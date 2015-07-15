//=========
//MUX 32to5b2x1
//=========

module mux32to5b2x1(inA, inB, select, out);
	input [31:0]inA, inB;
	input select;
	output [4:0]out;
	
	assign out = select ? inA[4:0] : inB[4:0];
endmodule