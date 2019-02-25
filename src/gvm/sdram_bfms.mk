SDRAM_BFMS_GVM_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ifneq (1,$(RULES))

SDRAM_BFMS_SRCGEN_DIR := $(abspath $(SDRAM_BFMS_GVM_DIR)../../src-gen)
SRC_DIRS += $(SDRAM_BFMS_GVM_DIR)
SRC_DIRS += $(SDRAM_BFMS_SRCGEN_DIR)/gvm

SDRAM_MASTER_BFMS_SRC = \
	$(notdir $(wildcard $(SDRAM_BFMS_GVM_DIR)/sdram_master_bfm*.cpp)) \
	$(notdir $(wildcard $(SDRAM_BFMS_SRCGEN_DIR)/gvm/sdram_master_bfm*.cpp)) \


else # Rules

libsdram_master_bfm.o : $(SDRAM_MASTER_BFMS_SRC:.cpp=.o)
	$(Q)$(LD) -r -o $@ $(SDRAM_MASTER_BFMS_SRC:.cpp=.o)


endif

