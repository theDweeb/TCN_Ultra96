#ifndef __COPY_WEIGHTS_HEADER__
#define __COPY_WEIGHTS_HEADER__

#include <specs/typedef_fixedpt.hpp>

template<unsigned MAX_WEIGHT_LENGTH, unsigned MAX_BIAS_LENGTH> 
void copy_weights_pw(
                  dType_32fp *weights,
                  dType_32fp weights_output[MAX_WEIGHT_LENGTH],
                  dType_32fp *biases,
                  dType_32fp bias_output[MAX_BIAS_LENGTH],
                  dType_Reg weight_offset,
                  dType_Reg weight_length,
                  dType_Reg bias_offset,
                  dType_Reg bias_length)
{
    //std::cout << "\n\nWEIGHTS PW\n";
    //std::cout << "weight offset = " << weight_offset << " | weight length = " << weight_length << "\n\n";
    for(dType_Reg i = 0; i < weight_length; i++)
    {
        weights_output[i] = weights[weight_offset + i];
        //std::cout << weights_output[i] << ", ";
    }
    //std::cout << "\n\nBIASES PW\n";
    //std::cout << "bias_offset = " << bias_offset << " | bias_length = " << bias_length << "\n\n";
    for(dType_Reg i = 0; i < bias_length; i++)
    {
        bias_output[i] = biases[bias_offset + i];
        //std::cout << bias_output[i] << ", ";
    }
    //std::cout << std::endl << std::endl;
}

template<unsigned MAX_WEIGHT_LENGTH, unsigned MAX_BIAS_LENGTH>
void copy_weights_dw(dType_32fp *weights,
                  dType_32fp weights_output[MAX_WEIGHT_LENGTH],
                  dType_32fp *biases,
                  dType_32fp bias_output[MAX_BIAS_LENGTH],
                  dType_Reg weight_offset,
                  dType_Reg weight_length,
                  dType_Reg bias_offset,
                  dType_Reg bias_length)
{
    //std::cout << "\n\nWEIGHTS\n";
    //std::cout << "weight offset = " << weight_offset << " | weight length = " << weight_length << "\n\n";

    for(dType_Reg i = 0; i < weight_length; i++)
    {   
        weights_output[i] = weights[weight_offset + i];
        //std::cout << weights_output[i] << ", ";
    }
    //std::cout << "\n\nBIASES DW\n";
    //std::cout << "bias_offset = " << bias_offset << " | bias_length = " << bias_length << "\n\n";
    for(dType_Reg i = 0; i < bias_length; i++)
    {
        bias_output[i] = biases[bias_offset + i];
    }

    //std::cout << std::endl << std::endl;

}


#endif