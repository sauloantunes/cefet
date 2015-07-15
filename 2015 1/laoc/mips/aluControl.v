//===========
//ALU CONTROL
//===========

module ALUControl(F, ALUOp, Operation);
	input [5:0]F;
	input [2:1]ALUOp;	
	output [2:0]Operation;
	wire w1, w2;

	or or1(w1, F[0], F[3]);
	or or2(Operation[2], w2, ALUOp[1]);

	and and1(w2, ALUOp[2], F[1]);
	and and2(Operation[0], ALUOp[2], w1);

	nand nand1(Operation[1], ALUOp[2], F[2]);
endmodule