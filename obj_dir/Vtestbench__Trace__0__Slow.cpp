// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtestbench__Syms.h"


VL_ATTR_COLD void Vtestbench___024root__trace_init_sub__TOP__0(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("testbench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+33,0,"cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+69,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+71,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+73,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"reg_data1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"reg_data2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"immediate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"alu_operand_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+81,0,"zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+74,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+78,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+81,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("CU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+68,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("PC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+82,0,"next_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("RF", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+66,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+71,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+78,0,"write_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"read_data1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"read_data2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers_out", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("registers", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+34+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtestbench___024root__trace_init_top(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_init_top\n"); );
    // Body
    Vtestbench___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtestbench___024root__trace_register(Vtestbench___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtestbench___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtestbench___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtestbench___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtestbench___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtestbench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_const_0\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtestbench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0\n"); );
    // Init
    Vtestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtestbench___024root*>(voidSelf);
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtestbench___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtestbench___024root__trace_full_0_sub_0(Vtestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->testbench__DOT__registers[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->testbench__DOT__registers[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->testbench__DOT__registers[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->testbench__DOT__registers[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->testbench__DOT__registers[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->testbench__DOT__registers[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->testbench__DOT__registers[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->testbench__DOT__registers[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->testbench__DOT__registers[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->testbench__DOT__registers[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->testbench__DOT__registers[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->testbench__DOT__registers[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->testbench__DOT__registers[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->testbench__DOT__registers[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->testbench__DOT__registers[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->testbench__DOT__registers[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->testbench__DOT__registers[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->testbench__DOT__registers[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->testbench__DOT__registers[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->testbench__DOT__registers[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->testbench__DOT__registers[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->testbench__DOT__registers[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->testbench__DOT__registers[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->testbench__DOT__registers[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->testbench__DOT__registers[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->testbench__DOT__registers[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->testbench__DOT__registers[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->testbench__DOT__registers[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->testbench__DOT__registers[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->testbench__DOT__registers[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->testbench__DOT__registers[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->testbench__DOT__registers[31]),32);
    bufp->fullIData(oldp+33,(vlSelf->testbench__DOT__cycle),32);
    bufp->fullIData(oldp+34,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[0]),32);
    bufp->fullIData(oldp+35,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[1]),32);
    bufp->fullIData(oldp+36,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[2]),32);
    bufp->fullIData(oldp+37,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[3]),32);
    bufp->fullIData(oldp+38,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[4]),32);
    bufp->fullIData(oldp+39,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[5]),32);
    bufp->fullIData(oldp+40,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[6]),32);
    bufp->fullIData(oldp+41,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[7]),32);
    bufp->fullIData(oldp+42,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[8]),32);
    bufp->fullIData(oldp+43,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[9]),32);
    bufp->fullIData(oldp+44,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[10]),32);
    bufp->fullIData(oldp+45,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[11]),32);
    bufp->fullIData(oldp+46,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[12]),32);
    bufp->fullIData(oldp+47,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[13]),32);
    bufp->fullIData(oldp+48,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[14]),32);
    bufp->fullIData(oldp+49,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[15]),32);
    bufp->fullIData(oldp+50,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[16]),32);
    bufp->fullIData(oldp+51,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[17]),32);
    bufp->fullIData(oldp+52,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[18]),32);
    bufp->fullIData(oldp+53,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[19]),32);
    bufp->fullIData(oldp+54,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[20]),32);
    bufp->fullIData(oldp+55,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[21]),32);
    bufp->fullIData(oldp+56,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[22]),32);
    bufp->fullIData(oldp+57,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[23]),32);
    bufp->fullIData(oldp+58,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[24]),32);
    bufp->fullIData(oldp+59,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[25]),32);
    bufp->fullIData(oldp+60,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[26]),32);
    bufp->fullIData(oldp+61,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[27]),32);
    bufp->fullIData(oldp+62,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[28]),32);
    bufp->fullIData(oldp+63,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[29]),32);
    bufp->fullIData(oldp+64,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[30]),32);
    bufp->fullIData(oldp+65,(vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[31]),32);
    bufp->fullBit(oldp+66,(vlSelf->clk));
    bufp->fullBit(oldp+67,(vlSelf->reset));
    bufp->fullIData(oldp+68,(vlSelf->instruction),32);
    bufp->fullIData(oldp+69,(vlSelf->testbench__DOT__cpu__DOT__pc),32);
    bufp->fullCData(oldp+70,((0x1fU & (vlSelf->instruction 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+71,((0x1fU & (vlSelf->instruction 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+72,((0x1fU & (vlSelf->instruction 
                                       >> 7U))),5);
    bufp->fullCData(oldp+73,((0x7fU & vlSelf->instruction)),7);
    bufp->fullIData(oldp+74,(vlSelf->testbench__DOT__cpu__DOT__reg_data1),32);
    bufp->fullIData(oldp+75,(((0U == (0x1fU & (vlSelf->instruction 
                                               >> 0x14U)))
                               ? 0U : vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
                              [(0x1fU & (vlSelf->instruction 
                                         >> 0x14U))])),32);
    bufp->fullIData(oldp+76,((((- (IData)((vlSelf->instruction 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->instruction 
                                           >> 0x14U))),32);
    bufp->fullIData(oldp+77,(vlSelf->testbench__DOT__cpu__DOT__alu_operand_b),32);
    bufp->fullIData(oldp+78,(((8U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                               ? 0U : ((4U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                        ? ((2U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                            ? 0U : 
                                           ((1U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                             ? 0U : 
                                            (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                             ^ vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)))
                                        : ((2U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                            ? ((1U 
                                                & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                ? (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                   | vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                                : (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                   & vlSelf->testbench__DOT__cpu__DOT__alu_operand_b))
                                            : ((1U 
                                                & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                ? (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                   - vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                                : (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                   + vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)))))),32);
    bufp->fullBit(oldp+79,(vlSelf->testbench__DOT__cpu__DOT__reg_write));
    bufp->fullCData(oldp+80,(vlSelf->testbench__DOT__cpu__DOT__alu_op),4);
    bufp->fullBit(oldp+81,((0U == ((8U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                    ? 0U : ((4U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                             ? ((2U 
                                                 & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                  ^ vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)))
                                             : ((2U 
                                                 & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                  ? 
                                                 (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                  | vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                                  : 
                                                 (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                  & vlSelf->testbench__DOT__cpu__DOT__alu_operand_b))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                                  ? 
                                                 (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                  - vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                                  : 
                                                 (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                                  + vlSelf->testbench__DOT__cpu__DOT__alu_operand_b))))))));
    bufp->fullIData(oldp+82,(((IData)(1U) + vlSelf->testbench__DOT__cpu__DOT__pc)),32);
}
