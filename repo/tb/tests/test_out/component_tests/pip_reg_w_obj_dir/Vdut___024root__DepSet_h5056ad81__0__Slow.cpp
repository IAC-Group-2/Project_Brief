// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

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
    vlSelf->en_i = VL_RAND_RESET_I(1);
    vlSelf->RegWriteM_i = VL_RAND_RESET_I(1);
    vlSelf->RegWriteW_o = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcM_i = VL_RAND_RESET_I(2);
    vlSelf->ResultSrcW_o = VL_RAND_RESET_I(2);
    vlSelf->ALUResultM_i = VL_RAND_RESET_I(32);
    vlSelf->ALUResultW_o = VL_RAND_RESET_I(32);
    vlSelf->ReadDataM_i = VL_RAND_RESET_I(32);
    vlSelf->ReadDataW_o = VL_RAND_RESET_I(32);
    vlSelf->RdM_i = VL_RAND_RESET_I(5);
    vlSelf->RdW_o = VL_RAND_RESET_I(5);
    vlSelf->PCPlus4M_i = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4W_o = VL_RAND_RESET_I(32);
}
