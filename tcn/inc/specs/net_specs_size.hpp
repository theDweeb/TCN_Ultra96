/*
Copyright (c) 2019, University of North Carolina at Charlotte All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
Authors: Reza Baharani    - Transformative Computer Systems Architecture Research (TeCSAR) at UNC Charlotte
Steven Furgurson - Transformative Computer Systems Architecture Research (TeCSAR) at UNC Charlotte
This file has been generated automatically. DO NOT MODIFY IT.
*/

#ifndef __NET_SPECS__HEADER__
#define __NET_SPECS__HEADER__


#define __0_1_UPSAMPLE__INPUT_CHAN__                1
#define __0_1_UPSAMPLE__INPUT_SIZE__                21
#define __0_1_UPSAMPLE__OUTPUT_CHAN__               15
#define __0_1_UPSAMPLE__OUTPUT_SIZE__               21
#define __0_1_UPSAMPLE__WEIGHT_SIZE__               15
#define __0_1_UPSAMPLE__KERNEL_SIZE__               1
#define __0_1_UPSAMPLE__DILATION_SIZE__             1
#define __0_1_PADDING__INPUT_CHAN__                 1
#define __0_1_PADDING__INPUT_SIZE__                 21
#define __0_1_PADDING__OUTPUT_CHAN__                1
#define __0_1_PADDING__OUTPUT_SIZE__                27
#define __0_1_PADDING__PADDING_SIZE__               6
#define __0_1_1_DEPTHWISE__INPUT_CHAN__             1
#define __0_1_1_DEPTHWISE__INPUT_SIZE__             27
#define __0_1_1_DEPTHWISE__OUTPUT_CHAN__            1
#define __0_1_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __0_1_1_DEPTHWISE__WEIGHT_SIZE__            7
#define __0_1_1_DEPTHWISE__KERNEL_SIZE__            7
#define __0_1_1_DEPTHWISE__DILATION_SIZE__          1
#define __0_1_4_POINTWISE__INPUT_CHAN__             1
#define __0_1_4_POINTWISE__INPUT_SIZE__             21
#define __0_1_4_POINTWISE__OUTPUT_CHAN__            15
#define __0_1_4_POINTWISE__OUTPUT_SIZE__            21
#define __0_1_4_POINTWISE__WEIGHT_SIZE__            15
#define __0_1_4_POINTWISE__KERNEL_SIZE__            1
#define __0_1_4_POINTWISE__DILATION_SIZE__          1
#define __0_2_PADDING__INPUT_CHAN__                 15
#define __0_2_PADDING__INPUT_SIZE__                 21
#define __0_2_PADDING__OUTPUT_CHAN__                15
#define __0_2_PADDING__OUTPUT_SIZE__                27
#define __0_2_PADDING__PADDING_SIZE__               6
#define __0_2_1_DEPTHWISE__INPUT_CHAN__             15
#define __0_2_1_DEPTHWISE__INPUT_SIZE__             27
#define __0_2_1_DEPTHWISE__OUTPUT_CHAN__            15
#define __0_2_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __0_2_1_DEPTHWISE__WEIGHT_SIZE__            105
#define __0_2_1_DEPTHWISE__KERNEL_SIZE__            7
#define __0_2_1_DEPTHWISE__DILATION_SIZE__          1
#define __0_2_4_POINTWISE__INPUT_CHAN__             15
#define __0_2_4_POINTWISE__INPUT_SIZE__             21
#define __0_2_4_POINTWISE__OUTPUT_CHAN__            15
#define __0_2_4_POINTWISE__OUTPUT_SIZE__            21
#define __0_2_4_POINTWISE__WEIGHT_SIZE__            225
#define __0_2_4_POINTWISE__KERNEL_SIZE__            1
#define __0_2_4_POINTWISE__DILATION_SIZE__          1
#define __1_1_PADDING__INPUT_CHAN__                 15
#define __1_1_PADDING__INPUT_SIZE__                 21
#define __1_1_PADDING__OUTPUT_CHAN__                15
#define __1_1_PADDING__OUTPUT_SIZE__                33
#define __1_1_PADDING__PADDING_SIZE__               12
#define __1_1_1_DEPTHWISE__INPUT_CHAN__             15
#define __1_1_1_DEPTHWISE__INPUT_SIZE__             33
#define __1_1_1_DEPTHWISE__OUTPUT_CHAN__            15
#define __1_1_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __1_1_1_DEPTHWISE__WEIGHT_SIZE__            195
#define __1_1_1_DEPTHWISE__KERNEL_SIZE__            7
#define __1_1_1_DEPTHWISE__DILATION_SIZE__          2
#define __1_1_4_POINTWISE__INPUT_CHAN__             15
#define __1_1_4_POINTWISE__INPUT_SIZE__             21
#define __1_1_4_POINTWISE__OUTPUT_CHAN__            15
#define __1_1_4_POINTWISE__OUTPUT_SIZE__            21
#define __1_1_4_POINTWISE__WEIGHT_SIZE__            225
#define __1_1_4_POINTWISE__KERNEL_SIZE__            1
#define __1_1_4_POINTWISE__DILATION_SIZE__          1
#define __1_2_PADDING__INPUT_CHAN__                 15
#define __1_2_PADDING__INPUT_SIZE__                 21
#define __1_2_PADDING__OUTPUT_CHAN__                15
#define __1_2_PADDING__OUTPUT_SIZE__                33
#define __1_2_PADDING__PADDING_SIZE__               12
#define __1_2_1_DEPTHWISE__INPUT_CHAN__             15
#define __1_2_1_DEPTHWISE__INPUT_SIZE__             33
#define __1_2_1_DEPTHWISE__OUTPUT_CHAN__            15
#define __1_2_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __1_2_1_DEPTHWISE__WEIGHT_SIZE__            195
#define __1_2_1_DEPTHWISE__KERNEL_SIZE__            7
#define __1_2_1_DEPTHWISE__DILATION_SIZE__          2
#define __1_2_4_POINTWISE__INPUT_CHAN__             15
#define __1_2_4_POINTWISE__INPUT_SIZE__             21
#define __1_2_4_POINTWISE__OUTPUT_CHAN__            15
#define __1_2_4_POINTWISE__OUTPUT_SIZE__            21
#define __1_2_4_POINTWISE__WEIGHT_SIZE__            225
#define __1_2_4_POINTWISE__KERNEL_SIZE__            1
#define __1_2_4_POINTWISE__DILATION_SIZE__          1
#define __2_1_PADDING__INPUT_CHAN__                 15
#define __2_1_PADDING__INPUT_SIZE__                 21
#define __2_1_PADDING__OUTPUT_CHAN__                15
#define __2_1_PADDING__OUTPUT_SIZE__                45
#define __2_1_PADDING__PADDING_SIZE__               24
#define __2_1_1_DEPTHWISE__INPUT_CHAN__             15
#define __2_1_1_DEPTHWISE__INPUT_SIZE__             45
#define __2_1_1_DEPTHWISE__OUTPUT_CHAN__            15
#define __2_1_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __2_1_1_DEPTHWISE__WEIGHT_SIZE__            375
#define __2_1_1_DEPTHWISE__KERNEL_SIZE__            7
#define __2_1_1_DEPTHWISE__DILATION_SIZE__          4
#define __2_1_4_POINTWISE__INPUT_CHAN__             15
#define __2_1_4_POINTWISE__INPUT_SIZE__             21
#define __2_1_4_POINTWISE__OUTPUT_CHAN__            15
#define __2_1_4_POINTWISE__OUTPUT_SIZE__            21
#define __2_1_4_POINTWISE__WEIGHT_SIZE__            225
#define __2_1_4_POINTWISE__KERNEL_SIZE__            1
#define __2_1_4_POINTWISE__DILATION_SIZE__          1
#define __2_2_PADDING__INPUT_CHAN__                 15
#define __2_2_PADDING__INPUT_SIZE__                 21
#define __2_2_PADDING__OUTPUT_CHAN__                15
#define __2_2_PADDING__OUTPUT_SIZE__                45
#define __2_2_PADDING__PADDING_SIZE__               24
#define __2_2_1_DEPTHWISE__INPUT_CHAN__             15
#define __2_2_1_DEPTHWISE__INPUT_SIZE__             45
#define __2_2_1_DEPTHWISE__OUTPUT_CHAN__            15
#define __2_2_1_DEPTHWISE__OUTPUT_SIZE__            21
#define __2_2_1_DEPTHWISE__WEIGHT_SIZE__            375
#define __2_2_1_DEPTHWISE__KERNEL_SIZE__            7
#define __2_2_1_DEPTHWISE__DILATION_SIZE__          4
#define __2_2_4_POINTWISE__INPUT_CHAN__             15
#define __2_2_4_POINTWISE__INPUT_SIZE__             21
#define __2_2_4_POINTWISE__OUTPUT_CHAN__            15
#define __2_2_4_POINTWISE__OUTPUT_SIZE__            21
#define __2_2_4_POINTWISE__WEIGHT_SIZE__            225
#define __2_2_4_POINTWISE__KERNEL_SIZE__            1
#define __2_2_4_POINTWISE__DILATION_SIZE__          1
#define __3_LINEAR__INPUT_CHAN__                    1
#define __3_LINEAR__INPUT_SIZE__                    15
#define __3_LINEAR__OUTPUT_CHAN__                   1
#define __3_LINEAR__OUTPUT_SIZE__                   104
#define __3_LINEAR__WEIGHT_SIZE__                   1560
#define __MAX_INPUT_CH__                            15
#define __MAX_INPUT_SIZE__                          15
#define __MAX_OUT_CH__                              45
#define __MAX_OUT_SIZE__                            45
#define __MAX_WEIGHT_SIZE__                         375
#define __MAX_PW_WEIGHT_SIZE__                      225
#define __MAX_BIAS_OUT_CH_SIZE__                    104
#define __LINEAR_ROW_SIZE__                         1
#define __LINEAR_DEPTH_SIZE__                       15
#define __DW_CONV_MAX_INPUT_CHAN__                  15
#define __DW_CONV_MAX_INPUT_SIZE__                  21
#define __DW_CONV_MAX_OUTPUT_CHANNEL__              15
#define __DW_CONV_MAX_OUTPUT_SIZE__                 21
#define __PW_CONV_MAX_INPUT_CHAN__                  15
#define __PW_CONV_MAX_INPUT_SIZE__                  45
#define __MAX_PW_BIAS_SIZE__                        15
#define __MAX_DW_BIAS_SIZE__                        15
#define __PW_CONV_MAX_OUTPUT_SIZE                   21
#define __DEBUG_OUTPUT_SIZE__                       315
#endif
