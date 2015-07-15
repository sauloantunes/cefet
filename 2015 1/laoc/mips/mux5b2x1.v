//=========
//MUX 5b2x1
//=========
module mux5b2x1(inA, inB, select, out);
	input [4:0]inA, inB;
	input select;
	output [4:0]out;
	
	assign out = select ? inA : inB;
endmodule