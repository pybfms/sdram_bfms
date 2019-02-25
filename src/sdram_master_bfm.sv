/****************************************************************************
 * sdram_master_bfm.sv
 ****************************************************************************/
`include "sdram_macros.svh"

/**
 * Module: sdram_master_bfm
 * 
 * TODO: Add module documentation
 */
module sdram_master_bfm #(
		parameter int ADDR_WIDTH=11,
		parameter int DATA_WIDTH=16,
		parameter int BANKSEL_WIDTH=2) (
	input clock,
	input reset,
	`SDRAM_INITIATOR_PORT(, ADDR_WIDTH, DATA_WIDTH, BANKSEL_WIDTH)
		);

	sdram_master_bfm_core u_core(
		.clock(clock),
		.reset(reset)
		);
	
	assign addr = u_core.addr;
	assign bs = u_core.bs;
	assign u_core.dq_i = dq;
	assign dq = (we_n == 0)?u_core.dq_o:{DATA_WIDTH{1'bz}};
	assign cs_n = u_core.cs_n;
	assign ras_n = u_core.ras_n;
	assign cas_n = u_core.cas_n;
	assign we_n = u_core.we_n;
	assign dqm = u_core.dqm;
	assign cke = u_core.cke;
	
endmodule

interface sdram_master_bfm_core(
		input clock,
		input reset);
	
	reg[63:0]					addr = 0;
	reg[63:0]					addr_r = 0;
	reg[7:0]					bs = 0;
	reg[7:0]					bs_r = 0;
	reg[63:0]					dq_o = 0;
	reg[63:0]					dq_o_r = 0;
	wire[63:0]					dq_i;
	reg							cs_n = 1;
	reg							cs_n_r = 1;
	reg							ras_n = 1;
	reg							ras_n_r = 1;
	reg							cas_n = 1;
	reg							cas_n_r = 1;
	reg							we_n = 1;
	reg							we_n_r = 1;
	reg[7:0]					dqm = 0;
	reg[7:0]					dqm_r = 0;
	reg							cke = 1;
	reg							cke_r = 1;
	reg							cmd_r = 0;
	reg							cmd;
	reg							in_reset = 0;
	
	always @(posedge clock) begin
		cmd <= cmd_r;
		addr <= addr_r;
		bs <= bs_r;
		dq_o <= dq_o_r;
		cs_n <= cs_n_r;
		ras_n <= ras_n_r;
		cas_n <= cas_n_r;
		we_n <= we_n_r;
		dqm <= dqm_r;
		cke <= cke_r;
		
		if (reset == 1) begin
			in_reset <= 1;
		end else if (in_reset == 1) begin
			reset_ev();
			in_reset <= 0;
		end
		
		if (cmd_r == 1) begin
			// Automatically revert back to NOP
			cke_r = 1;
			cs_n_r = 0;
			ras_n_r = 1;
			cas_n_r = 1;
			we_n_r = 1;
			dqm_r = 0;
			
			cmd_r = 0;
		end
		
		if (cmd == 1) begin
			cmdack();
		end
	end

	// Commands:
	// precharge_all
	// auto_refresh
	// load_mode
	task sdram_master_bfm_load_modereg(shortint unsigned mode);
		cke_r = 1;
		cs_n_r = 0;
		ras_n_r = 0;
		cas_n_r = 0;
		we_n_r = 0;
		dqm_r = 0;
		bs_r = 0;
		addr_r = mode;
		cmd_r = 1;
	endtask
	
	// activate
	// write (auto-precharge)
	// read (auto-precharge)
	
	// nop
	task sdram_master_bfm_nop();
		cke_r = 1;
		cs_n_r = 0;
		ras_n_r = 1;
		cas_n_r = 1;
		we_n_r = 1;
		dqm_r = 0;
		cmd_r = 1;
	endtask
		
	
`include "sdram_master_bfm_api.svh"	

endinterface

		
		

