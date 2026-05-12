////////////////////////////////////////////////////////////////////////////////
// MODULO: alu.v
// DESCRIZIONE: Arithmetic Logic Unit (ALU) per CPU RISC-V RV32I
//
// FUNZIONALITA':
// - Operazioni aritmetiche: ADD, SUB
// - Operazioni logiche: AND, OR, XOR
// - Flag zero per istruzioni di branch
//
// UTILIZZO:
// - a, b: operandi a 32 bit
// - alu_op: codice operazione (4 bit)
//   * 0000: ADD (a + b)
//   * 0001: SUB (a - b)
//   * 0010: AND (a & b)
//   * 0011: OR  (a | b)
//   * 0100: XOR (a ^ b)
// - result: risultato operazione (32 bit)
// - zero: flag zero (1 se result == 0)
//
// ESEMPIO DI UTILIZZO:
// alu ALU(.a(reg1), .b(reg2), .alu_op(4'b0000), .result(sum), .zero(is_zero));
////////////////////////////////////////////////////////////////////////////////

module alu(
 input [31:0] a,          // Operando A (32 bit)
 input [31:0] b,          // Operando B (32 bit)
 input [3:0] alu_op,      // Codice operazione (4 bit)
 output reg [31:0] result,// Risultato operazione (32 bit)
 output zero              // Flag zero (per branch)
);

// Flag zero: alto quando il risultato è zero
// Utile per istruzioni BEQ (Branch if Equal)
assign zero = (result == 32'b0);

// Logica combinatoriale: esegue operazione in base ad alu_op
always @(*) begin
 case(alu_op)
  4'b0000: result = a + b;       // ADD: somma aritmetica
  4'b0001: result = a - b;       // SUB: sottrazione aritmetica
  4'b0010: result = a & b;       // AND: AND bit a bit
  4'b0011: result = a | b;       // OR:  OR bit a bit
  4'b0100: result = a ^ b;       // XOR: XOR bit a bit
  // Estensioni future:
  // 4'b0101: result = (a < b) ? 1 : 0;  // SLT (Set Less Than)
  // 4'b0110: result = a << b[4:0];      // SLL (Shift Left Logical)
  // 4'b0111: result = a >> b[4:0];      // SRL (Shift Right Logical)
  // 4'b1000: result = $signed(a) >>> b[4:0]; // SRA (Shift Right Arithmetic)
  default: result = 32'b0;       // Default: zero
 endcase
end

endmodule
