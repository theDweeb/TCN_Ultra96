//#include <hw/tcn_block.hpp>

#include <hw/tcn.hpp>

extern "C" {
void tcn(
        dType_32fp input[__0_1_PADDING__INPUT_SIZE__],
        dType_32fp net_weights[__TOTAL_WEIGHT_LENGTH__],
        dType_32fp net_biases[__TOTAL_BIASES_LENGTH__],
        dType_32fp output[__SCRATCH_PAD_SIZE__])
{
#pragma HLS INTERFACE m_axi port=input offset=slave
#pragma HLS INTERFACE m_axi port=net_weights offset=slave
#pragma HLS INTERFACE m_axi port=net_biases offset=slave
#pragma HLS INTERFACE m_axi port=output offset=slave
#pragma HLS INTERFACE s_axilite port=return bundle=control

    //Allocate read_write buffers (4)
    dType_32fp read_output_1[__SCRATCH_PAD_SIZE__];
    dType_32fp read_output_2[__SCRATCH_PAD_SIZE__];
    dType_32fp read_output_3[__SCRATCH_PAD_SIZE__];
    dType_32fp read_output_4[__SCRATCH_PAD_SIZE__];

    //Allocate copy depthwise weights and biases (6)
    dType_32fp cp_dw_weights_1[__0_1_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_1[__0_1_1_DEPTHWISE_BIAS_LENGTH__];

    dType_32fp cp_dw_weights_2[__0_2_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_2[__0_2_1_DEPTHWISE_BIAS_LENGTH__];

    dType_32fp cp_dw_weights_3[__1_1_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_3[__1_1_1_DEPTHWISE_BIAS_LENGTH__];

    dType_32fp cp_dw_weights_4[__1_2_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_4[__1_2_1_DEPTHWISE_BIAS_LENGTH__];

    dType_32fp cp_dw_weights_5[__2_1_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_5[__2_1_1_DEPTHWISE_BIAS_LENGTH__];

    dType_32fp cp_dw_weights_6[__2_2_1_DEPTHWISE_WEIGHT_LENGTH__];
    dType_32fp cp_dw_bias_6[__2_2_1_DEPTHWISE_BIAS_LENGTH__];

    //Allocate depthwise output buffers (6)
    dType_32fp dw_output_1[__SCRATCH_PAD_SIZE__];
    dType_32fp dw_output_2[__SCRATCH_PAD_SIZE__];
    dType_32fp dw_output_3[__SCRATCH_PAD_SIZE__];
    dType_32fp dw_output_4[__SCRATCH_PAD_SIZE__];
    dType_32fp dw_output_5[__SCRATCH_PAD_SIZE__];
    dType_32fp dw_output_6[__SCRATCH_PAD_SIZE__];

    //Allocate copy pointwise weights and biases(7)
    dType_32fp cp_pw_weights_1[__0_1_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_1[__0_1_4_POINTWISE_BIAS_LENGTH__];

    dType_32fp cp_pw_weights_2[__0_2_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_2[__0_2_4_POINTWISE_BIAS_LENGTH__];

    dType_32fp cp_pw_weights_3[__0_1_UPSAMPLE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_3[__0_1_UPSAMPLE_BIAS_LENGTH__];
    
    dType_32fp cp_pw_weights_4[__1_1_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_4[__1_1_4_POINTWISE_BIAS_LENGTH__];

    dType_32fp cp_pw_weights_5[__1_2_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_5[__1_2_4_POINTWISE_BIAS_LENGTH__];

    dType_32fp cp_pw_weights_6[__2_1_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_6[__2_1_4_POINTWISE_BIAS_LENGTH__];

    dType_32fp cp_pw_weights_7[__2_2_4_POINTWISE_WEIGHT_LENGTH__];
    dType_32fp cp_pw_bias_7[__2_2_4_POINTWISE_BIAS_LENGTH__];

    //Allocate pointwise output buffers
    dType_32fp pw_output_1[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_2[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_3[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_4[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_5[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_6[__SCRATCH_PAD_SIZE__];
    dType_32fp pw_output_7[__SCRATCH_PAD_SIZE__];

    //Allocate vadd buffers (3)
    dType_32fp vadd_output_1[__SCRATCH_PAD_SIZE__];
    dType_32fp vadd_output_2[__SCRATCH_PAD_SIZE__];
    dType_32fp vadd_output_3[__SCRATCH_PAD_SIZE__];

    //Allocate linear buffers
    dType_32fp cp_linear_weights[__3_LINEAR__WEIGHT_SIZE__];
    dType_32fp cp_linear_bias[__3_LINEAR_BIAS_LENGTH__];
    dType_32fp linear_output[__SCRATCH_PAD_SIZE__];

    //Allocate copy point

//         dType_32fp local_buffer1[__SCRATCH_PAD_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_buffer1 cyclic factor 4

//         dType_32fp local_buffer2[__SCRATCH_PAD_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_buffer2 cyclic factor 4

//         dType_32fp local_res_path1[__SCRATCH_PAD_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_res_path1 cyclic factor 4

//         dType_32fp local_res_path2[__SCRATCH_PAD_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_res_path2 cyclic factor 4

//         dType_32fp local_weights[__MAX_WEIGHT_BUFFER_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_weights cyclic factor 4

//         dType_32fp local_biases[__MAX_BIAS_BUFFER_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_biases cyclic factor 4

//         dType_32fp local_linear_weights[__3_LINEAR__WEIGHT_SIZE__];
// //#pragma HLS ARRAY_PARTITION variable=local_linear_weights cyclic factor 4

            read_in2<__SCRATCH_PAD_SIZE__>(input, read_output_1, read_output_2,
            __0_1_PADDING__INPUT_CHAN__,
            __0_1_PADDING__INPUT_SIZE__,
            __0_1_PADDING__PADDING_SIZE__);
            // ++++++++++++++++++++++++++ BLOCK 1 ++++++++++++++++++++++++++++++++++++++++
            // ============================ FIRST DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_BIAS_OUT_CH_SIZE__>(
                net_weights,
                cp_dw_weights_1,
                net_biases,
                cp_dw_bias_1,
                __0_1_1_DEPTHWISE_WEIGHT_OFFSET__,
                __0_1_1_DEPTHWISE__WEIGHT_SIZE__,
                __0_1_1_DEPTHWISE_BIAS_OFFSET__,
                __0_1_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_DW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                read_output_1,
                cp_dw_weights_1,
                net_biases,
                dw_output_1,
                
                __0_1_1_DEPTHWISE__INPUT_CHAN__, __0_1_1_DEPTHWISE__INPUT_SIZE__,
                __0_1_1_DEPTHWISE__OUTPUT_CHAN__, __0_1_1_DEPTHWISE__OUTPUT_SIZE__,
                __0_1_1_DEPTHWISE__KERNEL_SIZE__, __0_1_1_DEPTHWISE__DILATION_SIZE__);


            // ============================ FIRST POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_1,
                net_biases,
                cp_pw_bias_1,
                __0_1_4_POINTWISE_WEIGHT_OFFSET__,
                __0_1_4_POINTWISE_WEIGHT_LENGTH__,
                __0_1_4_POINTWISE_BIAS_OFFSET__,
                __0_2_1_DEPTHWISE_BIAS_LENGTH__);

            pointwise_1<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_1,
                cp_pw_weights_2,
                cp_pw_bias_2,
                pw_output_1,
                
                __0_1_4_POINTWISE__INPUT_CHAN__, __0_1_4_POINTWISE__INPUT_SIZE__,
                __0_1_4_POINTWISE__OUTPUT_CHAN__, __0_1_4_POINTWISE__OUTPUT_SIZE__,
                __0_1_4_POINTWISE__KERNEL_SIZE__, __0_2_PADDING__PADDING_SIZE__);


            // ============================ SECOND DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_DW_BIAS_SIZE__>(
                net_weights,
                cp_dw_weights_2,
                net_biases,
                cp_dw_bias_2,
                __0_2_1_DEPTHWISE_WEIGHT_OFFSET__,
                __0_2_1_DEPTHWISE_WEIGHT_LENGTH__,
                __0_2_1_DEPTHWISE_BIAS_OFFSET__,
                __0_2_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_DW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                pw_output_1,
                cp_dw_weights_2,
                cp_dw_bias_2,
                dw_output_2,
                
                __0_2_1_DEPTHWISE__INPUT_CHAN__, __0_2_1_DEPTHWISE__INPUT_SIZE__,
                __0_2_1_DEPTHWISE__OUTPUT_CHAN__, __0_2_1_DEPTHWISE__OUTPUT_SIZE__,
                __0_2_1_DEPTHWISE__KERNEL_SIZE__, __0_2_1_DEPTHWISE__DILATION_SIZE__);


            //============================ SECOND POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_2,
                net_biases,
                cp_pw_bias_2,
                __0_2_4_POINTWISE_WEIGHT_OFFSET__,
                __0_2_4_POINTWISE_WEIGHT_LENGTH__,
                __0_2_4_POINTWISE_BIAS_OFFSET__,
                __0_2_4_POINTWISE_BIAS_LENGTH__);

            pointwise_2<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_2,
                cp_pw_weights_3,
                cp_pw_bias_3,
                pw_output_2,
                
                __0_2_4_POINTWISE__INPUT_CHAN__, __0_2_4_POINTWISE__INPUT_SIZE__,
                __0_2_4_POINTWISE__OUTPUT_CHAN__, __0_2_4_POINTWISE__OUTPUT_SIZE__,
                __0_2_4_POINTWISE__WEIGHT_SIZE__, __1_1_PADDING__PADDING_SIZE__
                );

            //==================== UPSAMPLE ==============================================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_3,
                net_biases,
                cp_pw_bias_3,
                __0_1_UPSAMPLE_WEIGHT_OFFSET__,
                __0_1_UPSAMPLE_WEIGHT_LENGTH__,
                __0_1_UPSAMPLE_BIAS_OFFSET__,
                __0_1_UPSAMPLE_BIAS_LENGTH__);

            pointwise_1<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                read_output_2,
                cp_pw_weights_4,
                cp_pw_bias_4,
                pw_output_3,
                
                __0_1_UPSAMPLE__INPUT_CHAN__, __0_1_UPSAMPLE__INPUT_SIZE__,
                __0_1_UPSAMPLE__OUTPUT_CHAN__, __0_1_UPSAMPLE__OUTPUT_SIZE__,
                __0_1_UPSAMPLE__KERNEL_SIZE__, __1_1_PADDING__PADDING_SIZE__
                );


            // //====================== ELEMENT WISE ADDITION ===============================================
            vadd<__SCRATCH_PAD_SIZE__>(pw_output_2, pw_output_3, vadd_output_1, __SCRATCH_PAD_SIZE__);
            
            

            // ++++++++++++++++++++++++++ BLOCK 2 ++++++++++++++++++++++++++++++++++++++++
            // Read in for vadd
            read_in1<__SCRATCH_PAD_SIZE__>(vadd_output_1, read_output_3, __2_1_PADDING__INPUT_CHAN__, __2_1_PADDING__INPUT_SIZE__ +__1_1_PADDING__PADDING_SIZE__ , 12);
            //============================ FIRST DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_DW_BIAS_SIZE__>(
                net_weights,
                cp_dw_weights_3,
                net_biases,
                cp_dw_bias_3,
                __1_1_1_DEPTHWISE_WEIGHT_OFFSET__,
                __1_1_1_DEPTHWISE_WEIGHT_LENGTH__,
                __1_1_1_DEPTHWISE_BIAS_OFFSET__,
                __1_1_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_DW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                vadd_output_1,
                cp_dw_weights_3,
                cp_dw_bias_3,
                dw_output_3,
                
                __1_1_1_DEPTHWISE__INPUT_CHAN__, __1_1_1_DEPTHWISE__INPUT_SIZE__,
                __1_1_1_DEPTHWISE__OUTPUT_CHAN__, __1_1_1_DEPTHWISE__OUTPUT_SIZE__,
                __1_1_1_DEPTHWISE__KERNEL_SIZE__, __1_1_1_DEPTHWISE__DILATION_SIZE__);


            // ============================ FIRST POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_4,
                net_biases,
                cp_pw_bias_4,
                __1_1_4_POINTWISE_WEIGHT_OFFSET__,
                __1_1_4_POINTWISE_WEIGHT_LENGTH__,
                __1_1_4_POINTWISE_BIAS_OFFSET__,
                __1_1_4_POINTWISE_BIAS_LENGTH__);

            pointwise_2<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_3,
                cp_pw_weights_4,
                cp_pw_bias_4,
                pw_output_4,
                
                __1_1_4_POINTWISE__INPUT_CHAN__, __1_1_4_POINTWISE__INPUT_SIZE__,
                __1_1_4_POINTWISE__OUTPUT_CHAN__, __1_1_4_POINTWISE__OUTPUT_SIZE__,
                __1_1_4_POINTWISE__KERNEL_SIZE__, __1_2_PADDING__PADDING_SIZE__);


            // ============================ SECOND DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_DW_BIAS_SIZE__>(
                net_weights,
                cp_dw_weights_4,
                net_biases,
                cp_dw_bias_4,
                __1_2_1_DEPTHWISE_WEIGHT_OFFSET__,
                __1_2_1_DEPTHWISE_WEIGHT_LENGTH__,
                __1_2_1_DEPTHWISE_BIAS_OFFSET__,
                __1_2_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_BIAS_OUT_CH_SIZE__, __SCRATCH_PAD_SIZE__>(
                pw_output_4,
                cp_dw_weights_4,
                cp_dw_bias_4,
                dw_output_3,
                
                __1_2_1_DEPTHWISE__INPUT_CHAN__, __1_2_1_DEPTHWISE__INPUT_SIZE__,
                __1_2_1_DEPTHWISE__OUTPUT_CHAN__, __1_2_1_DEPTHWISE__OUTPUT_SIZE__,
                __1_2_1_DEPTHWISE__KERNEL_SIZE__, __1_2_1_DEPTHWISE__DILATION_SIZE__);


            //============================ SECOND POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_5,
                net_biases,
                cp_pw_bias_5,
                __1_2_4_POINTWISE_WEIGHT_OFFSET__,
                __1_2_4_POINTWISE_WEIGHT_LENGTH__,
                __1_2_4_POINTWISE_BIAS_OFFSET__,
                __1_2_4_POINTWISE_BIAS_LENGTH__);

            pointwise_2<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_3,
                cp_pw_weights_5,
                cp_pw_bias_5,
                pw_output_4,
                
                __1_2_4_POINTWISE__INPUT_CHAN__, __1_2_4_POINTWISE__INPUT_SIZE__,
                __1_2_4_POINTWISE__OUTPUT_CHAN__, __1_2_4_POINTWISE__OUTPUT_SIZE__,
                __1_2_4_POINTWISE__KERNEL_SIZE__, __2_1_PADDING__PADDING_SIZE__
                );

   
            // //====================== ELEMENT WISE ADDITION ===============================================
            vadd<__SCRATCH_PAD_SIZE__>(pw_output_4, read_output_3, vadd_output_2, __SCRATCH_PAD_SIZE__);


            // ++++++++++++++++++++++++++ BLOCK 3 ++++++++++++++++++++++++++++++++++++++++
            // Read in for vadd
            read_in1<__SCRATCH_PAD_SIZE__>(vadd_output_2, read_output_4, __2_1_PADDING__INPUT_CHAN__, __2_1_PADDING__OUTPUT_SIZE__, 0);
            //============================ FIRST DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_DW_BIAS_SIZE__>(
                net_weights,
                cp_dw_weights_5,
                net_biases,
                cp_dw_bias_5,
                __2_1_1_DEPTHWISE_WEIGHT_OFFSET__,
                __2_1_1_DEPTHWISE_WEIGHT_LENGTH__,
                __2_1_1_DEPTHWISE_BIAS_OFFSET__,
                __2_1_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_DW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                vadd_output_2,
                cp_dw_weights_5,
                cp_dw_bias_5,
                dw_output_4,
                
                __2_1_1_DEPTHWISE__INPUT_CHAN__, __2_1_1_DEPTHWISE__INPUT_SIZE__,
                __2_1_1_DEPTHWISE__OUTPUT_CHAN__, __2_1_1_DEPTHWISE__OUTPUT_SIZE__,
                __2_1_1_DEPTHWISE__KERNEL_SIZE__, __2_1_1_DEPTHWISE__DILATION_SIZE__);


            // ============================ FIRST POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_6,
                net_biases,
                cp_pw_bias_6,
                __2_1_4_POINTWISE_WEIGHT_OFFSET__,
                __2_1_4_POINTWISE_WEIGHT_LENGTH__,
                __2_1_4_POINTWISE_BIAS_OFFSET__,
                __2_1_4_POINTWISE_BIAS_LENGTH__);

            pointwise_2<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_4,
                cp_pw_weights_6,
                cp_pw_bias_6,
                pw_output_5,
                
                __2_1_4_POINTWISE__INPUT_CHAN__, __2_1_4_POINTWISE__INPUT_SIZE__,
                __2_1_4_POINTWISE__OUTPUT_CHAN__, __2_1_4_POINTWISE__OUTPUT_SIZE__,
                __2_1_4_POINTWISE__KERNEL_SIZE__, __2_2_PADDING__PADDING_SIZE__);


            // ============================ SECOND DEPTHWISE CONV =========================
            copy_weights_dw<__MAX_WEIGHT_SIZE__,__MAX_DW_BIAS_SIZE__>(
                net_weights,
                cp_dw_weights_6,
                net_biases,
                cp_dw_bias_6,
                __2_2_1_DEPTHWISE_WEIGHT_OFFSET__,
                __2_2_1_DEPTHWISE_WEIGHT_LENGTH__,
                __2_2_1_DEPTHWISE_BIAS_OFFSET__,
                __2_2_1_DEPTHWISE_BIAS_LENGTH__
                );

            depthwise<__SCRATCH_PAD_SIZE__, __MAX_WEIGHT_SIZE__, __MAX_BIAS_OUT_CH_SIZE__, __SCRATCH_PAD_SIZE__>(
                pw_output_5,
                cp_dw_weights_6,
                cp_dw_bias_6,
                dw_output_5,
                
                __2_2_1_DEPTHWISE__INPUT_CHAN__, __2_2_1_DEPTHWISE__INPUT_SIZE__,
                __2_2_1_DEPTHWISE__OUTPUT_CHAN__, __2_2_1_DEPTHWISE__OUTPUT_SIZE__,
                __2_2_1_DEPTHWISE__KERNEL_SIZE__, __2_2_1_DEPTHWISE__DILATION_SIZE__);


            //============================ SECOND POINTWISE CONV =========================
            copy_weights_pw<__MAX_PW_WEIGHT_SIZE__,__MAX_PW_BIAS_SIZE__>(
                net_weights,
                cp_pw_weights_7,
                net_biases,
                cp_pw_bias_7,
                __2_2_4_POINTWISE_WEIGHT_OFFSET__,
                __2_2_4_POINTWISE_WEIGHT_LENGTH__,
                __2_2_4_POINTWISE_BIAS_OFFSET__,
                __2_2_4_POINTWISE_BIAS_LENGTH__);

            pointwise_2<__SCRATCH_PAD_SIZE__, __MAX_PW_WEIGHT_SIZE__, __MAX_PW_BIAS_SIZE__, __SCRATCH_PAD_SIZE__>(
                dw_output_5,
                cp_pw_weights_7,
                cp_pw_bias_7,
                pw_output_6,
                
                __2_2_4_POINTWISE__INPUT_CHAN__, __2_2_4_POINTWISE__INPUT_SIZE__,
                __2_2_4_POINTWISE__OUTPUT_CHAN__, __2_2_4_POINTWISE__OUTPUT_SIZE__,
                __2_2_4_POINTWISE__KERNEL_SIZE__, __2_2_PADDING__PADDING_SIZE__
                );

   
            // //====================== ELEMENT WISE ADDITION ===============================================
            vadd_unpad<__SCRATCH_PAD_SIZE__>(pw_output_6, read_output_4, vadd_output_3,
             __2_2_4_POINTWISE__INPUT_CHAN__,__2_2_1_DEPTHWISE__INPUT_SIZE__, __2_2_4_POINTWISE__INPUT_SIZE__);


            read_linear<315, 15>(vadd_output_3, pw_output_6, 15);
            copy_weights_dw<__3_LINEAR__WEIGHT_SIZE__,__MAX_BIAS_OUT_CH_SIZE__>(
                net_weights,
                cp_linear_weights,
                net_biases,
                cp_linear_bias,
                __3_LINEAR_WEIGHT_OFFSET__,
                __3_LINEAR__WEIGHT_SIZE__,
                __3_LINEAR_BIAS_OFFSET__,
                __MAX_BIAS_OUT_CH_SIZE__
                );

 
            linear<15, 104, 15*104, 104>(
                pw_output_6,
                cp_linear_weights,
                cp_linear_bias,
                linear_output,
                104,
                15
                );
            // //========================= WRITE BACK ========================================================
            write_out<__SCRATCH_PAD_SIZE__>(linear_output, output, 104);
        }
}