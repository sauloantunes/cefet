//==================
//INSTRUCTION MEMORY
//==================

module instructionMemory(readAddr, instruction);
	input  [ 4:0] readAddr;
	output [31:0] instruction;
	reg [7:0] memory [0:31];
	integer i;
	
	initial
	begin
		for(i=0; i<32; i=i+1)
			memory[i] = 0;
			
		{memory[3],  memory[2],  memory[1],  memory[0]}   = 32'b00010001000010010000000000000011;
		{memory[7],  memory[6],  memory[5],  memory[4]}   = 32'b00010001001010100000000000000011;
		{memory[23],  memory[22],  memory[21],  memory[20]} = 32'b00001000000000000000000000000000;
	end
	
	assign instruction = {memory[readAddr+3], memory[readAddr+2], memory[readAddr+1], memory[readAddr]};
endmodule