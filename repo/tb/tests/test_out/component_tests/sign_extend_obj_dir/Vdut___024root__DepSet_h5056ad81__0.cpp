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
    vlSelf->imm_ext_o = ((4U & (IData)(vlSelf->imm_src_i))
                          ? ((2U & (IData)(vlSelf->imm_src_i))
                              ? 0U : ((1U & (IData)(vlSelf->imm_src_i))
                                       ? (0x1fU & (vlSelf->imm_instr_i 
                                                   >> 0x14U))
                                       : (((- (IData)(
                                                      (vlSelf->imm_instr_i 
                                                       >> 0x1fU))) 
                                           << 0x15U) 
                                          | ((0x100000U 
                                              & (vlSelf->imm_instr_i 
                                                 >> 0xbU)) 
                                             | ((0xff000U 
                                                 & vlSelf->imm_instr_i) 
                                                | ((0x800U 
                                                    & (vlSelf->imm_instr_i 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->imm_instr_i 
                                                         >> 0x14U))))))))
                          : ((2U & (IData)(vlSelf->imm_src_i))
                              ? ((1U & (IData)(vlSelf->imm_src_i))
                                  ? (0xfffff000U & vlSelf->imm_instr_i)
                                  : (((- (IData)((vlSelf->imm_instr_i 
                                                  >> 0x1fU))) 
                                      << 0xcU) | ((0xfe0U 
                                                   & (vlSelf->imm_instr_i 
                                                      >> 0x14U)) 
                                                  | (0x1fU 
                                                     & (vlSelf->imm_instr_i 
                                                        >> 7U)))))
                              : ((1U & (IData)(vlSelf->imm_src_i))
                                  ? (((- (IData)((vlSelf->imm_instr_i 
                                                  >> 0x1fU))) 
                                      << 0xdU) | ((0x1000U 
                                                   & (vlSelf->imm_instr_i 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlSelf->imm_instr_i 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelf->imm_instr_i 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelf->imm_instr_i 
                                                              >> 7U))))))
                                  : (((- (IData)((vlSelf->imm_instr_i 
                                                  >> 0x1fU))) 
                                      << 0xcU) | (vlSelf->imm_instr_i 
                                                  >> 0x14U)))));
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
    if (VL_UNLIKELY((vlSelf->imm_src_i & 0xf8U))) {
        Verilated::overWidthError("imm_src_i");}
}
#endif  // VL_DEBUG
