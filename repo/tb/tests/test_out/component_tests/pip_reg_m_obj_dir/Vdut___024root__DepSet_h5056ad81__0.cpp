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
        vlSelf->PCPlus4M_o = vlSelf->PCPlus4E_i;
        vlSelf->WriteDataM_o = vlSelf->WriteDataE_i;
        vlSelf->ALUResultM_o = vlSelf->ALUResultE_i;
        vlSelf->funct3M_o = vlSelf->funct3E_i;
        vlSelf->MemWriteM_o = vlSelf->MemWriteE_i;
        vlSelf->ResultSrcM_o = vlSelf->ResultSrcE_i;
        vlSelf->RegWriteM_o = vlSelf->RegWriteE_i;
        vlSelf->RdM_o = vlSelf->RdE_i;
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
    if (VL_UNLIKELY((vlSelf->RegWriteE_i & 0xfeU))) {
        Verilated::overWidthError("RegWriteE_i");}
    if (VL_UNLIKELY((vlSelf->ResultSrcE_i & 0xfcU))) {
        Verilated::overWidthError("ResultSrcE_i");}
    if (VL_UNLIKELY((vlSelf->MemWriteE_i & 0xfeU))) {
        Verilated::overWidthError("MemWriteE_i");}
    if (VL_UNLIKELY((vlSelf->funct3E_i & 0xf8U))) {
        Verilated::overWidthError("funct3E_i");}
    if (VL_UNLIKELY((vlSelf->RdE_i & 0xe0U))) {
        Verilated::overWidthError("RdE_i");}
}
#endif  // VL_DEBUG
