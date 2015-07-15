//=======
//CONTROL
//=======

module Control(Op, RegDst, Jump, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp);
	input [5:0]Op;
	output RegDst, Jump, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch;
	output [1:0] ALUOp;
	wire R, lw, sw, beq, jump;
	
	and and1(R,    ~Op[0], ~Op[1], ~Op[2], ~Op[3], ~Op[4], ~Op[5]);
	and and2(lw,    Op[0],  Op[1], ~Op[2], ~Op[3], ~Op[4],  Op[5]);
	and and3(sw,    Op[0],  Op[1], ~Op[2],  Op[3], ~Op[4],  Op[5]);
	and and4(beq,  ~Op[0], ~Op[1],  Op[2], ~Op[3], ~Op[4], ~Op[5]);
	and and5(jump, ~Op[0],  Op[1], ~Op[2], ~Op[3], ~Op[4], ~Op[5]);
	
	or or1(ALUSrc,  lw, sw);
	or or2(RegWrite, R, lw);
	
	assign RegDst = R;
	assign MemtoReg = lw; 
	assign MemRead = lw;
	assign MemWrite = sw;
	assign Branch = beq;
	assign ALUOp[0] = beq;
	assign ALUOp[1] = R;
	assign Jump = jump;
endmodule
