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
    vlSelf->RD_o = ((vlSelf->instr_mem__DOT__rom_array
                     [(0xfffU & ((IData)(3U) + vlSelf->A_i))] 
                     << 0x18U) | ((vlSelf->instr_mem__DOT__rom_array
                                   [(0xfffU & ((IData)(2U) 
                                               + vlSelf->A_i))] 
                                   << 0x10U) | ((vlSelf->instr_mem__DOT__rom_array
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->A_i))] 
                                                 << 8U) 
                                                | vlSelf->instr_mem__DOT__rom_array
                                                [(0xfffU 
                                                  & vlSelf->A_i)])));
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
}
#endif  // VL_DEBUG
