mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	WheelCtrl.o \
<<<<<<< HEAD
	runStraight.o
=======
	ArmMove.o
>>>>>>> 2959a84138cc4df22d5dc199198acb435f2c1c1a

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIR += $(mkfile_path)app $(mkfile_path)unit

COPTS += -fno-use-cxa-atexit
