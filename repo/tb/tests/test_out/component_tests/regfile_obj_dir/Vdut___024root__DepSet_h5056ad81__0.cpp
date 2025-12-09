// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__regfile__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__regfile__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__regfile__DOT__mem__v0;
    // Body
    __Vdlyvset__regfile__DOT__mem__v0 = 0U;
    if (((IData)(vlSelf->WE3_i) & (0U != (IData)(vlSelf->A3_i)))) {
        __Vdlyvval__regfile__DOT__mem__v0 = vlSelf->WD3_i;
        __Vdlyvset__regfile__DOT__mem__v0 = 1U;
        __Vdlyvdim0__regfile__DOT__mem__v0 = vlSelf->A3_i;
    }
    if (__Vdlyvset__regfile__DOT__mem__v0) {
        vlSelf->regfile__DOT__mem[__Vdlyvdim0__regfile__DOT__mem__v0] 
            = __Vdlyvval__regfile__DOT__mem__v0;
    }
    vlSelf->A0_o = vlSelf->regfile__DOT__mem[0xaU];
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->RD1_o = ((0U == (IData)(vlSelf->A1_i)) ? 0U
                      : vlSelf->regfile__DOT__mem[vlSelf->A1_i]);
    vlSelf->RD2_o = ((0U == (IData)(vlSelf->A2_i)) ? 0U
                      : vlSelf->regfile__DOT__mem[vlSelf->A2_i]);
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vdut___024root___combo__TOP__0(vlSelf);
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
    if (VL_UNLIKELY((vlSelf->A1_i & 0xe0U))) {
        Verilated::overWidthError("A1_i");}
    if (VL_UNLIKELY((vlSelf->A2_i & 0xe0U))) {
        Verilated::overWidthError("A2_i");}
    if (VL_UNLIKELY((vlSelf->A3_i & 0xe0U))) {
        Verilated::overWidthError("A3_i");}
    if (VL_UNLIKELY((vlSelf->WE3_i & 0xfeU))) {
        Verilated::overWidthError("WE3_i");}
}
#endif  // VL_DEBUG
