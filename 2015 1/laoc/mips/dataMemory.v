//===========
//DATA MEMORY
//===========
module dataMemory(memAddr, memWrite, memRead, clk, writeData, readData);
	input memWrite, memRead, clk;
	input [ 4:0] memAddr;
	input [31:0] writeData;
	output reg [31:0] readData;
	reg [7:0] memory [0:31];
	integer i;
	
	initial
	begin
		for(i=0; i<32; i=i+1)
			memory[i] = i;
		{memory[3], memory[2], memory[1], memory[0]} = 15;
	end
	
	always @ (*) begin
		if(memWrite)
			{memory[memAddr+3], memory[memAddr+2], memory[memAddr+1], memory[memAddr]} = writeData;
			
		if(memRead)
			readData = {memory[memAddr+3], memory[memAddr+2], memory[memAddr+1], memory[memAddr]};
	end
endmodule