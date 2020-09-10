#ifndef __DEPTHWISE__HEADER__
#define __DEPTHWISE__HEADER__

// #include "depthwise_operation.hpp"
#include <iostream>
#include <specs/typedef_fixedpt.hpp>

template<unsigned MAX_INPUT_SIZE, unsigned MAX_OUTPUT_SIZE,
         unsigned MAX_WEIGHT_SIZE, unsigned MAX_BIAS_SIZE>
void depthwise(
    dType_32fp input[MAX_INPUT_SIZE],
    dType_32fp weights[MAX_WEIGHT_SIZE],
    dType_32fp biases[MAX_BIAS_SIZE],
    dType_32fp output[MAX_OUTPUT_SIZE],

    dType_Reg ip_chan, dType_Reg ip_size,
    dType_Reg op_chan, dType_Reg op_size,
    dType_Reg ksize, dType_Reg dilation
)
{   
    ksize = ((dilation - 1) * (ksize - 1)) + ksize;
    //std::cout << "==========+++++DEPTHWISE+++++==========\n\n";
    dType_32fp tmp = 0.0;
    dType_Reg cvt = 0;
    dType_Reg ptr = 0;
    for(int oc = 0; oc < op_chan; oc++)
    {
        for(int os = 0; os < op_size; os++)
        {
            dType_Reg b_idx = oc;
            dType_Reg o_idx = (oc * op_size) + os;
            for(int ks = 0; ks < ksize; ks++)
            {   
                
                dType_Reg w_idx = (oc * ksize) + ks;
                dType_Reg i_idx = (oc * ip_size) + (os + ks);
                tmp += input[i_idx] * weights[w_idx];
                //std::cout << "input idx = " << i_idx << ", weight idx = " << w_idx << ", bias idx = " << b_idx <<  ", output idx = " << o_idx <<  std::endl;
                //std::cout << input[i_idx] << ",      " << weights[w_idx] << ",      " << biases[b_idx] << ",        == " << tmp << std::endl;
            }
            tmp += biases[b_idx];

            if(tmp < 0)
            {
                tmp = 0.0;
            }
            if(tmp > 6)
            {
                tmp = 6.0;
            }

            output[o_idx] = dType_32fp(tmp);
            //std::cout << output[(oc * op_size) + os] << ", ";
            //ptr++;
            tmp = 0;
            //std::cout << std::endl;
        }
       // std::cout << std::endl;
    }
    //std::cout << "DW1 result" << std::endl;
}
#endif