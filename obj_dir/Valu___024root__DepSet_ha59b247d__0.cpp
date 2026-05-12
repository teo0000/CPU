// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu__pch.h"
#include "Valu___024root.h"

VL_INLINE_OPT void Valu___024root___ico_sequent__TOP__0(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___ico_sequent__TOP__0\n"); );
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
}

void Valu___024root___eval_ico(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Valu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Valu___024root___eval_triggers__ico(Valu___024root* vlSelf);

bool Valu___024root___eval_phase__ico(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Valu___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Valu___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Valu___024root___eval_act(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_act\n"); );
}

VL_INLINE_OPT void Valu___024root___nba_sequent__TOP__0(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__testbench__DOT__cycle;
    __Vdly__testbench__DOT__cycle = 0;
    CData/*4:0*/ __Vdlyvdim0__testbench__DOT__cpu__DOT__RF__DOT__registers__v0;
    __Vdlyvdim0__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 = 0;
    IData/*31:0*/ __Vdlyvval__testbench__DOT__cpu__DOT__RF__DOT__registers__v0;
    __Vdlyvval__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__testbench__DOT__cpu__DOT__RF__DOT__registers__v0;
    __Vdlyvset__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 = 0;
    // Body
    __Vdly__testbench__DOT__cycle = vlSelf->testbench__DOT__cycle;
    __Vdlyvset__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 = 0U;
    if (VL_UNLIKELY(vlSelf->reset)) {
        VL_WRITEF("=== Simulazione RISC-V avviata ===\n");
        __Vdly__testbench__DOT__cycle = 0U;
    } else {
        __Vdly__testbench__DOT__cycle = ((IData)(1U) 
                                         + vlSelf->testbench__DOT__cycle);
        if (VL_UNLIKELY(((0U == VL_MODDIVS_III(32, vlSelf->testbench__DOT__cycle, (IData)(5U))) 
                         & VL_LTS_III(32, 0U, vlSelf->testbench__DOT__cycle)))) {
            VL_WRITEF("Ciclo %11d:\n  R1 = %0#  R2 = %0#  R3 = %0#\n",
                      32,vlSelf->testbench__DOT__cycle,
                      32,vlSelf->testbench__DOT__registers
                      [1U],32,vlSelf->testbench__DOT__registers
                      [2U],32,vlSelf->testbench__DOT__registers
                      [3U]);
        }
    }
    if (((IData)(vlSelf->testbench__DOT__cpu__DOT__reg_write) 
         & (0U != (0x1fU & (vlSelf->instruction >> 7U))))) {
        __Vdlyvval__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 
            = ((8U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                ? 0U : ((4U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                         ? ((2U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                             ? 0U : ((1U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                      ? 0U : (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                              ^ vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)))
                         : ((2U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                             ? ((1U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                 ? (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                    | vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                 : (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                    & vlSelf->testbench__DOT__cpu__DOT__alu_operand_b))
                             : ((1U & (IData)(vlSelf->testbench__DOT__cpu__DOT__alu_op))
                                 ? (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                    - vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)
                                 : (vlSelf->testbench__DOT__cpu__DOT__reg_data1 
                                    + vlSelf->testbench__DOT__cpu__DOT__alu_operand_b)))));
        __Vdlyvset__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 = 1U;
        __Vdlyvdim0__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 
            = (0x1fU & (vlSelf->instruction >> 7U));
    }
    vlSelf->testbench__DOT__cycle = __Vdly__testbench__DOT__cycle;
    if (__Vdlyvset__testbench__DOT__cpu__DOT__RF__DOT__registers__v0) {
        vlSelf->testbench__DOT__cpu__DOT__RF__DOT__registers[__Vdlyvdim0__testbench__DOT__cpu__DOT__RF__DOT__registers__v0] 
            = __Vdlyvval__testbench__DOT__cpu__DOT__RF__DOT__registers__v0;
    }
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

void Valu___024root___eval_nba(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Valu___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Valu___024root___eval_triggers__act(Valu___024root* vlSelf);

bool Valu___024root___eval_phase__act(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Valu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Valu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Valu___024root___eval_phase__nba(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Valu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__ico(Valu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__nba(Valu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__act(Valu___024root* vlSelf);
#endif  // VL_DEBUG

void Valu___024root___eval(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Valu___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("testbench.v", 30, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Valu___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Valu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("testbench.v", 30, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Valu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("testbench.v", 30, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Valu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Valu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
