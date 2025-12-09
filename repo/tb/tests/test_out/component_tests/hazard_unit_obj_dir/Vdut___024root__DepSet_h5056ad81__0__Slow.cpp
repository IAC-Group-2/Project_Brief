// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
}

void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
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
    vlSelf->Rs1D_i = VL_RAND_RESET_I(5);
    vlSelf->Rs2D_i = VL_RAND_RESET_I(5);
    vlSelf->Rs1E_i = VL_RAND_RESET_I(5);
    vlSelf->Rs2E_i = VL_RAND_RESET_I(5);
    vlSelf->RdE_i = VL_RAND_RESET_I(5);
    vlSelf->ResultSrcE0_i = VL_RAND_RESET_I(1);
    vlSelf->RdM_i = VL_RAND_RESET_I(5);
    vlSelf->RegWriteM_i = VL_RAND_RESET_I(1);
    vlSelf->RdW_i = VL_RAND_RESET_I(5);
    vlSelf->RegWriteW_i = VL_RAND_RESET_I(1);
    vlSelf->PCSrcE_i = VL_RAND_RESET_I(1);
    vlSelf->CacheStall_i = VL_RAND_RESET_I(1);
    vlSelf->ForwardAE_o = VL_RAND_RESET_I(2);
    vlSelf->ForwardBE_o = VL_RAND_RESET_I(2);
    vlSelf->StallF_o = VL_RAND_RESET_I(1);
    vlSelf->StallD_o = VL_RAND_RESET_I(1);
    vlSelf->StallE_o = VL_RAND_RESET_I(1);
    vlSelf->StallM_o = VL_RAND_RESET_I(1);
    vlSelf->StallW_o = VL_RAND_RESET_I(1);
    vlSelf->FlushD_o = VL_RAND_RESET_I(1);
    vlSelf->FlushE_o = VL_RAND_RESET_I(1);
    vlSelf->hazard_unit__DOT__lwStall = VL_RAND_RESET_I(1);
}
