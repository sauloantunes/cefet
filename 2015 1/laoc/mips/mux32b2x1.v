//=========
//MUX 32b2x1
//=========
module mux32b2x1(inA, inB, select, out);
	input [31:0]inA, inB;
	input select;
	output [31:0]out;
	
	assign out = select ? inA : inB;
endmodule