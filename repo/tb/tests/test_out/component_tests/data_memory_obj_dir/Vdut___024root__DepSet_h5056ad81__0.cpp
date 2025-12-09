// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_INLINE_OPT void Vdut___024root___sequent__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___sequent__TOP__0\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__data_memory__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v3;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v4;
    CData/*0:0*/ __Vdlyvset__data_memory__DOT__ram_array__v4;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v5;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v5;
    CData/*0:0*/ __Vdlyvset__data_memory__DOT__ram_array__v5;
    IData/*16:0*/ __Vdlyvdim0__data_memory__DOT__ram_array__v6;
    CData/*7:0*/ __Vdlyvval__data_memory__DOT__ram_array__v6;
    // Body
    __Vdlyvset__data_memory__DOT__ram_array__v0 = 0U;
    __Vdlyvset__data_memory__DOT__ram_array__v4 = 0U;
    __Vdlyvset__data_memory__DOT__ram_array__v5 = 0U;
    if (vlSelf->wr_en_i) {
        if ((2U == (IData)(vlSelf->funct3_i))) {
            __Vdlyvval__data_memory__DOT__ram_array__v0 
                = (0xffU & vlSelf->data_i);
            __Vdlyvset__data_memory__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__data_memory__DOT__ram_array__v0 
                = (0x1ffffU & vlSelf->addr_i);
            __Vdlyvval__data_memory__DOT__ram_array__v1 
                = (0xffU & (vlSelf->data_i >> 8U));
            __Vdlyvdim0__data_memory__DOT__ram_array__v1 
                = (0x1ffffU & ((IData)(1U) + vlSelf->addr_i));
            __Vdlyvval__data_memory__DOT__ram_array__v2 
                = (0xffU & (vlSelf->data_i >> 0x10U));
            __Vdlyvdim0__data_memory__DOT__ram_array__v2 
                = (0x1ffffU & ((IData)(2U) + vlSelf->addr_i));
            __Vdlyvval__data_memory__DOT__ram_array__v3 
                = (vlSelf->data_i >> 0x18U);
            __Vdlyvdim0__data_memory__DOT__ram_array__v3 
                = (0x1ffffU & ((IData)(3U) + vlSelf->addr_i));
        } else if ((0U == (IData)(vlSelf->funct3_i))) {
            __Vdlyvval__data_memory__DOT__ram_array__v4 
                = (0xffU & vlSelf->data_i);
            __Vdlyvset__data_memory__DOT__ram_array__v4 = 1U;
            __Vdlyvdim0__data_memory__DOT__ram_array__v4 
                = (0x1ffffU & vlSelf->addr_i);
        } else if ((1U == (IData)(vlSelf->funct3_i))) {
            __Vdlyvval__data_memory__DOT__ram_array__v5 
                = (0xffU & vlSelf->data_i);
            __Vdlyvset__data_memory__DOT__ram_array__v5 = 1U;
            __Vdlyvdim0__data_memory__DOT__ram_array__v5 
                = (0x1ffffU & vlSelf->addr_i);
            __Vdlyvval__data_memory__DOT__ram_array__v6 
                = (0xffU & (vlSelf->data_i >> 8U));
            __Vdlyvdim0__data_memory__DOT__ram_array__v6 
                = (0x1ffffU & ((IData)(1U) + vlSelf->addr_i));
        }
    }
    if (__Vdlyvset__data_memory__DOT__ram_array__v0) {
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v0] 
            = __Vdlyvval__data_memory__DOT__ram_array__v0;
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v1] 
            = __Vdlyvval__data_memory__DOT__ram_array__v1;
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v2] 
            = __Vdlyvval__data_memory__DOT__ram_array__v2;
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v3] 
            = __Vdlyvval__data_memory__DOT__ram_array__v3;
    }
    if (__Vdlyvset__data_memory__DOT__ram_array__v4) {
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v4] 
            = __Vdlyvval__data_memory__DOT__ram_array__v4;
    }
    if (__Vdlyvset__data_memory__DOT__ram_array__v5) {
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v5] 
            = __Vdlyvval__data_memory__DOT__ram_array__v5;
        vlSelf->data_memory__DOT__ram_array[__Vdlyvdim0__data_memory__DOT__ram_array__v6] 
            = __Vdlyvval__data_memory__DOT__ram_array__v6;
    }
}

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->data_o = ((4U & (IData)(vlSelf->funct3_i))
                       ? ((2U & (IData)(vlSelf->funct3_i))
                           ? 0U : ((1U & (IData)(vlSelf->funct3_i))
                                    ? ((vlSelf->data_memory__DOT__ram_array
                                        [(0x1ffffU 
                                          & ((IData)(1U) 
                                             + vlSelf->addr_i))] 
                                        << 8U) | vlSelf->data_memory__DOT__ram_array
                                       [(0x1ffffU & vlSelf->addr_i)])
                                    : vlSelf->data_memory__DOT__ram_array
                                   [(0x1ffffU & vlSelf->addr_i)]))
                       : ((2U & (IData)(vlSelf->funct3_i))
                           ? ((1U & (IData)(vlSelf->funct3_i))
                               ? 0U : ((vlSelf->data_memory__DOT__ram_array
                                        [(0x1ffffU 
                                          & ((IData)(3U) 
                                             + vlSelf->addr_i))] 
                                        << 0x18U) | 
                                       ((vlSelf->data_memory__DOT__ram_array
                                         [(0x1ffffU 
                                           & ((IData)(2U) 
                                              + vlSelf->addr_i))] 
                                         << 0x10U) 
                                        | ((vlSelf->data_memory__DOT__ram_array
                                            [(0x1ffffU 
                                              & ((IData)(1U) 
                                                 + vlSelf->addr_i))] 
                                            << 8U) 
                                           | vlSelf->data_memory__DOT__ram_array
                                           [(0x1ffffU 
                                             & vlSelf->addr_i)]))))
                           : ((1U & (IData)(vlSelf->funct3_i))
                               ? (((- (IData)((1U & 
                                               (vlSelf->data_memory__DOT__ram_array
                                                [(0x1ffffU 
                                                  & ((IData)(1U) 
                                                     + vlSelf->addr_i))] 
                                                >> 7U)))) 
                                   << 0x10U) | ((vlSelf->data_memory__DOT__ram_array
                                                 [(0x1ffffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->addr_i))] 
                                                 << 8U) 
                                                | vlSelf->data_memory__DOT__ram_array
                                                [(0x1ffffU 
                                                  & vlSelf->addr_i)]))
                               : (((- (IData)((1U & 
                                               (vlSelf->data_memory__DOT__ram_array
                                                [(0x1ffffU 
                                                  & vlSelf->addr_i)] 
                                                >> 7U)))) 
                                   << 8U) | vlSelf->data_memory__DOT__ram_array
                                  [(0x1ffffU & vlSelf->addr_i)]))));
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vdut___024root___sequent__TOP__0(vlSelf);
    }
    Vdut___024root___combo__TOP__0(vlSelf);
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
    if (VL_UNLIKELY((vlSelf->wr_en_i & 0xfeU))) {
        Verilated::overWidthError("wr_en_i");}
    if (VL_UNLIKELY((vlSelf->funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
}
#endif  // VL_DEBUG
