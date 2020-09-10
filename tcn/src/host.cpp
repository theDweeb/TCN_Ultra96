
#include <stdlib.h>
#include <vector>
#include <utils/npy.hpp>
#include <specs/typedef_fixedpt.hpp>
#include <hw/tcn.hpp>

#ifdef __HW__
#include "utils/sds_utils.h"
#include "utils/xcl2.hpp"

#else
#include <iostream>

#endif

int main(int argc, char** argv)
{

    // Allocate Memory in Host Memory
    std::cout << "-> Allocating memory..." << std::endl;

    size_t sequence_size =  sizeof(dType_32fp) * __0_1_PADDING__INPUT_SIZE__;
    size_t weight_size   =  sizeof(dType_32fp) * __TOTAL_WEIGHT_LENGTH__;
    size_t bias_size     =  sizeof(dType_32fp) * __TOTAL_BIASES_LENGTH__;
    size_t output_size   =  sizeof(dType_32fp) * __SEQUENCE_OUTPUT_LENGTH__;

    dType_32fp *sequence =  (dType_32fp *)malloc(sequence_size);
    dType_32fp *weights  =  (dType_32fp *)malloc(weight_size);
    dType_32fp *biases   =  (dType_32fp *)malloc(bias_size);
    dType_32fp *output   =  (dType_32fp *)malloc(output_size);

    //Stores results for plotting
    std::vector<dType_32fp> plot;
    
    // Numpy network parameter arrays
    std::cout << "-> Reading network parameters..." << std::endl;

    std::vector<dType_32fp>     sequence_numpy;
    std::vector<unsigned long>  sequence_numpy_size;
    std::vector<dType_32fp>     weight_numpy;
    std::vector<unsigned long>  weight_numpy_size;
    std::vector<dType_32fp>     bias_numpy;
    std::vector<unsigned long>  bias_numpy_size;
    std::vector<dType_32fp>     output_numpy;
    std::vector<unsigned long>  output_numpy_size;

#ifdef __HW__
    std::cout << "-> Reading Input..." << std::endl;
    npy::LoadArrayFromNumpy("/home/xilinx/jupyter_notebooks/weights/dev0_input.npy", sequence_numpy_size, sequence_numpy);

    std::cout << "-> Reading Weights..." << std::endl;
    npy::LoadArrayFromNumpy("/home/xilinx/jupyter_notebooks/weights/weights.npy", weight_numpy_size, weight_numpy);

    std::cout << "-> Reading Biases..." << std::endl;
    npy::LoadArrayFromNumpy("/home/xilinx/jupyter_notebooks/weights/biases.npy", bias_numpy_size, bias_numpy);

#else
    std::cout << "-> Reading Input..." << std::endl;
    npy::LoadArrayFromNumpy("/mnt/500GB/home/steve/TCN/network_parameters/dev0_input.npy", sequence_numpy_size, sequence_numpy);

    std::cout << "-> Reading Weights..." << std::endl;
    npy::LoadArrayFromNumpy("/mnt/500GB/home/steve/TCN/network_parameters/weights.npy", weight_numpy_size, weight_numpy);
    
    std::cout << "-> Reading Biases..." << std::endl;
    npy::LoadArrayFromNumpy("/mnt/500GB/home/steve/TCN/network_parameters/biases.npy", bias_numpy_size, bias_numpy);

    std::cout << "-> Reading Output..." << std::endl;
    npy::LoadArrayFromNumpy("/mnt/500GB/home/steve/TCN/network_parameters/output.npy", output_numpy_size, output_numpy);
	
#endif

    int number_of_sequences = sequence_numpy_size[0] / __0_1_PADDING__INPUT_SIZE__;

    // Mean and STD of input data
    float mean = 0.010460076990023664;
    float std = 0.012938735335215161;

    // Read network weights and biases from the numpy arrays
    for (int i = 0; i < (__TOTAL_WEIGHT_LENGTH__); i++)
    {
        weights[i] = weight_numpy[i];
    }

    for (int i = 0; i < __TOTAL_BIASES_LENGTH__; i++)
    {
        biases[i] = bias_numpy[i];
    }


#ifdef __HW__
    std::cout << "Getting Xilinx device\n";
    std::vector<cl::Device> devices = xcl::get_xil_devices();
    cl::Device device = devices[0];

    cl::Context context(device);
    cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE);
    std::string device_name = device.getInfo<CL_DEVICE_NAME>(); 
    std::cout << "Device found: " << device_name << std::endl;

    //Create Program and Kernel
    std::cout << "Creating program and kernel\n";
    std::string binaryFile = xcl::find_binary_file(device_name,"tcn_block");
    cl::Program::Binaries bins = xcl::import_binary_file(binaryFile);
    devices.resize(1);
    cl::Program program(context, devices, bins);
    cl::Kernel tcn_block(program,"tcn_block");
 
    std::cout << "Allocating Buffer in Global Memory\n";
    cl::Buffer _input(context, CL_MEM_READ_ONLY, 
            sequence_size);
    cl::Buffer _net_weights (context, CL_MEM_READ_ONLY, 
            weight_size);
    cl::Buffer _net_biases (context, CL_MEM_READ_ONLY, 
            bias_size);
    cl::Buffer _output(context, CL_MEM_WRITE_ONLY, 
            output_size);

    std::cout << "Setting kernel arguments\n";
    int nargs = 0;
    tcn_block.setArg(nargs++,_input);
    tcn_block.setArg(nargs++,_net_weights);
    tcn_block.setArg(nargs++,_net_biases);
    tcn_block.setArg(nargs++,_output);
 
 #endif

    for(int i = 0; i < number_of_sequences; i++)
    {
        for(int j = 0; j < __0_1_PADDING__INPUT_SIZE__; j++)
        {

            sequence[j] = sequence_numpy[(i * __0_1_PADDING__INPUT_SIZE__) + j];
            std::cout << sequence[j] << ", ";
            plot.push_back((sequence[j]*std) + mean);
        }
        std::cout << std::endl;

#ifdef __HW__
        //Allocate Buffer in Global Memory
        //Copying input data to Device buffer from host memory
        std::cout << "Copying input data into device buffer from host memory\n";
        q.enqueueWriteBuffer(_input, CL_TRUE, 0, sequence_size, sequence_0);
        q.enqueueWriteBuffer(_net_weights, CL_TRUE, 0, weight_size, weights);
        q.enqueueWriteBuffer(_net_biases, CL_TRUE, 0, bias_size, biases);

        //Launch the Kernel
        std::cout << "Launching kernel\n";
        q.enqueueTask(tcn_block);

        //Copying Device result data to Host memory
        std::cout << "Copying device result back to host\n";
        q.enqueueReadBuffer(_output, CL_TRUE, 0, output_size, output);

#else
        std::cout << "\n-> Launching TCN from CPU...\n";
        tcn(sequence, weights, biases, output);

#endif

        // Print results
        std::cout << "\nResults for sequence [" << i+1 << "/" << number_of_sequences << "]" << std::endl;
        const long unsigned out_shape[1] = {__3_LINEAR__OUTPUT_SIZE__};
        for(int i = 0; i < out_shape[0]; i++)
        {   
#ifdef __VERBOSE__
            if(i % 10 == 0 && i != 0)
            {
                std::cout << std::endl;
            }
            std::cout << (output[i]*std) + mean << ", ";
#endif
            plot.push_back((output[i]*std) + mean);
        }
    }

#ifdef __HW__
    q.finish()

#endif

    std::cout << "\n\nFinished!\n";
    std::cout << "\nSaving output.npy\n";
    std::string filename = "./outputs/output.npy";
    const long unsigned int dim[1] = {(unsigned long)10494};
    npy::SaveArrayAsNumpy("./outputs/output.npy", false, 1, dim, plot);

    // Free allocations
    free(sequence);
    free(weights);
    free(biases);
    free(output);

    return 0;
}
