module simple_cpu(
 input clk,
 input reset,
 /* verilator lint_off UNUSEDSIGNAL */
 input [15:0] instruction // Modifica temporanea: l'istruzione viene dall'esterno
 /* verilator lint_on UNUSEDSIGNAL */
);

wire [15:0] pc;
// wire [15:0] instruction; // Rimosso wire interno, ora è un input

wire [2:0] rs1, rs2, rd;
wire [3:0] opcode;
wire [15:0] reg_data1, reg_data2;
wire [15:0] alu_result;
wire reg_write;
wire [2:0] alu_op;

assign opcode = instruction[15:12];
assign rd = instruction[11:9];
assign rs1 = instruction[8:6];
assign rs2 = instruction[5:3];

program_counter PC(.clk(clk), .reset(reset), .next_pc(pc + 1), .pc(pc));
register_file RF(.clk(clk), .reg_write(reg_write), .rs1(rs1), .rs2(rs2), .rd(rd), .write_data(alu_result), .read_data1(reg_data1), .read_data2(reg_data2));
alu ALU(.a(reg_data1), .b(reg_data2), .alu_op(alu_op), .result(alu_result));
control_unit CU(.opcode(opcode), .reg_write(reg_write), .alu_op(alu_op));

endmodule
