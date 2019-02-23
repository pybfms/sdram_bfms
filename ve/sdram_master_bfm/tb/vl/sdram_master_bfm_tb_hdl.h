/****************************************************************************
 * sdram_master_bfm_tb_hdl.h
 ****************************************************************************/

#ifndef INCLUDED_sdram_master_bfm_TB_HDL_H
#define INCLUDED_sdram_master_bfm_TB_HDL_H
#include "GoogletestVlEngine.h"
#include "Vsdram_master_bfm_tb_hdl.h"

using namespace gtest_hdl;

class sdram_master_bfm_tb_hdl : public GoogletestVlEngine<Vsdram_master_bfm_tb_hdl> {
public:
        sdram_master_bfm_tb_hdl();

        virtual ~sdram_master_bfm_tb_hdl();

        virtual void SetUp();

};


#endif /* INCLUDED_sdram_master_bfm_TB_HDL_H */
