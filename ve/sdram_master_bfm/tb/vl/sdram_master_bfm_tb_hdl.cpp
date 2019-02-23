/****************************************************************************
 * sdram_master_bfm_tb_hdl.cpp
 ****************************************************************************/

#include "sdram_master_bfm_tb_hdl.h"
#include <stdio.h>


sdram_master_bfm_tb_hdl::sdram_master_bfm_tb_hdl() {
        addClock(top()->clock, 10);
}

sdram_master_bfm_tb_hdl::~sdram_master_bfm_tb_hdl() {

}

void sdram_master_bfm_tb_hdl::SetUp() {
}

// Register this top-level with the GoogletestVl system
static GoogletestVlEngineFactory<sdram_master_bfm_tb_hdl>         prv_factory;
