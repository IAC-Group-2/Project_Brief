// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->A0_o = vlSelf->regfile__DOT__mem[0xaU];
    vlSelf->RD1_o = ((0U == (IData)(vlSelf->A1_i)) ? 0U
                      : vlSelf->regfile__DOT__mem[vlSelf->A1_i]);
    vlSelf->RD2_o = ((0U == (IData)(vlSelf->A2_i)) ? 0U
                      : vlSelf->regfile__DOT__mem[vlSelf->A2_i]);
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->A1_i = VL_RAND_RESET_I(5);
    vlSelf->A2_i = VL_RAND_RESET_I(5);
    vlSelf->A3_i = VL_RAND_RESET_I(5);
    vlSelf->WD3_i = VL_RAND_RESET_I(32);
    vlSelf->WE3_i = VL_RAND_RESET_I(1);
    vlSelf->RD1_o = VL_RAND_RESET_I(32);
    vlSelf->RD2_o = VL_RAND_RESET_I(32);
    vlSelf->A0_o = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->regfile__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
