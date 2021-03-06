module SCHK(input CLK,DIN,RST,output reg SOUT);
    parameter s0=0,s1=1,s2=2,s3=3,s4=4,s5=5,s6=6,s7=7,s8=8;
    reg[8:0] ST;
    always@(posedge CLK) begin
        SOUT=0;
        if(RST) ST<=s0;  else begin
            casex(ST)
                s0: if(DIN==1'b1) ST<=s1;  else ST<=s0;
                s1: if(DIN==1'b1) ST<=s2;  else ST<=s0;
                s2: if(DIN==1'b0) ST<=s3;  else ST<=s2;
                s3: if(DIN==1'b1) ST<=s4;  else ST<=s0;
                s4: if(DIN==1'b0) ST<=s5;  else ST<=s2;
                s5: if(DIN==1'b0) ST<=s6;  else ST<=s1;
                s6: if(DIN==1'b1) ST<=s7;  else ST<=s0;
                s7: if(DIN==1'b1) ST<=s8;  else ST<=s0;
                s8: begin SOUT=1;
                    if(DIN==1'b0) ST<=s3;  else ST<=s2;  end
                default: ST<=s0;
            endcase  end  end
endmodule 