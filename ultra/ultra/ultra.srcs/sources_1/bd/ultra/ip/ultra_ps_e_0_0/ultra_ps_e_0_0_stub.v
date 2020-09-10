// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.2.1 (lin64) Build 2729669 Thu Dec  5 04:48:12 MST 2019
// Date        : Wed Sep  9 15:09:53 2020
// Host        : RezaLabPC running 64-bit Ubuntu 18.04.5 LTS
// Command     : write_verilog -force -mode synth_stub
//               /mnt/500GB/home/steve/TCN/ultra/ultra/ultra.srcs/sources_1/bd/ultra/ip/ultra_ps_e_0_0/ultra_ps_e_0_0_stub.v
// Design      : ultra_ps_e_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sbva484-1-i
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "zynq_ultra_ps_e_v3_3_1_zynq_ultra_ps_e,Vivado 2019.2.1" *)
module ultra_ps_e_0_0(emio_gpio_i, emio_gpio_o, emio_gpio_t, 
  emio_uart0_ctsn, emio_uart0_rtsn, emio_uart0_dsrn, emio_uart0_dcdn, emio_uart0_rin, 
  emio_uart0_dtrn, emio_uart1_txd, emio_uart1_rxd, pl_ps_irq0, pl_ps_irq1, pl_resetn0, pl_clk0, 
  pl_clk1, pl_clk2, pl_clk3)
/* synthesis syn_black_box black_box_pad_pin="emio_gpio_i[94:0],emio_gpio_o[94:0],emio_gpio_t[94:0],emio_uart0_ctsn,emio_uart0_rtsn,emio_uart0_dsrn,emio_uart0_dcdn,emio_uart0_rin,emio_uart0_dtrn,emio_uart1_txd,emio_uart1_rxd,pl_ps_irq0[0:0],pl_ps_irq1[0:0],pl_resetn0,pl_clk0,pl_clk1,pl_clk2,pl_clk3" */;
  input [94:0]emio_gpio_i;
  output [94:0]emio_gpio_o;
  output [94:0]emio_gpio_t;
  input emio_uart0_ctsn;
  output emio_uart0_rtsn;
  input emio_uart0_dsrn;
  input emio_uart0_dcdn;
  input emio_uart0_rin;
  output emio_uart0_dtrn;
  output emio_uart1_txd;
  input emio_uart1_rxd;
  input [0:0]pl_ps_irq0;
  input [0:0]pl_ps_irq1;
  output pl_resetn0;
  output pl_clk0;
  output pl_clk1;
  output pl_clk2;
  output pl_clk3;
endmodule
