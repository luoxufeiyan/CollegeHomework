module DFF24(D,EN,CLK,RST,Q1,Q);
	input D,EN,CLK,RST;
	output Q1,Q;
	wire Q10=D&EN;
	wire Q11=RST|!Q10;
	wire Q1=Q11;
	reg Q;
	always@(posedge CLK or negedge RST)
	begin
		if(!RST) Q<=0;
		else if (EN) Q<=D;
	end
endmodule
