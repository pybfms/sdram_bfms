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

void sdram_master_bfm::cmdack() {

}
