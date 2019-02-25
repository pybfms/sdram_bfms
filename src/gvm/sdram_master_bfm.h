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

private:
    bool						m_is_reset;
    GvmMutex					m_is_reset_mutex;
    GvmCond						m_is_reset_cond;

};

typedef GvmBfmType<sdram_master_bfm>			sdram_master_bfm_t;

