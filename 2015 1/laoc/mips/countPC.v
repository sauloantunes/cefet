//========
//COUNT PC
//========

module countPC (in, reset, clk, out);
	input reset, clk;
	input [4:0] in;
	output reg [4:0] out;
	
	initial begin
		out = 0;
	end
	
	always @ (posedge clk) begin
		if(reset)
			out = 0;
		else
			out = in;
	end
endmodule