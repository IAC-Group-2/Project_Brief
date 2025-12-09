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
    vlSelf->BranchTaken_o = (1U & ((4U & (IData)(vlSelf->funct3_i))
                                    ? ((2U & (IData)(vlSelf->funct3_i))
                                        ? ((1U & (IData)(vlSelf->funct3_i))
                                            ? (vlSelf->SrcA_i 
                                               >= vlSelf->SrcB_i)
                                            : (vlSelf->SrcA_i 
                                               < vlSelf->SrcB_i))
                                        : ((1U & (IData)(vlSelf->funct3_i))
                                            ? VL_GTES_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i)
                                            : VL_LTS_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i)))
                                    : ((~ ((IData)(vlSelf->funct3_i) 
                                           >> 1U)) 
                                       & ((1U & (IData)(vlSelf->funct3_i))
                                           ? (~ (IData)(vlSelf->Zero_i))
                                           : (IData)(vlSelf->Zero_i)))));
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
    if (VL_UNLIKELY((vlSelf->funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
    if (VL_UNLIKELY((vlSelf->Zero_i & 0xfeU))) {
        Verilated::overWidthError("Zero_i");}
}
#endif  // VL_DEBUG
