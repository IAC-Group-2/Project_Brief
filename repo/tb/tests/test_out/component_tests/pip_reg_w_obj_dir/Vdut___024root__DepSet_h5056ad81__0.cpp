// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->en_i) {
        vlSelf->PCPlus4W_o = vlSelf->PCPlus4M_i;
        vlSelf->RdW_o = vlSelf->RdM_i;
        vlSelf->ReadDataW_o = vlSelf->ReadDataM_i;
        vlSelf->ALUResultW_o = vlSelf->ALUResultM_i;
        vlSelf->ResultSrcW_o = vlSelf->ResultSrcM_i;
        vlSelf->RegWriteW_o = vlSelf->RegWriteM_i;
    }
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->en_i & 0xfeU))) {
        Verilated::overWidthError("en_i");}
    if (VL_UNLIKELY((vlSelf->RegWriteM_i & 0xfeU))) {
        Verilated::overWidthError("RegWriteM_i");}
    if (VL_UNLIKELY((vlSelf->ResultSrcM_i & 0xfcU))) {
        Verilated::overWidthError("ResultSrcM_i");}
    if (VL_UNLIKELY((vlSelf->RdM_i & 0xe0U))) {
        Verilated::overWidthError("RdM_i");}
}
#endif  // VL_DEBUG
