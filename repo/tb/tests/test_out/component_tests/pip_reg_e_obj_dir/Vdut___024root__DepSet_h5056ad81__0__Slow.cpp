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
    vlSelf->clr_i = VL_RAND_RESET_I(1);
    vlSelf->en_i = VL_RAND_RESET_I(1);
    vlSelf->RegWriteD_i = VL_RAND_RESET_I(1);
    vlSelf->RegWriteE_o = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcD_i = VL_RAND_RESET_I(2);
    vlSelf->ResultSrcE_o = VL_RAND_RESET_I(2);
    vlSelf->MemWriteD_i = VL_RAND_RESET_I(1);
    vlSelf->MemWriteE_o = VL_RAND_RESET_I(1);
    vlSelf->JumpD_i = VL_RAND_RESET_I(1);
    vlSelf->JumpE_o = VL_RAND_RESET_I(1);
    vlSelf->BranchD_i = VL_RAND_RESET_I(1);
    vlSelf->BranchE_o = VL_RAND_RESET_I(1);
    vlSelf->ALUControlD_i = VL_RAND_RESET_I(4);
    vlSelf->ALUControlE_o = VL_RAND_RESET_I(4);
    vlSelf->ALUSrcAD_i = VL_RAND_RESET_I(1);
    vlSelf->ALUSrcAE_o = VL_RAND_RESET_I(1);
    vlSelf->funct3D_i = VL_RAND_RESET_I(3);
    vlSelf->funct3E_o = VL_RAND_RESET_I(3);
    vlSelf->ALUSrcD_i = VL_RAND_RESET_I(1);
    vlSelf->ALUSrcE_o = VL_RAND_RESET_I(1);
    vlSelf->RD1D_i = VL_RAND_RESET_I(32);
    vlSelf->RD1E_o = VL_RAND_RESET_I(32);
    vlSelf->RD2D_i = VL_RAND_RESET_I(32);
    vlSelf->RD2E_o = VL_RAND_RESET_I(32);
    vlSelf->PCD_i = VL_RAND_RESET_I(32);
    vlSelf->PCE_o = VL_RAND_RESET_I(32);
    vlSelf->Rs1D_i = VL_RAND_RESET_I(5);
    vlSelf->Rs1E_o = VL_RAND_RESET_I(5);
    vlSelf->Rs2D_i = VL_RAND_RESET_I(5);
    vlSelf->Rs2E_o = VL_RAND_RESET_I(5);
    vlSelf->RdD_i = VL_RAND_RESET_I(5);
    vlSelf->RdE_o = VL_RAND_RESET_I(5);
    vlSelf->ImmExtD_i = VL_RAND_RESET_I(32);
    vlSelf->ImmExtE_o = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4D_i = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4E_o = VL_RAND_RESET_I(32);
}
