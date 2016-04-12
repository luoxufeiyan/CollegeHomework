module FDIV0(input CLK,RST,input[3:0]D,output PM,output[3:0]DOUT);
reg[3:0] Q1;	reg FULL;
(* synthesis,keep	*) wire LD;
always@(posedge CLK or negedge RST)
	if(!RST) begin Q1<=0;FULL<=0;end
		else if(LD) begin Q1<=D; FULL<=1;end
			else begin Q1<=Q1+1;FULL<=0;end
	assign LD=(Q1==4'B1111); assign PM=FULL; assign DOUT=Q1;
endmodule