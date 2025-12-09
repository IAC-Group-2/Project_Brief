// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___settle__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->cache__DOT__cache_en = ((1U == (IData)(vlSelf->ResultSrcM_i)) 
                                    | (IData)(vlSelf->MemWriteM_i));
    vlSelf->cache__DOT__cache_set[0U] = vlSelf->cache__DOT__cache_array
        [(0xffU & (vlSelf->addr_i >> 2U))][0U];
    vlSelf->cache__DOT__cache_set[1U] = vlSelf->cache__DOT__cache_array
        [(0xffU & (vlSelf->addr_i >> 2U))][1U];
    vlSelf->cache__DOT__cache_set[2U] = vlSelf->cache__DOT__cache_array
        [(0xffU & (vlSelf->addr_i >> 2U))][2U];
    vlSelf->cache__DOT__cache_set[3U] = vlSelf->cache__DOT__cache_array
        [(0xffU & (vlSelf->addr_i >> 2U))][3U];
    vlSelf->mem_wr_en_o = 0U;
    vlSelf->mem_wr_en_o = (1U == vlSelf->cache__DOT__current_state);
    vlSelf->funct3_o = ((((2U == vlSelf->cache__DOT__current_state) 
                          | (1U == vlSelf->cache__DOT__current_state)) 
                         | (3U == vlSelf->cache__DOT__current_state))
                         ? 2U : (IData)(vlSelf->funct3_i));
    vlSelf->cache__DOT__tag_0_hit = (((vlSelf->addr_i 
                                       >> 0xaU) == 
                                      (0x3fffffU & 
                                       vlSelf->cache__DOT__cache_set[1U])) 
                                     & (vlSelf->cache__DOT__cache_set[1U] 
                                        >> 0x17U));
    vlSelf->cache__DOT__tag_1_hit = (((vlSelf->addr_i 
                                       >> 0xaU) == 
                                      (0x3fffffU & 
                                       ((vlSelf->cache__DOT__cache_set[3U] 
                                         << 8U) | (
                                                   vlSelf->cache__DOT__cache_set[2U] 
                                                   >> 0x18U)))) 
                                     & (vlSelf->cache__DOT__cache_set[3U] 
                                        >> 0xfU));
    vlSelf->cache__DOT__cache_hit = (((IData)(vlSelf->cache__DOT__tag_0_hit) 
                                      | (IData)(vlSelf->cache__DOT__tag_1_hit)) 
                                     & (IData)(vlSelf->cache__DOT__cache_en));
    vlSelf->cache__DOT__cache_miss = ((IData)(vlSelf->cache__DOT__cache_en) 
                                      & (~ (IData)(vlSelf->cache__DOT__cache_hit)));
    vlSelf->mem_wr_data_o = 0U;
    vlSelf->mem_addr_o = vlSelf->addr_i;
    if ((1U == vlSelf->cache__DOT__current_state)) {
        vlSelf->mem_wr_data_o = ((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                                  ? ((vlSelf->cache__DOT__cache_set[2U] 
                                      << 8U) | (vlSelf->cache__DOT__cache_set[1U] 
                                                >> 0x18U))
                                  : vlSelf->cache__DOT__cache_set[0U]);
        vlSelf->mem_addr_o = ((((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                                 ? ((vlSelf->cache__DOT__cache_set[3U] 
                                     << 8U) | (vlSelf->cache__DOT__cache_set[2U] 
                                               >> 0x18U))
                                 : vlSelf->cache__DOT__cache_set[1U]) 
                               << 0xaU) | (0x3fcU & vlSelf->addr_i));
    } else {
        vlSelf->mem_addr_o = ((2U == vlSelf->cache__DOT__current_state)
                               ? (0xfffffffcU & vlSelf->addr_i)
                               : ((3U == vlSelf->cache__DOT__current_state)
                                   ? (0xfffffffcU & vlSelf->addr_i)
                                   : vlSelf->addr_i));
    }
    vlSelf->cache_miss_o = vlSelf->cache__DOT__cache_miss;
    vlSelf->stall_o = ((0U != vlSelf->cache__DOT__current_state) 
                       | ((0U == vlSelf->cache__DOT__current_state) 
                          & (IData)(vlSelf->cache__DOT__cache_miss)));
    vlSelf->cache__DOT__next_state = ((0U == vlSelf->cache__DOT__current_state)
                                       ? ((IData)(vlSelf->cache__DOT__cache_miss)
                                           ? ((1U & 
                                               ((0x10000U 
                                                 & vlSelf->cache__DOT__cache_set[3U])
                                                 ? (IData)(
                                                           (0xc000U 
                                                            == 
                                                            (0xc000U 
                                                             & vlSelf->cache__DOT__cache_set[3U])))
                                                 : (IData)(
                                                           (0xc00000U 
                                                            == 
                                                            (0xc00000U 
                                                             & vlSelf->cache__DOT__cache_set[1U])))))
                                               ? 1U
                                               : 2U)
                                           : 0U) : 
                                      ((1U == vlSelf->cache__DOT__current_state)
                                        ? 2U : ((2U 
                                                 == vlSelf->cache__DOT__current_state)
                                                 ? 3U
                                                 : 0U)));
    vlSelf->cache__DOT__raw_cache_data = ((IData)(vlSelf->cache__DOT__tag_1_hit)
                                           ? ((vlSelf->cache__DOT__cache_set[2U] 
                                               << 8U) 
                                              | (vlSelf->cache__DOT__cache_set[1U] 
                                                 >> 0x18U))
                                           : vlSelf->cache__DOT__cache_set[0U]);
    vlSelf->cache__DOT__raw_mem_data = vlSelf->mem_rd_data_i;
    vlSelf->data_o = (((0U == vlSelf->cache__DOT__current_state) 
                       & (IData)(vlSelf->cache__DOT__cache_hit))
                       ? ((2U == (IData)(vlSelf->funct3_i))
                           ? vlSelf->cache__DOT__raw_cache_data
                           : ((0U == (3U & vlSelf->addr_i))
                               ? (0xffU & vlSelf->cache__DOT__raw_cache_data)
                               : ((1U == (3U & vlSelf->addr_i))
                                   ? (0xffU & (vlSelf->cache__DOT__raw_cache_data 
                                               >> 8U))
                                   : ((2U == (3U & vlSelf->addr_i))
                                       ? (0xffU & (vlSelf->cache__DOT__raw_cache_data 
                                                   >> 0x10U))
                                       : (vlSelf->cache__DOT__raw_cache_data 
                                          >> 0x18U)))))
                       : ((3U == vlSelf->cache__DOT__current_state)
                           ? ((2U == (IData)(vlSelf->funct3_i))
                               ? vlSelf->cache__DOT__raw_mem_data
                               : ((0U == (3U & vlSelf->addr_i))
                                   ? (0xffU & vlSelf->cache__DOT__raw_mem_data)
                                   : ((1U == (3U & vlSelf->addr_i))
                                       ? (0xffU & (vlSelf->cache__DOT__raw_mem_data 
                                                   >> 8U))
                                       : ((2U == (3U 
                                                  & vlSelf->addr_i))
                                           ? (0xffU 
                                              & (vlSelf->cache__DOT__raw_mem_data 
                                                 >> 0x10U))
                                           : (vlSelf->cache__DOT__raw_mem_data 
                                              >> 0x18U)))))
                           : 0U));
}

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
    // Body
    Vdut___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
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
    vlSelf->rst_i = VL_RAND_RESET_I(1);
    vlSelf->MemWriteM_i = VL_RAND_RESET_I(1);
    vlSelf->ResultSrcM_i = VL_RAND_RESET_I(2);
    vlSelf->funct3_i = VL_RAND_RESET_I(3);
    vlSelf->addr_i = VL_RAND_RESET_I(32);
    vlSelf->data_i = VL_RAND_RESET_I(32);
    vlSelf->mem_rd_data_i = VL_RAND_RESET_I(32);
    vlSelf->mem_addr_o = VL_RAND_RESET_I(32);
    vlSelf->mem_wr_en_o = VL_RAND_RESET_I(1);
    vlSelf->mem_wr_data_o = VL_RAND_RESET_I(32);
    vlSelf->funct3_o = VL_RAND_RESET_I(3);
    vlSelf->data_o = VL_RAND_RESET_I(32);
    vlSelf->cache_miss_o = VL_RAND_RESET_I(1);
    vlSelf->stall_o = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__cache_en = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__current_state = 0;
    vlSelf->cache__DOT__next_state = 0;
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        VL_RAND_RESET_W(113, vlSelf->cache__DOT__cache_array[__Vi0]);
    }
    VL_RAND_RESET_W(113, vlSelf->cache__DOT__cache_set);
    vlSelf->cache__DOT__tag_0_hit = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__tag_1_hit = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__cache_miss = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__cache_hit = VL_RAND_RESET_I(1);
    vlSelf->cache__DOT__raw_cache_data = VL_RAND_RESET_I(32);
    vlSelf->cache__DOT__raw_mem_data = VL_RAND_RESET_I(32);
    vlSelf->cache__DOT__unnamedblk1__DOT__i = 0;
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
