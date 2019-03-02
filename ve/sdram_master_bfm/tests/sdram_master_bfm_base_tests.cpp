/****************************************************************************
 * sdram_master_bfm_base_tests.cpp
 ****************************************************************************/
#include "gtest/gtest.h"
#include <stdio.h>
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

	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_precharge_all_bank();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_auto_refresh();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_auto_refresh();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_load_modereg(50);
	bfm->do_nop();

	bfm->do_active(0, 0); // bank 0, col 0
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_write(0, 0, 100, 0);
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_write(0, 1, 101, 0);
	bfm->do_write(0, 1, 102, 0);
	bfm->do_write(0, 1, 103, 0);
	bfm->do_write(0, 1, 104, 0);
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();
	bfm->do_nop();

//	GoogletestHdl::raiseObjection();
//	run();
}
