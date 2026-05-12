////////////////////////////////////////////////////////////////////////////////
// MODULO: testbench.v
// DESCRIZIONE: Testbench per simulazione e test della CPU RISC-V RV32I
//
// FUNZIONALITA':
// - Genera segnali di clock e reset
// - Fornisce istruzioni alla CPU
// - Monitora e visualizza lo stato dei registri
// - Simula esecuzione istruzioni
//
// UTILIZZO:
// - Compilare con Verilator: verilator --trace -cc testbench.v *.v --exe testbench.v
// - Eseguire: make -C obj_dir -f Vtestbench.mk && obj_dir/Vtestbench
//
// STRUTTURA TEST:
// 1. Reset iniziale (5 ns)
// 2. Esecuzione istruzioni
// 3. Monitoraggio registri
// 4. Fine simulazione
//
// ESEMPIO ISTRUZIONE:
// instruction = 32'b0000000_00011_00010_000_00001_0110011;
// Significa: ADD R1, R2, R3
// - opcode = 0110011 (R-type)
// - rd = 00001 (R1)
// - rs1 = 00010 (R2)
// - rs2 = 00011 (R3)
////////////////////////////////////////////////////////////////////////////////

module testbench(
 input clk,                          // Segnale di Clock
 input reset,                        // Segnale di Reset controllato da C++
 input [31:0] instruction            // Istruzione fornita da C++
);

// Segnali di uscita dalla CPU
wire [31:0] registers [31:0];

// Segnali singoli per GTKWave (visualization-friendly)
/* verilator lint_off UNUSEDSIGNAL */
wire [31:0] R0 = registers[0];
wire [31:0] R1 = registers[1];
wire [31:0] R2 = registers[2];
wire [31:0] R3 = registers[3];
wire [31:0] R4 = registers[4];
wire [31:0] R5 = registers[5];
wire [31:0] R6 = registers[6];
wire [31:0] R7 = registers[7];
wire [31:0] R8 = registers[8];
wire [31:0] R9 = registers[9];
wire [31:0] R10 = registers[10];
/* verilator lint_on UNUSEDSIGNAL */

// Istanza della CPU sotto test
simple_cpu cpu(
 .clk(clk),                          // Clock
 .reset(reset),                      // Reset
 .instruction(instruction),          // Istruzione da eseguire
 .registers_out(registers)           // Output debug registri
);

// Contatore di cicli (posedge clk)
integer cycle;

// Sezione di controllo basata su edge di clock (senza #delay)
always @(posedge clk) begin
    if (reset) begin
        cycle <= 0;
        $display("=== Simulazione RISC-V avviata ===");
    end
    else begin
        cycle <= cycle + 1;
        if (cycle % 5 == 0 && cycle > 0) begin
            $display("Ciclo %d:", cycle);
            $display("  R1 = %0d  R2 = %0d  R3 = %0d", registers[1], registers[2], registers[3]);
        end
    end
end

endmodule
