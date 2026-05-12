// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtestbench.h for the primary calling header

#ifndef VERILATED_VTESTBENCH___024ROOT_H_
#define VERILATED_VTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"


class Vtestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtestbench___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ testbench__DOT__cpu__DOT__reg_write;
    CData/*3:0*/ testbench__DOT__cpu__DOT__alu_op;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(instruction,31,0);
    IData/*31:0*/ testbench__DOT__cycle;
    IData/*31:0*/ testbench__DOT__cpu__DOT__pc;
    IData/*31:0*/ testbench__DOT__cpu__DOT__reg_data1;
    IData/*31:0*/ testbench__DOT__cpu__DOT__alu_operand_b;
    IData/*31:0*/ testbench__DOT__cpu__DOT____Vcellinp__PC__next_pc;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> testbench__DOT__registers;
    VlUnpacked<IData/*31:0*/, 32> testbench__DOT__cpu__DOT__RF__DOT__registers;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtestbench__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtestbench___024root(Vtestbench__Syms* symsp, const char* v__name);
    ~Vtestbench___024root();
    VL_UNCOPYABLE(Vtestbench___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
