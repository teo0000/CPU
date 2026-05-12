////////////////////////////////////////////////////////////////////////////////
// MODULO: control_unit.v
// DESCRIZIONE: Unità di controllo per decodifica istruzioni RISC-V RV32I
//
// FUNZIONALITA':
// - Decodifica opcode e genera segnali di controllo
// - Supporta istruzioni R-type: ADD, SUB, AND, OR, XOR
// - Placeholder per LOAD/STORE (da implementare)
//
// UTILIZZO:
// - opcode: opcode a 7 bit dall'istruzione (bit 0-6)
// - reg_write: segnale scrittura registro (1=scrivi nel registro destinazione)
// - alu_op: codice operazione ALU (4 bit)
//
// CODICI OPERAZIONE ALU:
// - 0000: ADD
// - 0001: SUB
// - 0010: AND
// - 0011: OR
// - 0100: XOR
//
// ESEMPIO DI UTILIZZO:
// control_unit CU(.opcode(instr[6:0]), .reg_write(write_en), .alu_op(op_code));
////////////////////////////////////////////////////////////////////////////////

module control_unit(
 /* verilator lint_off UNUSEDSIGNAL */
 input [31:0] instruction,             // Istruzione completa per decodifica
 /* verilator lint_on UNUSEDSIGNAL */
 output reg reg_write,                 // Abilita scrittura registro destinazione
 output reg [3:0] alu_op               // Codice operazione ALU (4 bit)
);

// Logica combinatoriale: decodifica opcode e genera segnali
always @(*) begin
 case(instruction[6:0])               // Usa l'opcode dall'istruzione
  // Istruzioni I-type (ADDI, LI, etc)
  7'b0010011: begin                   // I-type opcode (ADDI, etc)
   reg_write = 1;                     // Scrivi nel registro destinazione
   alu_op = 4'b0000;                  // ADD (per immediati)
  end

  // Istruzioni LOAD (da implementare completamente)
  7'b0000011: begin                   // LOAD opcode
   reg_write = 1;                     // Scrivi nel registro destinazione
   alu_op = 4'b0000;                  // ADD (per calcolo indirizzo)
  end

  // Istruzioni STORE (da implementare completamente)
  7'b0100011: begin                   // STORE opcode
   reg_write = 0;                     // Non scrivere registri (scrivi memoria)
   alu_op = 4'b0000;                  // ADD (per calcolo indirizzo)
  end

  // Istruzioni R-type (Register-Register)
  7'b0110011: begin                   // R-type opcode
   reg_write = 1;
   // Decodifica basata su funct3 (bit 12-14) e funct7 (bit 30)
   case(instruction[14:12])
    3'b000: begin
     if (instruction[30]) alu_op = 4'b0001; // SUB
     else                 alu_op = 4'b0000; // ADD
    end
    3'b111: alu_op = 4'b0010; // AND
    3'b110: alu_op = 4'b0011; // OR
    3'b100: alu_op = 4'b0100; // XOR
    default: alu_op = 4'b0000;
   endcase
  end

  // Opcode non riconosciuto
  default: begin
   reg_write = 0;                     // Non scrivere
   alu_op = 4'b0000;                  // Operazione neutra
  end
 endcase
end

endmodule
