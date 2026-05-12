# Implementazione di un simulatore di ciclo per architettura RISC-V (RV32I)

Questo repository contiene il codice sorgente e l'ambiente di simulazione per un processore basato sull'Instruction Set Architecture (ISA) **RISC-V**, specificamente il set base a 32-bit **RV32I**. Il progetto è stato sviluppato come parte del lavoro di tesi per l'analisi delle performance hardware e la validazione funzionale di core digitali.

## Descrizione del Progetto

Il sistema è basato su un approccio di **co-simulazione hardware/software**. Il core del processore, descritto in linguaggio Verilog, viene compilato tramite **Verilator** in un modello C++ ad alte prestazioni. Il testbench, scritto in C++, funge da wrapper per gestire l'esecuzione, l'input assembly e il monitoraggio dei segnali interni.

### Componenti principali:
*   **Core RTL**: Implementazione dei moduli critici (ALU, Register File, Control Unit, Program Counter).
*   **Interprete Assembly**: Un parser personalizzato integrato nel testbench C++ in grado di decodificare mnemonici assembly in codice binario RISC-V compatibile.
*   **Monitor di Stato**: Sistema di log per il tracciamento dei registri (`x0`-`x31`) e dei segnali di controllo durante ogni ciclo di clock.
*   **Generatore di Tracce**: Esportazione automatica in formato VCD per l'analisi temporale dei segnali.

## Requisiti Tecnici

L'ambiente di sviluppo richiede i seguenti tool:
*   **Verilator**: Per la traduzione del codice Verilog in C++.
*   **Compilatore C++**: GCC o Clang con supporto a C++11 o superiore.
*   **GTKWave**: Strumento consigliato per la visualizzazione e l'analisi dei file `.vcd` generati.

## Istruzioni Supportate (ISA Subset)

Il simulatore supporta attualmente le seguenti classi di istruzioni:

| Formato | Mnemonici | Descrizione Funzionale |
| :--- | :--- | :--- |
| **R-Type** | `ADD`, `SUB`, `AND`, `OR`, `XOR` | Operazioni aritmetico-logiche tra registri. |
| **I-Type** | `ADDI` (alias `LI`) | Operazioni con operando immediato a 12 bit. |
| **System** | `NOP`, `HALT` / `END` | Gestione del flusso e terminazione della simulazione. |

## Guida all'utilizzo

### 1. Workflow di Compilazione
Il progetto utilizza Verilator per generare il modello di simulazione. Un esempio tipico di compilazione prevede:

```bash
# Generazione dei file C++ dal sorgente Verilog
verilator --cc testbench.v --exe sim_main.cpp --trace

# Compilazione del binario finale
make -C obj_dir -f Vtestbench.mk
```

### 2. Esecuzione e Test
Il simulatore può essere avviato in modalità interattiva per testare brevi sequenze di codice:

```bash
./obj_dir/Vtestbench
```
Una volta avviato, l'utente può inserire istruzioni mnemoniche (es. `LI R1, 10`). La simulazione ha inizio al comando `END`.

## Analisi dei Risultati

Al termine di ogni istruzione, il simulatore fornisce un output strutturato che include:
1.  **Decoding Unit**: Rappresentazione binaria dell'istruzione, opcode e scomposizione dei campi (rd, rs1, rs2, imm).
2.  **Register Diff**: Visualizzazione dei soli registri che hanno subito una variazione di stato nell'ultimo ciclo.
3.  **Trace Dump**: Il file `trace.vcd` registrato consente di analizzare la logica interna, inclusi i segnali della ALU e della Control Unit, verificando la corretta propagazione dei dati.

### Esempio di log di simulazione
```text
┌─ Istruzione 1 ─────────────────────────────┐
│ LI R1, 42                                  │
│   Binario: 00000000001010100000000010010011│
│   Tipo:    I-type (Register-Immediate)     │
├─ Modifiche:                                │
│   R 1: 0 → 42                              │
└────────────────────────────────────────────┘
```

## Struttura della Directory

*   `sim_main.cpp`: Logica del testbench, parser assembly e driver della simulazione.
*   `testbench.v`: (Non incluso nel dump) Sorgente Verilog del processore.
*   `trace.vcd`: Tracciato temporale dei segnali (generato post-esecuzione).

---
