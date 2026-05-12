////////////////////////////////////////////////////////////////////////////////
// MODULO: program_counter.v
// DESCRIZIONE: Program Counter (PC) per CPU RISC-V RV32I
//
// FUNZIONALITA':
// - Tiene traccia dell'indirizzo dell'istruzione corrente
// - Incremento semplice (+1 per istruzioni consecutive)
// - Reset sincrono a zero
//
// UTILIZZO:
// - clk: segnale di clock (fronte positivo)
// - reset: reset sincrono (alto = azzera PC)
// - next_pc: indirizzo prossima istruzione (32 bit)
// - pc: indirizzo corrente (32 bit)
//
// NOTE:
// - In una CPU completa, next_pc verrebbe calcolato da:
//   * PC + 4 (istruzione successiva)
//   * Indirizzo branch/jump
//   * Eccezioni/interrupt
//
// ESEMPIO DI UTILIZZO:
// program_counter PC(.clk(clock), .reset(rst), .next_pc(pc + 4), .pc(current_pc));
////////////////////////////////////////////////////////////////////////////////

module program_counter(
 input clk,                           // Clock principale
 input reset,                         // Reset sincrono (alto = reset)
 input [31:0] next_pc,                // Prossimo valore del PC
 output reg [31:0] pc                 // Program Counter corrente
);

// Logica sequenziale: aggiorna PC sul fronte positivo del clock
always @(posedge clk) begin
 if(reset)                            // Reset sincrono attivo
  pc <= 0;                           // Azzera PC
 else                                 // Clock normale
  pc <= next_pc;                     // Carica prossimo PC
end

endmodule
