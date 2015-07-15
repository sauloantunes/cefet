//=============
//REGISTER FILE
//=============
module registerFile (addr1, addr2, writeAddr, writedata, writeEnable, data1, data2, clk);
	input writeEnable, clk;
	input  [ 4:0] addr1, addr2, writeAddr;
	input  [31:0] writedata;
	output [31:0] data1, data2;	
	reg [31:0]memory[0:31];
	
	integer i;
	initial begin
		for(i=0; i<32; i=i+1)
			memory[i] = i;
		memory[8] = 14;
		memory[9] = 15;
		memory[10] = 15;
	end
	
	always @ (posedge clk) begin
		if (writeEnable) 				
				memory[writeAddr] = writedata;
	end
	
	assign data1 = memory[addr1];
	assign data2 = memory[addr2];
endmodule