mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	WheelCtrl.o \
	ArmMove.o \
	pidCtrl.o \
	RightAngleDetection.o \
	Tracer.o\
	Calibration.o\
	plaBoard.o\
	SumouMove.o\
	ItemMove.o\

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += $(mkfile_path)app $(mkfile_path)unit

COPTS += -fno-use-cxa-atexit
