/*
 * sdram_master_bfm.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: ballance
 */

#include "sdram_master_bfm.h"

sdram_master_bfm::sdram_master_bfm() : sdram_master_bfm_base(this) {
	// TODO Auto-generated constructor stub

}

sdram_master_bfm::~sdram_master_bfm() {
	// TODO Auto-generated destructor stub
}

void sdram_master_bfm::wait_reset() {
	while (!m_is_reset) {
		m_is_reset_mutex.lock();
		m_is_reset_cond.wait(m_is_reset_mutex);
		m_is_reset_mutex.unlock();
	}
}

void sdram_master_bfm::reset_ev() {
	m_is_reset_mutex.lock();
	m_is_reset = true;
	m_is_reset_cond.notify();
	m_is_reset_mutex.unlock();
}

void sdram_master_bfm::do_nop() {
	nop();

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
}

void sdram_master_bfm::do_load_modereg(uint16_t mode) {
	fprintf(stdout, "--> load_modereg\n");
	sdram_master_bfm_base::load_modereg(mode);

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
	fprintf(stdout, "<-- load_modereg\n");
}

void sdram_master_bfm::do_precharge_all_bank() {
	precharge_all_bank();

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
}

void sdram_master_bfm::do_auto_refresh() {
	auto_refresh();

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
}

void sdram_master_bfm::do_active(uint8_t bank, uint32_t row) {
	active(bank, row);

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
}

void sdram_master_bfm::do_write(
		uint8_t 	bank,
		uint32_t 	col,
		uint64_t 	*dq,
		uint8_t 	*dqm,
		uint32_t	dq_sz) {
	for (uint32_t i=0; i<dq_sz; i++) {
		set_dq(i, dq[i], dqm[i]);
	}
	write(bank, col, dq_sz);

	m_cmdack_mutex.lock();
	m_cmdack_cond.wait(m_cmdack_mutex);
	m_cmdack_mutex.unlock();
}

void sdram_master_bfm::cmdack() {
	fprintf(stdout, "--> cmdack\n");
	m_cmdack_mutex.lock();
	m_cmdack_cond.notify();
	m_cmdack_mutex.unlock();
	fprintf(stdout, "<-- cmdack\n");
}
