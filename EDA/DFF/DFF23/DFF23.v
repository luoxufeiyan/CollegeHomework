module DFF23(RST,D,CLK,Q,DOUT);
	input RST,D,CLK;
	output Q,DOUT;
	wire Q0= RST?D:0;
	wire DOUT0=Q0^D;
	reg Q,DOUT;
	always@(posedge CLK)
	begin
		Q=Q0;
		DOUT=DOUT0;
	end
endmodule