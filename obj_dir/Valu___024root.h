// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu.h for the primary calling header

#ifndef VERILATED_VALU___024ROOT_H_
#define VERILATED_VALU___024ROOT_H_  // guard

#include "verilated.h"


class Valu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Valu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ testbench__DOT__cpu__DOT__reg_write;
    CData/*3:0*/ testbench__DOT__cpu__DOT__alu_op;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(instruction,31,0);
    IData/*31:0*/ testbench__DOT__cycle;
    IData/*31:0*/ testbench__DOT__cpu__DOT__reg_data1;
    IData/*31:0*/ testbench__DOT__cpu__DOT__alu_operand_b;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> testbench__DOT__registers;
    VlUnpacked<IData/*31:0*/, 32> testbench__DOT__cpu__DOT__RF__DOT__registers;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Valu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Valu___024root(Valu__Syms* symsp, const char* v__name);
    ~Valu___024root();
    VL_UNCOPYABLE(Valu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
