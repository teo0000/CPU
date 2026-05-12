////////////////////////////////////////////////////////////////////////////////
// MODULO: register_file.v
// DESCRIZIONE: Banco di registri a 32 bit per CPU RISC-V RV32I
//
// ARCHITETTURA:
// - 32 registri generali (R0-R31) da 32 bit ciascuno
// - R0 è sempre zero (convenzione RISC-V)
// - Scrittura sincrona sul fronte positivo del clock
// - Lettura asincrona (combinatoria)
//
// UTILIZZO:
// - clk: segnale di clock (fronte positivo per scrittura)
// - reg_write: abilitazione scrittura (1 = scrivi, 0 = leggi solo)
// - rs1, rs2: indici registri sorgente (5 bit = 0-31)
// - rd: indice registro destinazione (5 bit = 0-31)
// - write_data: dati da scrivere in rd (32 bit)
// - read_data1, read_data2: dati letti da rs1, rs2 (32 bit)
// - registers_out: array output per debug (tutti i 32 registri)
//
// ESEMPIO DI UTILIZZO:
// register_file RF(.clk(clock), .reg_write(1'b1), .rs1(5'd1), .rs2(5'd2),
//                 .rd(5'd3), .write_data(32'h12345678),
//                 .read_data1(val1), .read_data2(val2), .registers_out(all_regs));
////////////////////////////////////////////////////////////////////////////////

module register_file(
 input clk,                           // Clock per scrittura sincrona
 input reg_write,                     // Abilita scrittura (1=scrivi, 0=leggi)
 input [4:0] rs1,                     // Indice registro sorgente 1 (0-31)
 input [4:0] rs2,                     // Indice registro sorgente 2 (0-31)
 input [4:0] rd,                      // Indice registro destinazione (0-31)
 input [31:0] write_data,             // Dati da scrivere (32 bit)
 output [31:0] read_data1,            // Dati letti da rs1 (32 bit)
 output [31:0] read_data2,            // Dati letti da rs2 (32 bit)
 output [31:0] registers_out [31:0]   // Output debug: tutti i registri
);

// Array di 32 registri, ciascuno da 32 bit
reg [31:0] registers[31:0];

// Lettura asincrona: i dati sono sempre disponibili
// Se l'indice è 0, restituisce sempre 0 (convenzione RISC-V)
assign read_data1 = (rs1 == 5'b0) ? 32'b0 : registers[rs1];
assign read_data2 = (rs2 == 5'b0) ? 32'b0 : registers[rs2];

// Output per debug: esporta tutto il banco registri
assign registers_out = registers;

// Scrittura sincrona: avviene solo sul fronte positivo del clock
always @(posedge clk) begin
 // Scrivi solo se reg_write è attivo e il registro destinazione non è R0
 if(reg_write && rd != 5'b0)
  registers[rd] <= write_data;        // Scrivi dati nel registro rd
end

endmodule
