#ifndef __TCN_HEADER__
#define __TCN_HEADER__

#include <specs/buf_size.hpp>
#include <specs/typedef_fixedpt.hpp>
#include <specs/net_specs_size.hpp>
#include <specs/indx_length.hpp>
#include <specs/net_params_offset.hpp>
#include <hw/copy_weights.hpp>
#include <hw/depthwise.hpp>
#include <hw/linear.hpp>
#include <hw/pointwise.hpp>
#include <hw/read_write.hpp>
#include <hw/vadd.hpp>

extern "C" {
void tcn(
        dType_32fp local_buffer1[__SCRATCH_PAD_SIZE__],
        dType_32fp net_weights[__MAX_WEIGHT_SIZE__],
        dType_32fp net_biases[__MAX_BIAS_OUT_CH_SIZE__],
        dType_32fp local_buffer2[__SCRATCH_PAD_SIZE__]);
}
#endif