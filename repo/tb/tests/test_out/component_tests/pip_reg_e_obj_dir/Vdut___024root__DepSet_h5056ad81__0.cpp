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
    if (vlSelf->clr_i) {
        vlSelf->ALUSrcAE_o = 0U;
        vlSelf->PCPlus4E_o = 0U;
        vlSelf->ImmExtE_o = 0U;
        vlSelf->RdE_o = 0U;
        vlSelf->Rs2E_o = 0U;
        vlSelf->Rs1E_o = 0U;
        vlSelf->funct3E_o = 0U;
        vlSelf->RegWriteE_o = 0U;
        vlSelf->ResultSrcE_o = 0U;
        vlSelf->MemWriteE_o = 0U;
        vlSelf->JumpE_o = 0U;
        vlSelf->BranchE_o = 0U;
        vlSelf->ALUControlE_o = 0U;
        vlSelf->ALUSrcE_o = 0U;
        vlSelf->RD1E_o = 0U;
        vlSelf->RD2E_o = 0U;
        vlSelf->PCE_o = 0U;
    } else if (vlSelf->en_i) {
        vlSelf->PCPlus4E_o = vlSelf->PCPlus4D_i;
        vlSelf->ImmExtE_o = vlSelf->ImmExtD_i;
        vlSelf->RdE_o = vlSelf->RdD_i;
        vlSelf->Rs2E_o = vlSelf->Rs2D_i;
        vlSelf->Rs1E_o = vlSelf->Rs1D_i;
        vlSelf->funct3E_o = vlSelf->funct3D_i;
        vlSelf->RegWriteE_o = vlSelf->RegWriteD_i;
        vlSelf->ResultSrcE_o = vlSelf->ResultSrcD_i;
        vlSelf->MemWriteE_o = vlSelf->MemWriteD_i;
        vlSelf->JumpE_o = vlSelf->JumpD_i;
        vlSelf->BranchE_o = vlSelf->BranchD_i;
        vlSelf->ALUControlE_o = vlSelf->ALUControlD_i;
        vlSelf->ALUSrcE_o = vlSelf->ALUSrcD_i;
        vlSelf->RD1E_o = vlSelf->RD1D_i;
        vlSelf->RD2E_o = vlSelf->RD2D_i;
        vlSelf->PCE_o = vlSelf->PCD_i;
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
    if (VL_UNLIKELY((vlSelf->clr_i & 0xfeU))) {
        Verilated::overWidthError("clr_i");}
    if (VL_UNLIKELY((vlSelf->en_i & 0xfeU))) {
        Verilated::overWidthError("en_i");}
    if (VL_UNLIKELY((vlSelf->RegWriteD_i & 0xfeU))) {
        Verilated::overWidthError("RegWriteD_i");}
    if (VL_UNLIKELY((vlSelf->ResultSrcD_i & 0xfcU))) {
        Verilated::overWidthError("ResultSrcD_i");}
    if (VL_UNLIKELY((vlSelf->MemWriteD_i & 0xfeU))) {
        Verilated::overWidthError("MemWriteD_i");}
    if (VL_UNLIKELY((vlSelf->JumpD_i & 0xfeU))) {
        Verilated::overWidthError("JumpD_i");}
    if (VL_UNLIKELY((vlSelf->BranchD_i & 0xfeU))) {
        Verilated::overWidthError("BranchD_i");}
    if (VL_UNLIKELY((vlSelf->ALUControlD_i & 0xf0U))) {
        Verilated::overWidthError("ALUControlD_i");}
    if (VL_UNLIKELY((vlSelf->ALUSrcAD_i & 0xfeU))) {
        Verilated::overWidthError("ALUSrcAD_i");}
    if (VL_UNLIKELY((vlSelf->funct3D_i & 0xf8U))) {
        Verilated::overWidthError("funct3D_i");}
    if (VL_UNLIKELY((vlSelf->ALUSrcD_i & 0xfeU))) {
        Verilated::overWidthError("ALUSrcD_i");}
    if (VL_UNLIKELY((vlSelf->Rs1D_i & 0xe0U))) {
        Verilated::overWidthError("Rs1D_i");}
    if (VL_UNLIKELY((vlSelf->Rs2D_i & 0xe0U))) {
        Verilated::overWidthError("Rs2D_i");}
    if (VL_UNLIKELY((vlSelf->RdD_i & 0xe0U))) {
        Verilated::overWidthError("RdD_i");}
}
#endif  // VL_DEBUG
