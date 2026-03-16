






module alu(
 input [31:0] a,          // RISC-V standard is 32-bit (RV32I)
 input [31:0] b,
 input [3:0] alu_op,      // Expanded to 4 bits to support more ops (SLT, shifts, etc.)
 output reg [31:0] result,
 output zero              // Essential for branch instructions (BEQ)
);

// Zero flag is high when result is 0
assign zero = (result == 32'b0);

always @(*) begin
 case(alu_op)
 4'b0000: result = a + b;       // ADD
 4'b0001: result = a - b;       // SUB
 4'b0010: result = a & b;       // AND
 4'b0011: result = a | b;       // OR
 4'b0100: result = a ^ b;       // XOR
 // Future ops: 4'b0101 for SLT (Set Less Than), Shifts, etc.
 default: result = 32'b0;
 endcase
end

endmodule
