XSA_PATH := ultra/ultra.xsa
BOARD := Ultra96

OVERLAY := $(shell basename $(XSA_PATH) | cut -d "." -f 1)
PORT := $(eval P := $$(shell platforminfo -p $(BOARD)/platforms/$(OVERLAY)/$(OVERLAY).xpfm | grep -m1 "Bus SP Tag: HP" | rev | cut -d " " -f 1 | rev ))$(P)
TEST_DIR := $(CURDIR)/test
TCN_DIR := $(CURDIR)/tcn

Zynq7000 := Pynq-Z1 Pynq-Z2
ZynqUltrascale := Ultra96 ZCU104 ZCU111
ifneq ($(filter $(BOARD),$(Zynq7000)),)
PROC = ps7_cortexa9
endif
ifneq ($(filter $(BOARD),$(ZynqUltrascale)),)
PROC = psu_cortexa53
endif
ifndef PROC
$(error Please set BOARD to one of the supported boards)
endif

all: clean help platform

help:
	@echo "usage: make [target]"
	@echo
	@echo "options:"
	@echo "--------"
	@echo "all:        clean, show help message, and make the platform."
	@echo "help:       show help message."
	@echo "platform:   make the Vitis platform."
	@echo "test:       take some time to do a test based on the platform."
	@echo "cleantest:  clean the test folder."
	@echo "clean:      clean test and Vitis platform for a given overlay."
	@echo
	@echo "arguments:"
	@echo "----------"
	@echo "XSA_PATH:   path to the xsa file"
	@echo "            e.g., /home/usr/boards/ZCU104/ultra/ultra.xsa"
	@echo "BOARD:      name of the board"
	@echo "            e.g., ZCU104, Ultra96, ZCU111"
	@echo
	@echo "current configuration:"
	@echo "----------------------"
	@echo "make XSA_PATH=$(XSA_PATH)"
	@echo "     BOARD=$(BOARD)"
	@echo

platform:
	mkdir -p ./$(BOARD)/platforms
	xsct -sdx build_pfm.tcl $(XSA_PATH) $(OVERLAY) $(BOARD) $(PROC)
	rm -rf ./$(BOARD)/platforms/$(OVERLAY)
	cp -rf ./$(BOARD)/output/$(OVERLAY)/export/$(OVERLAY) \
	$(BOARD)/platforms/$(OVERLAY)
	@echo "Successfully finished building vitis platform."
	@echo "Vitis platform stored in $(BOARD)/platforms/$(OVERLAY)."

tcn: cleantcn
	@echo 'Building Test Project'
	cd $(TCN_DIR) && \
	make xclbin \
	VITIS_PLATFORM=../vitis_platform/$(BOARD)/platforms/$(OVERLAY)/$(OVERLAY).xpfm \
	PORT=$(PORT) && \
	cd ..
	@echo 'Completed Building Test Project'
	@echo
	@tput setaf 2; echo "PASS: Platform successfully tested."; tput sgr0;
	@echo

test: cleantest
	@echo 'Building Test Project'
	cd $(TEST_DIR) && \
	make xclbin \
	VITIS_PLATFORM=../vitis_platform/$(BOARD)/platforms/$(OVERLAY)/$(OVERLAY).xpfm \
	PORT=$(PORT) && \
	cd ..
	@echo 'Completed Building Test Project'
	@echo
	@tput setaf 2; echo "PASS: Platform successfully tested."; tput sgr0;
	@echo

cleantcn:
	cd tcn && make clean

cleantest:
	cd test && make clean

clean: cleantest
	rm -rf ./*/output
