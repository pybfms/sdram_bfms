/****************************************************************************
 * sdram_master_bfm_base_tests.cpp
 ****************************************************************************/
#include "gtest/gtest.h"
#include "sdram_master_bfm_base_tests.h"
#include "sdram_master_bfm.h"

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
TEST_F(sdram_master_bfm_base_tests, smoke) {
	const CmdlineProcessor &clp = GoogletestHdl::clp();

	fprintf(stdout, "Hello from sdram_master_bfm_base_tests.smoke\n");

	sdram_master_bfm *bfm = sdram_master_bfm_t::bfm("*.u_bfm");

	fprintf(stdout, "--> wait_reset\n");
	bfm->wait_reset();
	fprintf(stdout, "<-- wait_reset\n");

	GoogletestHdl::raiseObjection();
	run();
}
