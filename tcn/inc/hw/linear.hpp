#ifndef __LINEAR__HEADER__
#define __LINEAR__HEADER__

#include <specs/typedef_fixedpt.hpp>

template<unsigned MAX_INPUT_SIZE, unsigned MAX_OUTPUT_SIZE,
         unsigned MAX_WEIGHT_SIZE, unsigned MAX_BIAS_SIZE>
void linear(dType_32fp input[MAX_INPUT_SIZE],
            dType_32fp weights[MAX_WEIGHT_SIZE],
            dType_32fp biases[MAX_BIAS_SIZE],
            dType_32fp output[MAX_OUTPUT_SIZE],
            dType_Reg row, dType_Reg col)
{
    dType_32fp sum = 0;

    for(dType_Reg i = 0; i < row; i++)
    {
        for(dType_Reg j = 0; j < col; j++)
        {
            sum += input[j] * weights[(i * col) + j];
            //std::cout << "input[" << j << "] = " << input[j] << ",  weights[" << (i * col) + j << "] = " << weights[(i * col) + j] <<  ",   bias[" << i << "] = " << biases[i] << ",  sum = " << sum << std::endl;
        }

        sum += biases[i];

        if(sum < 0)
        {
            sum = 0.0;
        }
        output[i] = sum;
        //std::cout << "-> output[" << i << "] = " << output[i] << std::endl << std::endl;
        sum = 0.0;
    }
}


#endif