#ifndef __POINTWISE__HEADER__
#define __POINTWISE__HEADER__

#include <specs/typedef_fixedpt.hpp>

template<unsigned MAX_INPUT_SIZE, unsigned MAX_OUTPUT_SIZE,
         unsigned MAX_WEIGHT_SIZE, unsigned MAX_BIAS_SIZE>
void pointwise_1(
    dType_32fp input[MAX_INPUT_SIZE],
    dType_32fp weights[MAX_WEIGHT_SIZE],
    dType_32fp biases[MAX_BIAS_SIZE],
    dType_32fp output[MAX_OUTPUT_SIZE],

    dType_Reg ip_chan, dType_Reg ip_size,
    dType_Reg op_chan, dType_Reg op_size,
    dType_Reg ksize,
    dType_Reg padding
)
{   
    dType_32fp tmp  = 0.0;

    //std::cout << "=============================POINTWISE 1=============================\n\n";
    for(dType_Reg oc = 0; oc < op_chan; oc++)
    {
        for(dType_Reg os = 0; os < op_size + padding; os++)
        {   int o_idx = 0;
            int b_idx = 0;

            for(dType_Reg ic = 0; ic < ip_chan; ic++)
            {
                o_idx = (oc * (op_size + padding)) + os;
                int i_idx = (ic * ip_size) + os;
                int w_idx = (ic * op_chan) + oc;
                b_idx = oc;
                //std::cout << "input idx = " << i_idx << ", weight idx = " << w_idx << ", bias idx = " << b_idx <<  ", output idx = " << o_idx <<  std::endl;
                //std::cout << "input = " << input[i_idx] << ", weight = " << weights[w_idx] << ", bias = " << biases[b_idx] << std::endl;
                tmp += input[i_idx] * weights[w_idx];
            }
            tmp += biases[b_idx];

            

            if((tmp < 0 || os >= op_size))
            {
                tmp = 0.0;
            }
            if(tmp > 6)
            {
                tmp = 6.0;
            }
            output[o_idx] = dType_32fp(tmp);
            //std::cout << "output = " << output[o_idx] << std::endl;
            tmp = 0;
        }
    }
}
template<unsigned MAX_INPUT_SIZE, unsigned MAX_OUTPUT_SIZE,
         unsigned MAX_WEIGHT_SIZE, unsigned MAX_BIAS_SIZE>
void pointwise_2(
    dType_32fp input[MAX_INPUT_SIZE],
    dType_32fp weights[MAX_WEIGHT_SIZE],
    dType_32fp biases[MAX_BIAS_SIZE],
    dType_32fp output[MAX_OUTPUT_SIZE],

    dType_Reg ip_chan, dType_Reg ip_size,
    dType_Reg op_chan, dType_Reg op_size,
    dType_Reg ksize,
    dType_Reg padding
)
{   
    dType_32fp tmp = 0.0;
    //std::cout << "\n\n=============================POINTWISE 2=============================\n\n";
    for(dType_Reg oc = 0; oc < op_chan; oc++)
    {
        for(dType_Reg os = 0; os < op_size + padding; os++)
        {   int o_idx = 0;
            int b_idx = 0;
            for(dType_Reg ic = 0; ic < ip_chan; ic++)
            {
                o_idx = (oc * (op_size + padding)) + os;
                int i_idx = (ic * ip_size) + os;
                int w_idx = (oc * op_chan) + ic;
                b_idx = oc;
                //std::cout << "input idx = " << i_idx << ", weight idx = " << w_idx << ", bias idx = " << b_idx <<  ", output idx = " << o_idx <<  std::endl;
                //std::cout << "input = " << input[i_idx] << ", weight = " << weights[w_idx] << ", bias = " << biases[b_idx] << std::endl;
                tmp += input[i_idx] * weights[w_idx];
            }
            tmp += biases[b_idx];
            
            if(tmp < 0 || os >= op_size)
            {
                tmp = 0;
            }
            output[o_idx] = tmp;
            //std::cout << "output = " << output[o_idx] << std::endl;
            tmp = 0;
            //tmp += biases[b_idx];

            // if(tmp < 0 || os >= op_size)
            // {
            //     tmp = 0;
            // }
            // output[o_idx] = tmp;
            // tmp = 0;
            
        }
    }
}

#endif