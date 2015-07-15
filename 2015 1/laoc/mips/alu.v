//=======
//MUX 2x1
//=======
module mux2x1(a, b, s, y);
	input a, b, s;
	output y;
	wire w1, w2;
	
	// a 1
	// b 0
	
	and and1 (w1,  a,  s);
	and and2 (w2,  b, ~s);
	or   or1 (y,  w1, w2);
endmodule

//=======
//MUX 4x1
//=======
module mux4x1(a, b, c, d, s, y);
	input a, b, c, d;
	input [1:0]s;
	output y;
	wire w1, w2;
	
	// a 3 11
	// b 2 10
	// c 1 01
	// d 0 00
	
	mux2x1 mux1(a, b,   s[0], w1);
	mux2x1 mux2(c, d,   s[0], w2);
	mux2x1 mux3(w1, w2, s[1], y);
endmodule

//==========
//FULL ADDER
//==========
module adder(a, b, cin, cout, s);
	input a, b, cin;
	output cout, s;
	wire w1, w2, w3, w4;
	
	//half-adder
	xor xor1(w1, a, b);
	and and1(w2, a, b);
	
	//half-adder
	xor xor2(s,  cin, w1);
	and and2(w3, cin, w1);
	
	or   or1(cout, w2, w3);
endmodule

//=========
//ALU SLICE
//=========
module aluSlice(a, b, operation, less, set, cin, cout, q);
	input a, b, less, cin;
	input [2:0]operation;
	output set, cout, q;
	wire w_a_and_b, w_a_or_b, w_adder, w_not_b, w_mux_b;
		
	and and1(w_a_and_b, a, b);
	or   or1(w_a_or_b,  a, b);
	not not1(w_not_b, b);
	
	mux2x1 mux2x1_1(w_not_b, b, operation[2], w_mux_b);
	adder  adder1(w_mux_b, a, cin, cout, w_adder);
	
	assign set = w_adder;
	
	//operation   result
	//   -00      a AND b
	//   -01      a OR  b
	//   010      a  +  b
	//   110      a  -  b
	//   -11      less
	
	//          11       10        01         00
	mux4x1 m1(less, w_adder, w_a_or_b, w_a_and_b, operation[1:0], q);
endmodule

//===========
//ALU 32 BITS
//===========
module ALU(a, b, operation, zero, result);
	input [31:0]a, b;
	input [2:0]operation;
	output zero;
	output [31:0]result;	
	wire [31:0] set, cout;

	//													 less                   Cin
	aluSlice alus1(a[0], b[0], operation, set[31], set[0], operation[2], cout[0], result[0]);
	
	genvar i;
	generate
	for(i=1; i<32; i=i+1) 
		begin : ALU_ASSEMBLY
			aluSlice alus(a[i], 			// input  a
							  b[i], 			// input  b
							  operation, 	// input  [2:0]operation
							  0, 				// input  less
							  set[i], 				// input  set
							  cout[i-1],   // input  Cin
							  cout[i],     // output Cout
							  result[i]);	// output result							
		end
	endgenerate
	
	assign zero = ~|result;
	
endmodule