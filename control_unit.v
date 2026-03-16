module control_unit(
 input [3:0] opcode,
 output reg reg_write,
 output reg [2:0] alu_op
);

always @(*) begin
 case(opcode)
 4'b0000: begin reg_write = 1; alu_op = 3'b000; end // ADD
 4'b0001: begin reg_write = 1; alu_op = 3'b001; end // SUB
 4'b0010: begin reg_write = 1; alu_op = 3'b010; end // AND
 4'b0011: begin reg_write = 1; alu_op = 3'b011; end // OR
 default: begin reg_write = 0; alu_op = 3'b000; end
 endcase
end

endmodule
