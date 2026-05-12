////////////////////////////////////////////////////////////////////////////////
// MODULO: simple_cpu.v
// DESCRIZIONE: Implementazione di una CPU RISC-V RV32I semplificata a 32 bit
//
// ARCHITETTURA:
// - 32 registri a 32 bit (R0-R31)
// - Istruzioni in formato RISC-V RV32I
// - ALU con operazioni base (ADD, SUB, AND, OR, XOR)
// - Program Counter a 32 bit
//
// UTILIZZO:
// - clk: segnale di clock (positivo)
// - reset: reset sincrono (alto = reset)
// - instruction: istruzione a 32 bit in ingresso (formato RISC-V)
// - registers_out: output array per visualizzare tutti i 32 registri
//
// ESEMPIO DI UTILIZZO:
// simple_cpu cpu(.clk(clock), .reset(rst), .instruction(instr),
//               .registers_out(regs));
////////////////////////////////////////////////////////////////////////////////

module simple_cpu(
 input clk,                           // Clock principale (fronte positivo)
 input reset,                         // Reset sincrono (alto = reset)
 /* verilator lint_off UNUSEDSIGNAL */
 input [31:0] instruction,            // Istruzione a 32 bit dall'esterno (formato RISC-V)
 /* verilator lint_on UNUSEDSIGNAL */
  output [31:0] registers_out [31:0]   // ERRORE: Yosys non supporta array unpacked nei port del modulo
 // output [1023:0] registers_out          // Versione corretta: Vettore piatto da 1024 bit (32 registri * 32 bit)
);

// Segnali interni per connessione moduli
wire [31:0] pc;                       // Program Counter (indirizzo corrente)
// wire [31:0] instruction;            // Commentato: ora è input esterno

// Campi decodificati dall'istruzione RISC-V
wire [4:0] rs1, rs2, rd;              // Indici registri (5 bit = 32 registri)
wire [6:0] opcode;                    // Opcode principale (7 bit RISC-V)
wire [31:0] reg_data1, reg_data2;     // Dati letti dai registri
wire [31:0] immediate;                // Valore immediato estratto dall'istruzione
wire [31:0] alu_operand_b;            // Operando B per ALU (reg_data2 o immediate)
wire [31:0] alu_result;               // Risultato ALU
wire reg_write;                       // Segnale scrittura registro
wire [3:0] alu_op;                    // Operazione ALU (4 bit per estensioni)
/* verilator lint_off UNUSEDSIGNAL */
wire zero;                            // Flag zero dall'ALU (usato per branch)
/* verilator lint_on UNUSEDSIGNAL */

// Decodifica campi istruzione RISC-V RV32I
/* verilator lint_off UNUSEDSIGNAL */
assign opcode = instruction[6:0];     // Opcode: bit 0-6
/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_off UNUSEDSIGNAL */
assign rd = instruction[11:7];        // Registro destinazione: bit 7-11
assign rs1 = instruction[19:15];      // Registro sorgente 1: bit 15-19
assign rs2 = instruction[24:20];      // Registro sorgente 2: bit 20-24
/* verilator lint_on UNUSEDSIGNAL */

// Estrazione immediato I-type (con sign extension)
/* verilator lint_off UNUSEDSIGNAL */
assign immediate = {{20{instruction[31]}}, instruction[31:20]};
/* verilator lint_on UNUSEDSIGNAL */

// Multiplexer: seleziona operando B in base all'opcode
// I-type (0010011): usa immediate, R-type (0110011): usa reg_data2
/* verilator lint_off UNUSEDSIGNAL */
assign alu_operand_b = (opcode == 7'b0010011) ? immediate : reg_data2;
/* verilator lint_on UNUSEDSIGNAL */

// Istanziazione moduli componenti
program_counter PC(
 .clk(clk),                           // Clock
 .reset(reset),                       // Reset
 .next_pc(pc + 1),                    // Prossimo PC (incremento semplice)
 .pc(pc)                             // PC corrente
);

register_file RF(
 .clk(clk),                          // Clock
 .reg_write(reg_write),              // Abilita scrittura
 .rs1(rs1),                          // Registro sorgente 1
 .rs2(rs2),                          // Registro sorgente 2
 .rd(rd),                            // Registro destinazione
 .write_data(alu_result),            // Dati da scrivere (da ALU)
 .read_data1(reg_data1),             // Dati letti rs1
 .read_data2(reg_data2),             // Dati letti rs2
 .registers_out(registers_out)       // Output debug tutti registri
);

alu ALU(
 .a(reg_data1),                      // Operando A (da rs1)
 .b(alu_operand_b),                  // Operando B (da rs2 per R-type, o immediato per I-type)
 .alu_op(alu_op),                    // Operazione da eseguire
 .result(alu_result),                // Risultato operazione
 .zero(zero)                         // Flag zero (utile per branch)
);

control_unit CU(
 .instruction(instruction),          // Passa l'intera istruzione
 .reg_write(reg_write),              // Segnale scrittura registro
 .alu_op(alu_op)                     // Operazione ALU
);

endmodule
