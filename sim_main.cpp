#include "Vtestbench.h"
#include "Vtestbench___024root.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iomanip>

// Struttura che rappresenta un'istruzione decodificata secondo il protocollo RISC-V
struct DecodedInst {
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    int32_t imm;
};

// Funzione per creare istruzioni RISC-V R-type
uint32_t createRInstruction(uint8_t funct7, uint8_t rs2, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {
    return ((uint32_t)funct7 << 25) | ((uint32_t)rs2 << 20) | ((uint32_t)rs1 << 15) | 
           ((uint32_t)funct3 << 12) | ((uint32_t)rd << 7) | opcode;
}

// Crea istruzione I-type (per immediati)
uint32_t createIInstruction(int32_t imm, uint8_t rs1, uint8_t funct3, uint8_t rd, uint8_t opcode) {
    uint32_t imm_field = (int32_t)imm & 0xFFF;
    return (imm_field << 20) | ((uint32_t)rs1 << 15) | ((uint32_t)funct3 << 12) | 
           ((uint32_t)rd << 7) | opcode;
}

// Estrai numero da stringa (supporta formati decimali e hex)
int parseNumber(const std::string& str) {
    if (str.length() > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        return std::stoi(str, nullptr, 16);
    }
    return std::stoi(str, nullptr, 10);
}

// Estrai registro
int parseRegister(const std::string& str) {
    if (str[0] == 'r' || str[0] == 'R') {
        return parseNumber(str.substr(1));
    }
    return parseNumber(str);
}

// Estrai token ignorando virgole
std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::string current;
    for (char c : str) {
        if (c == ',' || std::isspace(c)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}

// Parser assembly robusto
uint32_t parseAssembly(const std::string& line, std::string& logMsg) {
    size_t commentPos = line.find('#');
    std::string cleanLine = (commentPos == std::string::npos) ? line : line.substr(0, commentPos);
    
    if (cleanLine.empty()) return 0;

    auto tokens = tokenize(cleanLine);
    if (tokens.empty()) return 0;
    
    std::string op = tokens[0];
    std::transform(op.begin(), op.end(), op.begin(), ::tolower);
    
    logMsg = "";
    
    try {
        if (op == "add") {
            if (tokens.size() < 4) throw std::runtime_error("ADD richiede 3 parametri");
            int rd = parseRegister(tokens[1]);
            int rs1 = parseRegister(tokens[2]);
            int rs2 = parseRegister(tokens[3]);
            logMsg = "ADD R" + std::to_string(rd) + ", R" + std::to_string(rs1) + ", R" + std::to_string(rs2);
            return createRInstruction(0, rs2, rs1, 0, rd, 0b0110011);
        }
        else if (op == "sub") {
            if (tokens.size() < 4) throw std::runtime_error("SUB richiede 3 parametri");
            int rd = parseRegister(tokens[1]);
            int rs1 = parseRegister(tokens[2]);
            int rs2 = parseRegister(tokens[3]);
            logMsg = "SUB R" + std::to_string(rd) + ", R" + std::to_string(rs1) + ", R" + std::to_string(rs2);
            return createRInstruction(0x20, rs2, rs1, 0, rd, 0b0110011);
        }
        else if (op == "and") {
            if (tokens.size() < 4) throw std::runtime_error("AND richiede 3 parametri");
            int rd = parseRegister(tokens[1]);
            int rs1 = parseRegister(tokens[2]);
            int rs2 = parseRegister(tokens[3]);
            logMsg = "AND R" + std::to_string(rd) + ", R" + std::to_string(rs1) + ", R" + std::to_string(rs2);
            return createRInstruction(0, rs2, rs1, 7, rd, 0b0110011);
        }
        else if (op == "or") {
            if (tokens.size() < 4) throw std::runtime_error("OR richiede 3 parametri");
            int rd = parseRegister(tokens[1]);
            int rs1 = parseRegister(tokens[2]);
            int rs2 = parseRegister(tokens[3]);
            logMsg = "OR R" + std::to_string(rd) + ", R" + std::to_string(rs1) + ", R" + std::to_string(rs2);
            return createRInstruction(0, rs2, rs1, 6, rd, 0b0110011);
        }
        else if (op == "xor") {
            if (tokens.size() < 4) throw std::runtime_error("XOR richiede 3 parametri");
            int rd = parseRegister(tokens[1]);
            int rs1 = parseRegister(tokens[2]);
            int rs2 = parseRegister(tokens[3]);
            logMsg = "XOR R" + std::to_string(rd) + ", R" + std::to_string(rs1) + ", R" + std::to_string(rs2);
            return createRInstruction(0, rs2, rs1, 4, rd, 0b0110011);
        }
        else if (op == "li" || op == "addi") {
            if (tokens.size() < 3) throw std::runtime_error("LI richiede 2 parametri");
            int rd = parseRegister(tokens[1]);
            int imm = parseNumber(tokens[2]);
            logMsg = "LI R" + std::to_string(rd) + ", " + std::to_string(imm);
            return createIInstruction(imm, 0, 0, rd, 0b0010011);
        }
        else if (op == "nop") {
            logMsg = "NOP";
            return 0;
        }
        else if (op == "halt" || op == "end") {
            logMsg = "HALT";
            return 0xFFFFFFFF;
        }
        else {
            logMsg = "❌ Istruzione sconosciuta: " + op;
            return 0;
        }
    } catch (const std::exception& e) {
        logMsg = "❌ Errore: " + std::string(e.what());
        return 0;
    }
}

void printRegisters(Vtestbench* top, std::vector<int> regs_to_show = {}) {
    if (regs_to_show.empty()) {
        // Se non specificati, mostra tutti i registri non-zero
        for (int i = 0; i < 32; i++) {
            uint32_t val = top->rootp->testbench__DOT__registers[i];
            if (val != 0 || i == 0) {  // Mostra sempre R0
                char hex_buf[16];
                sprintf(hex_buf, "%08x", (unsigned int)val);
                std::cout << "  R" << std::setw(2) << i << " = " << std::setw(10) << std::dec << val 
                          << " (0x" << hex_buf << ")  ";
                if ((i + 1) % 2 == 0 || i == 31) std::cout << std::endl;
            }
        }
    } else {
        for (int r : regs_to_show) {
            if (r >= 0 && r < 32) {
                uint32_t val = top->rootp->testbench__DOT__registers[r];
                char hex_buf[16];
                sprintf(hex_buf, "%08x", (unsigned int)val);
                std::cout << "  R" << std::setw(2) << r << " = " << std::setw(10) << std::dec << val 
                          << " (0x" << hex_buf << ")";
                if ((r + 1) % 2 == 0) std::cout << std::endl;
                else std::cout << " │ ";
            }
        }
        if (regs_to_show.size() % 2 != 0) std::cout << std::endl;
    }
}

void printHeader(const std::string& title) {
    std::cout << "\n" << std::string(60, '-') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(60, '-') << std::endl;
}

// Decodifica e stampa info dettagliate dell'istruzione
void printInstructionDetails(uint32_t instr) {
    if (instr == 0 || instr == 0xFFFFFFFF) return;
    
    // Decodifica immediata grazie alla regolarità del formato
    DecodedInst d;
    d.opcode = instr & 0x7F;
    d.rd     = (instr >> 7) & 0x1F;
    d.funct3 = (instr >> 12) & 0x7;
    d.rs1    = (instr >> 15) & 0x1F;
    d.rs2    = (instr >> 20) & 0x1F;
    d.funct7 = (instr >> 25) & 0x7F;
    d.imm    = (int32_t)instr >> 20; // Semplificato per I-type
    
    std::cout << "│   Binario: " << std::bitset<32>(instr).to_string() << std::endl;
    std::cout << "│   Hex:     0x" << std::hex << std::setw(8) << std::setfill('0') << instr << std::dec << std::endl;
    
    if (d.opcode == 0b0110011) {  // R-type
        std::cout << "│   Tipo:    R-type (Register-Register)" << std::endl;
        std::cout << "│   Opcode:  0x" << std::hex << (int)d.opcode << std::dec << " (0110011)" << std::endl;
        std::cout << "│   Funct7:  0x" << std::hex << (int)d.funct7 << std::dec << std::setfill(' ');
        std::cout << "  Funct3: 0x" << std::hex << (int)d.funct3 << std::dec << std::endl;
        std::cout << "│   rd=" << (int)d.rd << ", rs1=" << (int)d.rs1 << ", rs2=" << (int)d.rs2 << std::endl;
    } 
    else if (d.opcode == 0b0010011) {  // I-type
        std::cout << "│   Tipo:    I-type (Register-Immediate)" << std::endl;
        std::cout << "│   Opcode:  0x" << std::hex << (int)d.opcode << std::dec << " (0010011)" << std::endl;
        std::cout << "│   Funct3:  0x" << std::hex << (int)d.funct3 << std::dec << std::endl;
        std::cout << "│   rd=" << (int)d.rd << ", rs1=" << (int)d.rs1 << ", imm=" << d.imm << std::endl;
    }
    else {
        std::cout << "│   Tipo:    Sconosciuto" << std::endl;
        std::cout << "│   Opcode:  0x" << std::hex << (int)d.opcode << std::dec << std::endl;
    }
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtestbench* top = new Vtestbench;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("trace.vcd");

    printHeader("SIMULATORE CPU RISC-V RV32I - ESECUTORE ASSEMBLY");
    
    std::cout << "\nMODALITA':" << std::endl;
    std::cout << "  1 = Assembly Interattivo (Scrivi direttamente le istruzioni)" << std::endl;
    std::cout << "  2 = Da File (Carica da un file .asm)" << std::endl;
    std::cout << "\nScelta (1-2): ";
    
    int mode;
    std::cin >> mode;
    std::cin.ignore();
    
    std::vector<std::pair<uint32_t, std::string>> program;
    
    if (mode == 1) {
        printHeader("EDITOR ASSEMBLY INTERATTIVO");
        std::cout << "Formato istruzioni:" << std::endl;
        std::cout << "  LI R1, 42         (Carica immediato)" << std::endl;
        std::cout << "  ADD R3, R1, R2    (Somma)" << std::endl;
        std::cout << "  SUB R3, R1, R2    (Sottrazione)" << std::endl;
        std::cout << "  AND R3, R1, R2    (AND logico)" << std::endl;
        std::cout << "  OR R3, R1, R2     (OR logico)" << std::endl;
        std::cout << "  XOR R3, R1, R2    (XOR logico)" << std::endl;
        std::cout << "  NOP               (Nessuna operazione)" << std::endl;
        std::cout << "  END / HALT        (Termina programma)" << std::endl;
        std::cout << "\nScrivi '#' per commentare una riga" << std::endl;
        std::cout << "Scrivi le istruzioni (una per riga, END per terminare):\n" << std::endl;
        
        std::string line;
        while (std::getline(std::cin, line)) {
            // Trim whitespace
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
            
            if (line.empty() || line[0] == '#') continue;
            if (line == "END" || line == "end" || line == "HALT" || line == "halt") break;
            
            std::string logMsg;
            uint32_t instr = parseAssembly(line, logMsg);
            program.push_back({instr, logMsg});
        }
    }
    
    if (program.empty()) {
        std::cout << "\n❌ Nessuna istruzione inserita!" << std::endl;
        return 0;
    }
    
    // Reset
    top->reset = 1;
    top->clk = 0;
    
    for (int i = 0; i < 2; i++) {
        top->clk = 0;
        top->eval();
        tfp->dump(i*2);
        top->clk = 1;
        top->eval();
        tfp->dump(i*2 + 1);
    }
    
    top->reset = 0;
    
    printHeader("ESECUZIONE PROGRAMMA");
    std::cout << "Programma caricato: " << program.size() << " istruzioni\n" << std::endl;
    
    // Esecuzione con log dettagliati
    for (int instr_idx = 0; instr_idx < (int)program.size(); instr_idx++) {
        uint32_t instr = program[instr_idx].first;
        if (instr == 0xFFFFFFFF) break; // HALT condition

        std::string logMsg = program[instr_idx].second;
        
        // Salva stati iniziali
        std::vector<uint32_t> regs_before(32);
        for (int i = 0; i < 32; i++) {
            regs_before[i] = top->rootp->testbench__DOT__registers[i];
        }
        
        // Esegui per 2 cicli di clock
        top->instruction = instr;
        
        for (int cycle = 0; cycle < 2; cycle++) {
            top->clk = 0;
            top->eval();
            tfp->dump(instr_idx * 4 + cycle * 2 + 4);
            
            top->clk = 1;
            top->eval();
            tfp->dump(instr_idx * 4 + cycle * 2 + 5);
        }
        
        // Log esecuzione
        std::cout << "┌─ Istruzione " << (instr_idx + 1) << " ─────────────────────────────┐" << std::endl;
        std::cout << "│ " << std::left << std::setw(56) << logMsg << "│" << std::endl;
        
        // Mostra dettagli istruzione (opcode, formato, campi)
        printInstructionDetails(instr);
        
        // Mostra registri che sono cambiati
        bool any_changed = false;
        for (int i = 0; i < 32; i++) {
            uint32_t val_after = top->rootp->testbench__DOT__registers[i];
            if (regs_before[i] != val_after) {
                if (!any_changed) {
                    std::cout << "├─ Modifiche:" << std::endl;
                    any_changed = true;
                }
                std::cout << "│   R" << std::setw(2) << i << ": " << std::setw(10) << std::dec 
                          << regs_before[i] << " → " << std::setw(10) << val_after << std::endl;
            }
        }
        
        if (!any_changed) {
            std::cout << "├─ Nessuna modifica ai registri" << std::endl;
        }
        
        std::cout << "└─────────────────────────────────────────────────────┘" << std::endl;
    }
    
    // Risultato finale - stampa SEMPRE, anche se vuota
    printHeader("STATO FINALE REGISTRI");
    std::cout << "\nTutti i registri:\n" << std::endl;
    printRegisters(top);
    
    std::cout << "\n" << std::string(60, '-') << std::endl;

    tfp->close();
    delete top;
    delete tfp;
    
    std::cout << "\n✓ Simulazione completata!" << std::endl;
    std::cout << "✓ Log VCD salvato in: trace.vcd" << std::endl;
    std::cout << std::string(60, '-') << std::endl << std::endl;
    
    return 0;
}