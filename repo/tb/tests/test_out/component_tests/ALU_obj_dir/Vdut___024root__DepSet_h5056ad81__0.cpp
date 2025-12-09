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
    vlSelf->ALU__DOT__signed_product = VL_MULS_QQQ(64, 
                                                   VL_EXTENDS_QI(64,32, vlSelf->SrcA_i), 
                                                   VL_EXTENDS_QI(64,32, vlSelf->SrcB_i));
    vlSelf->ALUResult_o = 0U;
    vlSelf->ALUResult_o = ((8U & (IData)(vlSelf->ALUControl_i))
                            ? ((4U & (IData)(vlSelf->ALUControl_i))
                                ? ((2U & (IData)(vlSelf->ALUControl_i))
                                    ? ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? vlSelf->SrcB_i
                                        : 0U) : ((1U 
                                                  & (IData)(vlSelf->ALUControl_i))
                                                  ? (IData)(vlSelf->ALU__DOT__signed_product)
                                                  : (IData)(
                                                            (((QData)((IData)(vlSelf->SrcA_i)) 
                                                              * (QData)((IData)(vlSelf->SrcB_i))) 
                                                             >> 0x20U))))
                                : ((2U & (IData)(vlSelf->ALUControl_i))
                                    ? ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? (IData)((vlSelf->ALU__DOT__signed_product 
                                                   >> 0x20U))
                                        : (IData)(((QData)((IData)(vlSelf->SrcA_i)) 
                                                   * (QData)((IData)(vlSelf->SrcB_i)))))
                                    : ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? ((vlSelf->SrcA_i 
                                            < vlSelf->SrcB_i)
                                            ? 1U : 0U)
                                        : (VL_LTS_III(32, vlSelf->SrcA_i, vlSelf->SrcB_i)
                                            ? 1U : 0U))))
                            : ((4U & (IData)(vlSelf->ALUControl_i))
                                ? ((2U & (IData)(vlSelf->ALUControl_i))
                                    ? ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? VL_SHIFTRS_III(32,32,5, vlSelf->SrcA_i, 
                                                         (0x1fU 
                                                          & vlSelf->SrcB_i))
                                        : (vlSelf->SrcA_i 
                                           >> (0x1fU 
                                               & vlSelf->SrcB_i)))
                                    : ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? (vlSelf->SrcA_i 
                                           << (0x1fU 
                                               & vlSelf->SrcB_i))
                                        : (vlSelf->SrcA_i 
                                           ^ vlSelf->SrcB_i)))
                                : ((2U & (IData)(vlSelf->ALUControl_i))
                                    ? ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? (vlSelf->SrcA_i 
                                           | vlSelf->SrcB_i)
                                        : (vlSelf->SrcA_i 
                                           & vlSelf->SrcB_i))
                                    : ((1U & (IData)(vlSelf->ALUControl_i))
                                        ? (vlSelf->SrcA_i 
                                           - vlSelf->SrcB_i)
                                        : (vlSelf->SrcA_i 
                                           + vlSelf->SrcB_i)))));
    vlSelf->Zero_o = (0U == vlSelf->ALUResult_o);
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
    if (VL_UNLIKELY((vlSelf->ALUControl_i & 0xf0U))) {
        Verilated::overWidthError("ALUControl_i");}
}
#endif  // VL_DEBUG
