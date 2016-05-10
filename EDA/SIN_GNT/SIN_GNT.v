module SIN_GNT(RST,CLK,EN,Q,AR); 
output [7:0]Q;output[6:0]AR; 
input EN,CLK,RST;wire[6:0]TMP;reg[6:0]Q1; 
always @(posedge CLK or negedge RST) 
if (!RST) Q1<=7'B0000000; 
else if(EN) Q1<=Q1+1; 
else Q1<=Q1; 
assign TMP=Q1; 
SIN_PL IC1(.address(TMP),.clock(CLK),.q(Q)); 
endmodule 