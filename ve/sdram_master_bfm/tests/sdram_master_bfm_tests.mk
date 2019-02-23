

sdram_master_bfm_TESTS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

ifneq (1,$(RULES))

SRC_DIRS += $(sdram_master_bfm_TESTS_DIR)
# TODO: Add source directories for each relevant sub-directory

sdram_master_bfm_TESTS_SRC := $(notdir $(wildcard $(sdram_master_bfm_TESTS_DIR)/*.cpp))

else # Rules


libsdram_master_bfm_tests.o : $(sdram_master_bfm_TESTS_SRC:.cpp=.o)
	$(Q)$(LD) -r -o $@ $(sdram_master_bfm_TESTS_SRC:.cpp=.o)
        

endif