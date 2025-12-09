// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->StallE_o = 0U;
    vlSelf->StallE_o = vlSelf->CacheStall_i;
    vlSelf->StallM_o = 0U;
    vlSelf->StallM_o = vlSelf->CacheStall_i;
    vlSelf->StallW_o = 0U;
    vlSelf->StallW_o = vlSelf->CacheStall_i;
    vlSelf->FlushD_o = 0U;
    vlSelf->FlushD_o = ((~ (IData)(vlSelf->CacheStall_i)) 
                        & (IData)(vlSelf->PCSrcE_i));
    vlSelf->ForwardAE_o = 0U;
    vlSelf->ForwardAE_o = (((((IData)(vlSelf->Rs1E_i) 
                              == (IData)(vlSelf->RdM_i)) 
                             & (IData)(vlSelf->RegWriteM_i)) 
                            & (0U != (IData)(vlSelf->Rs1E_i)))
                            ? 2U : (((((IData)(vlSelf->Rs1E_i) 
                                       == (IData)(vlSelf->RdW_i)) 
                                      & (IData)(vlSelf->RegWriteW_i)) 
                                     & (0U != (IData)(vlSelf->Rs1E_i)))
                                     ? 1U : 0U));
    vlSelf->ForwardBE_o = 0U;
    vlSelf->ForwardBE_o = (((((IData)(vlSelf->Rs2E_i) 
                              == (IData)(vlSelf->RdM_i)) 
                             & (IData)(vlSelf->RegWriteM_i)) 
                            & (0U != (IData)(vlSelf->Rs2E_i)))
                            ? 2U : (((((IData)(vlSelf->Rs2E_i) 
                                       == (IData)(vlSelf->RdW_i)) 
                                      & (IData)(vlSelf->RegWriteW_i)) 
                                     & (0U != (IData)(vlSelf->Rs2E_i)))
                                     ? 1U : 0U));
    vlSelf->StallF_o = 0U;
    vlSelf->StallD_o = 0U;
    vlSelf->FlushE_o = 0U;
    vlSelf->hazard_unit__DOT__lwStall = ((IData)(vlSelf->ResultSrcE0_i) 
                                         & (((IData)(vlSelf->Rs1D_i) 
                                             == (IData)(vlSelf->RdE_i)) 
                                            | ((IData)(vlSelf->Rs2D_i) 
                                               == (IData)(vlSelf->RdE_i))));
    vlSelf->StallF_o = ((IData)(vlSelf->hazard_unit__DOT__lwStall) 
                        | (IData)(vlSelf->CacheStall_i));
    vlSelf->StallD_o = ((IData)(vlSelf->hazard_unit__DOT__lwStall) 
                        | (IData)(vlSelf->CacheStall_i));
    vlSelf->FlushE_o = ((~ (IData)(vlSelf->CacheStall_i)) 
                        & ((IData)(vlSelf->hazard_unit__DOT__lwStall) 
                           | (IData)(vlSelf->PCSrcE_i)));
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->Rs1D_i & 0xe0U))) {
        Verilated::overWidthError("Rs1D_i");}
    if (VL_UNLIKELY((vlSelf->Rs2D_i & 0xe0U))) {
        Verilated::overWidthError("Rs2D_i");}
    if (VL_UNLIKELY((vlSelf->Rs1E_i & 0xe0U))) {
        Verilated::overWidthError("Rs1E_i");}
    if (VL_UNLIKELY((vlSelf->Rs2E_i & 0xe0U))) {
        Verilated::overWidthError("Rs2E_i");}
    if (VL_UNLIKELY((vlSelf->RdE_i & 0xe0U))) {
        Verilated::overWidthError("RdE_i");}
    if (VL_UNLIKELY((vlSelf->ResultSrcE0_i & 0xfeU))) {
        Verilated::overWidthError("ResultSrcE0_i");}
    if (VL_UNLIKELY((vlSelf->RdM_i & 0xe0U))) {
        Verilated::overWidthError("RdM_i");}
    if (VL_UNLIKELY((vlSelf->RegWriteM_i & 0xfeU))) {
        Verilated::overWidthError("RegWriteM_i");}
    if (VL_UNLIKELY((vlSelf->RdW_i & 0xe0U))) {
        Verilated::overWidthError("RdW_i");}
    if (VL_UNLIKELY((vlSelf->RegWriteW_i & 0xfeU))) {
        Verilated::overWidthError("RegWriteW_i");}
    if (VL_UNLIKELY((vlSelf->PCSrcE_i & 0xfeU))) {
        Verilated::overWidthError("PCSrcE_i");}
    if (VL_UNLIKELY((vlSelf->CacheStall_i & 0xfeU))) {
        Verilated::overWidthError("CacheStall_i");}
}
#endif  // VL_DEBUG
