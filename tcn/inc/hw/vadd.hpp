#ifndef __VADD__HEADER__
#define __VADD__HEADER__

#include <specs/typedef_fixedpt.hpp>


template<unsigned MAX_BUFFER_SIZE> 
void vadd(
    dType_32fp input1[MAX_BUFFER_SIZE],
    dType_32fp input2[MAX_BUFFER_SIZE],
    dType_32fp output[MAX_BUFFER_SIZE],
    dType_Reg output_size)
{
    for(dType_Reg i = 0; i < output_size; i++)
    {
        output[i] = input1[i] + input2[i];
        //std::cout << "input1[" << i << "] = " << input1[i] << "  |   input2[" << i << "] = " << input2[i] << "  |   sum = " << output[i] << std::endl;
    }
}

template<unsigned MAX_BUFFER_SIZE> 
void vadd_unpad(
    dType_32fp input1[MAX_BUFFER_SIZE],
    dType_32fp input2[MAX_BUFFER_SIZE],
    dType_32fp output[MAX_BUFFER_SIZE],
    dType_Reg channel,
    dType_Reg in_size,
    dType_Reg out_size)
{
    dType_Reg count = 0;
    for(dType_Reg i = 0; i < channel; i++)
    {
        for(dType_Reg j = 0; j < out_size; j++)
        {   
            dType_Reg o_idx = (i * out_size) + j;
            dType_Reg i_idx = (i * in_size) + j;
            output[o_idx] = input1[i_idx] + input2[i_idx];
            //std::cout << "input1[" << i_idx << "] = " << input1[i_idx] << ", input2[" << i_idx << "] = " << input2[i_idx] << ", output[" << o_idx << "] = " << output[o_idx] << std::endl;
        }
        //std::cout << std::endl;
    }
}

#endif