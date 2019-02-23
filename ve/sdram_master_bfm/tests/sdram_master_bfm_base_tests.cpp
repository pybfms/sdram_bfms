/****************************************************************************
 * sdram_master_bfm_base_tests.cpp
 ****************************************************************************/

#include "sdram_master_bfm_base_tests.h"

void sdram_master_bfm_base_tests::SetUp() {
}

void sdram_master_bfm_base_tests::TearDown() {
}

void sdram_master_bfm_base_tests::run() {
	GoogletestHdl::run();
}

/**
 * smoke test
 */
TEST_F(sdram_master_bfm_base_tests,smoke) {
	const CmdlineProcessor &clp = GoogletestHdl::clp();

	fprintf(stdout, "Hello from sdram_master_bfm_base_tests.smoke\n");

	GoogletestHdl::raiseObjection();
	run();
}
