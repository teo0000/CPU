// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench__pch.h"
#include "Vtestbench___024root.h"

VL_ATTR_COLD void Vtestbench___024root___eval_static(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtestbench___024root___eval_initial(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vtestbench___024root___eval_final(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__stl(Vtestbench___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtestbench___024root___eval_phase__stl(Vtestbench___024root* vlSelf);

VL_ATTR_COLD void Vtestbench___024root___eval_settle(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtestbench___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("testbench.v", 30, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtestbench___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__stl(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestbench___024root___stl_sequent__TOP__0(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->testbench__DOT__cpu__DOT__alu_op = ((0x40U 
                                                 & vlSelf->instruction)
                                                 ? 0U
                                                 : 
                                                ((0x20U 
                                                  & vlSelf->instruction)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelf->instruction)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->instruction)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->instruction)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->instruction)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->instruction)
                                                       ? 
                                                      ((0x4000U 
                                                        & vlSelf->instruction)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlSelf->instruction)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlSelf->instruction)
                                                          ? 2U
                                                          : 3U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlSelf->instruction)
                                                          ? 0U
                                                          : 4U))
                                                        : 
                                                       ((0x2000U 
                                                         & vlSelf->instruction)
                                                         ? 0U
                                                         : 
                                                        ((0x1000U 
                                                          & vlSelf->instruction)
                                                          ? 0U
                                                          : 
                                                         ((0x40000000U 
                                                           & vlSelf->instruction)
                                                           ? 1U
                                                           : 0U))))
                                                       : 0U)
                                                      : 0U)))
                                                   : 0U)
                                                  : 0U));
    vlSelf->testbench__DOT__cpu__DOT__reg_write = (
                                                   (1U 
                                                    & (~ 
                                                       (vlSelf->instruction 
                                                        >> 6U))) 
                                                   && ((0x20U 
                                                        & vlSelf->instruction)
                                                        ? 
                                                       ((1U 
                                                         & (vlSelf->instruction 
                                                            >> 4U)) 
                                                        && ((1U 
                                                             & (~ 
                                                                (vlSelf->instruction 
                                                                 >> 3U))) 
                                                            && ((1U 
                                                                 & (~ 
                                                                    (vlSelf->instruction 
                                                                     >> 2U))) 
                                                                && ((1U 
                                                                     & (vlSelf->instruction 
                                                                        >> 1U)) 
                                                                    && (1U 
                                                                        & vlSelf->instruction)))))
                                                        : 
                                                       ((0x10U 
                                                         & vlSelf->instruction)
                                                         ? 
                                                        ((1U 
                                                          & (~ 
                                                             (vlSelf->instruction 
                                                              >> 3U))) 
                                                         && ((1U 
                                                              & (~ 
                                                                 (vlSelf->instruction 
                                                                  >> 2U))) 
                                                             && ((1U 
                                                                  & (vlSelf->instruction 
                                                                     >> 1U)) 
                                                                 && (1U 
                                                                     & vlSelf->instruction))))
                                                         : 
                                                        ((1U 
                                                          & (~ 
                                                             (vlSelf->instruction 
                                                              >> 3U))) 
                                                         && ((1U 
                                                              & (~ 
                                                                 (vlSelf->instruction 
                                                                  >> 2U))) 
                                                             && ((1U 
                                                                  & (vlSelf->instruction 
                                                                     >> 1U)) 
                                                                 && (1U 
                                                                     & vlSelf->instruction)))))));
    vlSelf->testbench__DOT__cpu__DOT____Vcellinp__PC__next_pc 
        = ((IData)(1U) + vlSelf->testbench__DOT__cpu__DOT__pc);
    vlSelf->testbench__DOT__cpu__DOT__alu_operand_b 
        = ((0x13U == (0x7fU & vlSelf->instruction))
            ? (((- (IData)((vlSelf->instruction >> 0x1fU))) 
                << 0xcU) | (vlSelf->instruction >> 0x14U))
            : ((0U == (0x1fU & (vlSelf->instruction 
                                >> 0x14U))) ? 0U : 
               vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
               [(0x1fU & (vlSelf->instruction >> 0x14U))]));
    vlSelf->testbench__DOT__cpu__DOT__reg_data1 = (
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->instruction 
                                                        >> 0xfU)))
                                                    ? 0U
                                                    : 
                                                   vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->instruction 
                                                       >> 0xfU))]);
    vlSelf->testbench__DOT__registers[0x1fU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1fU];
    vlSelf->testbench__DOT__registers[0x1eU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1eU];
    vlSelf->testbench__DOT__registers[0x1dU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1dU];
    vlSelf->testbench__DOT__registers[0x1cU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1cU];
    vlSelf->testbench__DOT__registers[0x1bU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1bU];
    vlSelf->testbench__DOT__registers[0x1aU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x1aU];
    vlSelf->testbench__DOT__registers[0x19U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x19U];
    vlSelf->testbench__DOT__registers[0x18U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x18U];
    vlSelf->testbench__DOT__registers[0x17U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x17U];
    vlSelf->testbench__DOT__registers[0x16U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x16U];
    vlSelf->testbench__DOT__registers[0x15U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x15U];
    vlSelf->testbench__DOT__registers[0x14U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x14U];
    vlSelf->testbench__DOT__registers[0x13U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x13U];
    vlSelf->testbench__DOT__registers[0x12U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x12U];
    vlSelf->testbench__DOT__registers[0x11U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x11U];
    vlSelf->testbench__DOT__registers[0x10U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0x10U];
    vlSelf->testbench__DOT__registers[0xfU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xfU];
    vlSelf->testbench__DOT__registers[0xeU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xeU];
    vlSelf->testbench__DOT__registers[0xdU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xdU];
    vlSelf->testbench__DOT__registers[0xcU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xcU];
    vlSelf->testbench__DOT__registers[0xbU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xbU];
    vlSelf->testbench__DOT__registers[0xaU] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0xaU];
    vlSelf->testbench__DOT__registers[9U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [9U];
    vlSelf->testbench__DOT__registers[8U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [8U];
    vlSelf->testbench__DOT__registers[7U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [7U];
    vlSelf->testbench__DOT__registers[6U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [6U];
    vlSelf->testbench__DOT__registers[5U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [5U];
    vlSelf->testbench__DOT__registers[4U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [4U];
    vlSelf->testbench__DOT__registers[3U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [3U];
    vlSelf->testbench__DOT__registers[2U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [2U];
    vlSelf->testbench__DOT__registers[1U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [1U];
    vlSelf->testbench__DOT__registers[0U] = vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers
        [0U];
}

VL_ATTR_COLD void Vtestbench___024root___eval_stl(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtestbench___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtestbench___024root___eval_triggers__stl(Vtestbench___024root* vlSelf);

VL_ATTR_COLD bool Vtestbench___024root___eval_phase__stl(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtestbench___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtestbench___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__ico(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__act(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtestbench___024root___dump_triggers__nba(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtestbench___024root___ctor_var_reset(Vtestbench___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->instruction = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->testbench__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->testbench__DOT__cycle = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__cpu__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__cpu__DOT__reg_data1 = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__cpu__DOT__alu_operand_b = VL_RAND_RESET_I(32);
    vlSelf->testbench__DOT__cpu__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->testbench__DOT__cpu__DOT__alu_op = VL_RAND_RESET_I(4);
    vlSelf->testbench__DOT__cpu__DOT____Vcellinp__PC__next_pc = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
