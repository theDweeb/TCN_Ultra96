#ifndef __READ_WRITE_HEADER__
#define __READ_WRITE_HEADER__

#include <specs/typedef_fixedpt.hpp>
#include <iostream>


template<unsigned MAX_INPUT_READ> 
void read_in1(
                  dType_32fp input[MAX_INPUT_READ],
                  dType_32fp output1[MAX_INPUT_READ],
                  dType_Reg in_chan,
                  dType_Reg in_size,
                  dType_Reg padding)
{   
    //std::cout << "in channel: " << in_chan << ", in size: " << in_size << ", padding: " << padding << std::endl;
    dType_Reg o_idx = 0;
    for(dType_Reg i = 0; i < in_chan; i++)
    {
        for(dType_Reg j = 0; j < (in_size + padding); j++)
        {   
            dType_Reg i_idx = (i * (in_size + padding) + j);
            
            if(j >= in_size)
            {
                output1[i_idx] = 0;
                //std::cout << "!";
            }
            else
            {
                output1[i_idx] = input[o_idx];
                o_idx++;
            }
            //std::cout << "input[" << i_idx << "] = " << output1[i_idx] << ", ";
        }
        //std::cout << std::endl;
    }
    //std::cout << std::endl;
}


template<unsigned MAX_INPUT_READ> 
void read_in2(
                  dType_32fp input[MAX_INPUT_READ],
                  dType_32fp output1[MAX_INPUT_READ],
                  dType_32fp output2[MAX_INPUT_READ],
                  dType_Reg in_chan,
                  dType_Reg in_size,
                  dType_Reg padding)
{
    for(dType_Reg i = 0; i < in_chan; i++)
    {
        for(dType_Reg j = 0; j < (in_size + padding); j++)
        {   
            dType_Reg idx = (i * (in_size + padding) + j);
            if(j >= in_size)
            {
                output1[idx] = 0;
                output2[idx] = 0;
            }
            else
            {
                output1[idx] = input[idx];
                output2[idx] = input[idx];
            }
        }
    }
}


template<unsigned MAX_INPUT_READ, unsigned MAX_OUTPUT_READ> 
void read_linear(
                  dType_32fp input[MAX_INPUT_READ],
                  dType_32fp output[MAX_OUTPUT_READ],
                  dType_Reg in_chan)
{   
    //std::cout << "in channel: " << in_chan << ", in size: " << in_size << ", padding: " << padding << std::endl;
    dType_Reg o_idx = 20;
    for(dType_Reg i = 0; i < in_chan; i++)
    {
        output[i] = input[o_idx];
        //std::cout << "linear output[" << i << "] = " << output[i] << std::endl;
        o_idx += 21;
    }

}


template<unsigned MAX_OUTPUT_READ> 
void write_out(
                  dType_32fp input[MAX_OUTPUT_READ],
                  dType_32fp output[MAX_OUTPUT_READ],
                  dType_Reg length)
{
    for(dType_Reg i = 0; i < length; i++)
    {
        output[i] = input[i];
    }
}




#endif