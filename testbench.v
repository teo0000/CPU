module testbench();
 reg clk, reset;
 reg [15:0] instruction;
 simple_cpu cpu(.clk(clk), .reset(reset), .instruction(instruction));

 initial begin
   clk = 0; reset = 1;
   instruction = 16'b0000_000_001_010_000; // Esempio: Opcode 0 (ADD), R1, R2...
   #5 reset = 0;
   $display("Simulation started. Reset released.");
   #100 $finish;
 end

 always #1 clk <= ~clk; // clock toggling

endmodule
