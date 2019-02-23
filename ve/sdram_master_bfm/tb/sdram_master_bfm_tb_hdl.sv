/****************************************************************************
 * sdram_master_bfm_tb_hdl.sv
 ***************************************************************************/
`include "sdram_macros.svh"
 
module sdram_master_bfm_tb_hdl(input clock);

`ifdef HAVE_HDL_CLKGEN
	reg clk_r = 0;

	initial begin
		forever begin
			#10ns;
			clk_r <= ~clk_r;
		end
	end

	assign clock = clk_r;
`endif

	reg reset = 1;
	reg [7:0] reset_cnt = 0;

	always @(posedge clock) begin
		if (reset_cnt == 10) begin
			reset <= 0;
		end else begin
			reset_cnt <= reset_cnt + 1;
		end
	end
	
	`SDRAM_WIRES(bfm2dut_, 11, 16, 2);

	sdram_master_bfm #(
		.DATA_WIDTH     (16    ), 
		.ADDR_WIDTH     (11    ), 
		.BANKSEL_WIDTH  (2 )
		) u_bfm (
			.clock		(clock			),
			.reset		(reset			),
			`SDRAM_CONNECT(, bfm2dut_)
		);

	mt48lc16m16a2 #(
			.addr_bits(11)
		) u_dut (
		.Dq     (bfm2dut_dq    ), 
		.Addr   (bfm2dut_addr  ), 
		.Ba     (bfm2dut_bs    ), 
		.Clk    (clock         ), 
		.Cke    (bfm2dut_cke   ), 
		.Cs_n   (bfm2dut_cs_n  ), 
		.Ras_n  (bfm2dut_ras_n ), 
		.Cas_n  (bfm2dut_cas_n ), 
		.We_n   (bfm2dut_we_n  ), 
		.Dqm    (bfm2dut_dqm   ));
	
endmodule