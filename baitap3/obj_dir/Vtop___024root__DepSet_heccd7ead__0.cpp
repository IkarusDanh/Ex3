// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vdly__top__DOT__sum_module__DOT__state;
    CData/*7:0*/ __Vdly__top__DOT__sum_module__DOT__get_n;
    CData/*7:0*/ __Vdly__top__DOT__sum_module__DOT__get_sum;
    // Body
    __Vdly__top__DOT__sum_module__DOT__get_sum = vlSelf->top__DOT__sum_module__DOT__get_sum;
    __Vdly__top__DOT__sum_module__DOT__get_n = vlSelf->top__DOT__sum_module__DOT__get_n;
    __Vdly__top__DOT__sum_module__DOT__state = vlSelf->top__DOT__sum_module__DOT__state;
    if (vlSelf->rst_ni) {
        if ((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__state))) {
            if (vlSelf->start_i) {
                __Vdly__top__DOT__sum_module__DOT__state = 1U;
                __Vdly__top__DOT__sum_module__DOT__get_n 
                    = vlSelf->n_i;
            } else {
                __Vdly__top__DOT__sum_module__DOT__state = 0U;
            }
        } else if ((1U == (IData)(vlSelf->top__DOT__sum_module__DOT__state))) {
            if (((IData)(vlSelf->top__DOT__sum_module__DOT__counter) 
                 < (IData)(vlSelf->top__DOT__sum_module__DOT__get_n))) {
                __Vdly__top__DOT__sum_module__DOT__get_sum 
                    = (0xffU & ((IData)(vlSelf->top__DOT__sum_module__DOT__get_sum) 
                                + (IData)(vlSelf->data_i)));
                vlSelf->top__DOT__sum_module__DOT__counter 
                    = (0xffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__sum_module__DOT__counter)));
                __Vdly__top__DOT__sum_module__DOT__state = 1U;
            } else {
                __Vdly__top__DOT__sum_module__DOT__state = 2U;
            }
        } else if ((2U == (IData)(vlSelf->top__DOT__sum_module__DOT__state))) {
            vlSelf->sum_o = vlSelf->top__DOT__sum_module__DOT__get_sum;
            vlSelf->done_o = 1U;
        } else {
            vlSelf->sum_o = 0U;
            vlSelf->done_o = 0U;
        }
    } else {
        vlSelf->sum_o = 0U;
        vlSelf->done_o = 0U;
    }
    vlSelf->top__DOT__sum_module__DOT__state = __Vdly__top__DOT__sum_module__DOT__state;
    vlSelf->top__DOT__sum_module__DOT__get_n = __Vdly__top__DOT__sum_module__DOT__get_n;
    vlSelf->top__DOT__sum_module__DOT__get_sum = __Vdly__top__DOT__sum_module__DOT__get_sum;
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->start_i & 0xfeU))) {
        Verilated::overWidthError("start_i");}
}
#endif  // VL_DEBUG
