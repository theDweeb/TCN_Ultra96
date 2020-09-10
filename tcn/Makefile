RM = rm -f
RMDIR = rm -rf

#VITIS_PLATFORM := /home/yunq/Pynq-Python/PYNQ-derivative-overlays/vitis_platform/ZCU104/platforms/ultra/ultra.xpfm
#PORT := HP0
VPP := $(XILINX_VITIS)/bin/v++
MPSOC_CXX := g++
VPP_COMMON_OPTS += -t hw --platform ${VITIS_PLATFORM} --save-temps
VPP_COMMON_OPTS += -w -I$(CURDIR)/inc/
#VPP_LINK_OPTS := --config connectivity-$(PORT).cfg
VPP_LINK_OPTS := --config design.cfg
DEBUG := __SW__
ifdef verbose
DEBUG += -D__VERBOSE__
endif

#SOURCES = $(wildcard ${SOURCEDIR}/*.cpp)
#--profile_kernel data:all:all:all

KERN_NAME = tcn

all: xclbin elf

xclbin: bin/tcn.xclbin

elf: tcn.elf

.PHONY: all clean bin

sw:
	g++ ./src/host.cpp ./src/hw/tcn.cpp -I$(CURDIR)/inc/ -I/tools/Xilinx/Vivado/2019.2/include/ -o host -D$(DEBUG)


bin/tcn.xo: src/hw/tcn.cpp
	@mkdir -p $(@D)
	-@$(RM) $@
	$(VPP) $(VPP_COMMON_OPTS) -c -k ${KERN_NAME} -I'$(<D)' -o "$@" "$<"

bin/tcn.xclbin: bin/tcn.xo
	$(VPP) $(VPP_COMMON_OPTS)  -l -o "$@" $(+) $(VPP_LINK_OPTS)

%.o: src/%.cpp
	${MPSOC_CXX} -std=c++11 -I$(CURDIR)/inc/ -I$(CURDIR)../include/ -D__HW__ -DDSA64 -c $^ -I/opt/xilinx/xrt/include -o $@

tcn.elf: host.o xcl2.o
	${MPSOC_CXX} $^ -L/usr/lib  -lxilinxopencl -lxrt_core -o $@

clean:
	${RMDIR} *.o *.elf *.log .Xil
	${RMDIR} bin/ _x/

