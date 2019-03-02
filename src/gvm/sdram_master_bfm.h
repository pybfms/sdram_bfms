/*
 * sdram_master_bfm.h
 *
 *  Created on: Feb 24, 2019
 *      Author: ballance
 */
#pragma once
#include "sdram_master_bfm_base.h"
#include "GvmMutex.h"
#include "GvmCond.h"

class sdram_master_bfm : \
	public sdram_master_bfm_base,
	public virtual sdram_master_bfm_rsp_if {
public:
	sdram_master_bfm();

	virtual ~sdram_master_bfm();

	virtual void wait_reset();

    virtual void reset_ev();

    virtual void cmdack();

    virtual void do_nop();

    virtual void do_load_modereg(uint16_t mode);

    virtual void do_precharge_all_bank();

    virtual void do_auto_refresh();

    virtual void do_active(uint8_t bank, uint32_t row);

    virtual void do_write(
    		uint8_t  bank,
			uint32_t col,
			uint64_t *dq,
			uint8_t  *dqm,
			uint32_t dq_sz);

private:
    bool						m_is_reset;
    GvmMutex					m_is_reset_mutex;
    GvmCond						m_is_reset_cond;

    GvmMutex					m_cmdack_mutex;
    GvmCond						m_cmdack_cond;

};

typedef GvmBfmType<sdram_master_bfm>			sdram_master_bfm_t;

