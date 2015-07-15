module mips(clk);
	parameter PC_RESET = 0;
	input clk;
	wire RegDst, RegWrite, ALUSrc, MemWrite, MemRead, MemtoReg, Jump;
	wire [1:0] ALUOp;
	wire w9, w17;
	wire [2:0] w13;
	wire [4:0] w1, w2, w4, w23;
	wire [5:0] w18, w19;
	wire [25:0] w20;
	wire [31:0] w3, w5, w6, w7, w8, w10, w11, w12, w14, w15, w16, w21, w22;
	
	assign w18 = w3[25:21];
	assign w19 = w3[20:16];
	
	//countPC (in[4:0], reset, clk, out[4:0]);
	countPC pc(w23, PC_RESET, clk, w2);
	
	//instructionMemory(readAddr[4:0], instruction[31:0]);
	instructionMemory instMem(w2, w3);
	
	//mux5b2x1(inA[4:0], inB[4:0], select, out[4:0]);	
	//out = select ? inA : inB
	mux5b2x1 m1(w3[15:11], w3[20:16], RegDst, w4);
	
	//registerFile (addr1[4:0], addr2[4:0], writeAddr[4:0], writedata[31:0], writeEnable, data1[31:0], data2[31:0], clk);
	registerFile regs(w18, w19, w4, w12, RegWrite, w5, w6, clk);
	
	//mux32b2x1(inA[31:0], inB[31:0], select, out[31:0]);
	//out = select ? inA : inB
	mux32b2x1 m2(w7, w6, ALUSrc, w8);
	
	//ALU(a[31:0], b[31:0], operation[2:0], zero, result[31:0]);
	ALU alu(w5, w8, w13, w9, w10);
	
	//dataMemory(memAddr[4:0], memWrite, memRead, clk, writeData[31:0], readData[31:0]);
	dataMemory dataMem(w10, MemWrite, MemRead, clk, w6, w11);
	
	//mux32b2x1(inA[31:0], inB[31:0], select, out[31:0]);
	//out = select ? inA : inB
	mux32b2x1 m3(w11, w10, MemtoReg, w12);

	//signExtend(in[15:0], out[31:0]);
	signExtend signExt(w3[15:0], w7);
	
	//shiftLeft2 (in[31:0], out[31:0]);
	shiftLeft2 sl1(w7, w15);
	
	//ALUControl(F[5:0], ALUOp[2:1], Operation[2:0]);
	ALUControl aluControl(w3[5:0], ALUOp, w13);
	
	//Control(Op[5:0], RegDst, Jump, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp[1:0]);
	Control control(w3[31:26], RegDst, Jump, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp);
	
	//mux32b2x1(inA[31:0], inB[31:0], select, out[31:0]);
	//out = select ? inA : inB
	mux32to5b2x1 m4(w16, w14, w17, w1);
	
	//adder5x32b(inA[4:0], inB[4:0], out[31:0]);
	adder5x32b add1(w2, 5'b0100, w14);	
	
	//adder32b(inA[31:0], inB[31:0], out[31:0]);
	adder32b add2(w14, w15, w16);
	
	and a1(w17, Branch, w9);
	
	//Jump implementation
	assign w20 = w3[25:0];
	
	//shiftLeft2 (in[31:0], out[31:0]);
	shiftLeft2 sl2({6'b0, w20}, w21);
	
	//mux32b2x1(inA[31:0], inB[31:0], select, out[31:0]);
	//out = select ? inA : inB
	mux32b2x1 m5(w21, w1, Jump, w22);
	assign w23 = w22[4:0];
	
endmodule
