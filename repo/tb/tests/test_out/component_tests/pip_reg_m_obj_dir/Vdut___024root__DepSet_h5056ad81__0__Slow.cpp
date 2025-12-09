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
    vlSelf->RegWriteE_i = VL_RAND_RESET_I(1);
    vlSelf->RegWriteM_o = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcE_i = VL_RAND_RESET_I(2);
    vlSelf->ResultSrcM_o = VL_RAND_RESET_I(2);
    vlSelf->MemWriteE_i = VL_RAND_RESET_I(1);
    vlSelf->MemWriteM_o = VL_RAND_RESET_I(1);
    vlSelf->funct3E_i = VL_RAND_RESET_I(3);
    vlSelf->funct3M_o = VL_RAND_RESET_I(3);
    vlSelf->ALUResultE_i = VL_RAND_RESET_I(32);
    vlSelf->ALUResultM_o = VL_RAND_RESET_I(32);
    vlSelf->WriteDataE_i = VL_RAND_RESET_I(32);
    vlSelf->WriteDataM_o = VL_RAND_RESET_I(32);
    vlSelf->RdE_i = VL_RAND_RESET_I(5);
    vlSelf->RdM_o = VL_RAND_RESET_I(5);
    vlSelf->PCPlus4E_i = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4M_o = VL_RAND_RESET_I(32);
}
