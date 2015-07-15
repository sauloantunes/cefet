module adder5x32b(inA, inB, out);
	input  [4:0]inA, inB;
	output [31:0]out;
	
	assign out = inA + inB;
endmodule