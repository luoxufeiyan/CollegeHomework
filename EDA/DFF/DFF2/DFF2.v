module DFF2(CLK,D,Q,EN,SET,RESET);
	input SET,D,CLK,EN,RESET;
	output Q;
	wire Qreg0=SET&!RESET;
	reg Q;
	always@(posedge CLK or negedge RESET)
	begin
		if(!RESET)Q<=Qreg0;
	else if (EN) Q<=D;
	end
endmodule
