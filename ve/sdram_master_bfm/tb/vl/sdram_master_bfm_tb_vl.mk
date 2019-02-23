

sdram_master_bfm_TB_VL_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

ifneq (1,$(RULES))

ifeq (vl,$(SIM))
SRC_DIRS += $(sdram_master_bfm_TB_VL_DIR)
endif

sdram_master_bfm_TB_VL_SRC_FILES=$(wildcard $(sdram_master_bfm_TB_VL_DIR)/*.cpp)
sdram_master_bfm_TB_VL_SRC=$(notdir $(sdram_master_bfm_TB_VL_SRC_FILES))

else # Rules

# Compilation of the testbench wrapper requires the
# translated header files produced by vl_translate.d
libsdram_master_bfm_tb_vl.o : sdram_master_bfm_tb_hdl.cpp vl_translate.d
	$(Q)$(CXX) -c -o $@ $(CXXFLAGS) $(filter %.cpp,$(^))

endif
