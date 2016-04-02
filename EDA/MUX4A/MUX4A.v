module MUX4A (A,B,C,D,S3,S2,S1,S0,Y);
	input A,B,C,D,S3,S2,S1,S0;
	output Y;
	reg[3:0] SEL;reg Y;
	always@(A,B,C,D,SEL)
		begin 
				SEL={S3,S2,S1,S0};
				if (SEL == 4'b1110) Y=A;
				else if (SEL == 4'b 1101) Y=B;
				else if (SEL == 4'b 1011) Y=C; 
				else if (SEL == 4'b 0111) Y=D;
		end
endmodule