
SDRAM_BFMS_MKFILES_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
SDRAM_BFMS := $(abspath $(SDRAM_BFMS_MKFILES_DIR)/..)
export SDRAM_BFMS

ifneq (1,$(RULES))


else # Rules

endif