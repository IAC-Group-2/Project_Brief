// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->cache__DOT__cache_en));
        bufp->chgBit(oldp+1,((1U & (vlSelf->cache__DOT__cache_set[1U] 
                                    >> 0x17U))));
        bufp->chgBit(oldp+2,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                    >> 0xfU))));
        bufp->chgBit(oldp+3,((1U & (vlSelf->cache__DOT__cache_set[1U] 
                                    >> 0x16U))));
        bufp->chgBit(oldp+4,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                    >> 0xeU))));
        bufp->chgQData(oldp+5,((0xffffffffffffffULL 
                                & (((QData)((IData)(
                                                    vlSelf->cache__DOT__cache_set[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->cache__DOT__cache_set[0U]))))),56);
        bufp->chgQData(oldp+7,((0xffffffffffffffULL 
                                & (((QData)((IData)(
                                                    vlSelf->cache__DOT__cache_set[3U])) 
                                    << 0x28U) | (((QData)((IData)(
                                                                  vlSelf->cache__DOT__cache_set[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->cache__DOT__cache_set[1U])) 
                                                    >> 0x18U))))),56);
        bufp->chgIData(oldp+9,((0x3fffffU & vlSelf->cache__DOT__cache_set[1U])),22);
        bufp->chgIData(oldp+10,((0x3fffffU & ((vlSelf->cache__DOT__cache_set[3U] 
                                               << 8U) 
                                              | (vlSelf->cache__DOT__cache_set[2U] 
                                                 >> 0x18U)))),22);
        bufp->chgIData(oldp+11,(vlSelf->cache__DOT__cache_set[0U]),32);
        bufp->chgIData(oldp+12,(((vlSelf->cache__DOT__cache_set[2U] 
                                  << 8U) | (vlSelf->cache__DOT__cache_set[1U] 
                                            >> 0x18U))),32);
        bufp->chgWData(oldp+13,(vlSelf->cache__DOT__cache_set),113);
        bufp->chgBit(oldp+17,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                     >> 0x10U))));
        bufp->chgBit(oldp+18,(vlSelf->cache__DOT__tag_0_hit));
        bufp->chgBit(oldp+19,(vlSelf->cache__DOT__tag_1_hit));
        bufp->chgBit(oldp+20,(vlSelf->cache__DOT__cache_miss));
        bufp->chgBit(oldp+21,(vlSelf->cache__DOT__cache_hit));
        bufp->chgBit(oldp+22,((1U & ((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                                      ? (IData)((0xc000U 
                                                 == 
                                                 (0xc000U 
                                                  & vlSelf->cache__DOT__cache_set[3U])))
                                      : (IData)((0xc00000U 
                                                 == 
                                                 (0xc00000U 
                                                  & vlSelf->cache__DOT__cache_set[1U])))))));
        bufp->chgIData(oldp+23,((0x3fffffU & ((0x10000U 
                                               & vlSelf->cache__DOT__cache_set[3U])
                                               ? ((
                                                   vlSelf->cache__DOT__cache_set[3U] 
                                                   << 8U) 
                                                  | (vlSelf->cache__DOT__cache_set[2U] 
                                                     >> 0x18U))
                                               : vlSelf->cache__DOT__cache_set[1U]))),22);
        bufp->chgIData(oldp+24,(((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                                  ? ((vlSelf->cache__DOT__cache_set[2U] 
                                      << 8U) | (vlSelf->cache__DOT__cache_set[1U] 
                                                >> 0x18U))
                                  : vlSelf->cache__DOT__cache_set[0U])),32);
        bufp->chgIData(oldp+25,(vlSelf->cache__DOT__raw_cache_data),32);
        bufp->chgIData(oldp+26,(vlSelf->cache__DOT__raw_mem_data),32);
    }
    bufp->chgBit(oldp+27,(vlSelf->clk_i));
    bufp->chgBit(oldp+28,(vlSelf->rst_i));
    bufp->chgBit(oldp+29,(vlSelf->MemWriteM_i));
    bufp->chgCData(oldp+30,(vlSelf->ResultSrcM_i),2);
    bufp->chgCData(oldp+31,(vlSelf->funct3_i),3);
    bufp->chgIData(oldp+32,(vlSelf->addr_i),32);
    bufp->chgIData(oldp+33,(vlSelf->data_i),32);
    bufp->chgIData(oldp+34,(vlSelf->mem_rd_data_i),32);
    bufp->chgIData(oldp+35,(vlSelf->mem_addr_o),32);
    bufp->chgBit(oldp+36,(vlSelf->mem_wr_en_o));
    bufp->chgIData(oldp+37,(vlSelf->mem_wr_data_o),32);
    bufp->chgCData(oldp+38,(vlSelf->funct3_o),3);
    bufp->chgIData(oldp+39,(vlSelf->data_o),32);
    bufp->chgBit(oldp+40,(vlSelf->cache_miss_o));
    bufp->chgBit(oldp+41,(vlSelf->stall_o));
    bufp->chgBit(oldp+42,((1U == (IData)(vlSelf->ResultSrcM_i))));
    bufp->chgCData(oldp+43,((3U & vlSelf->addr_i)),2);
    bufp->chgBit(oldp+44,((2U == (IData)(vlSelf->funct3_i))));
    bufp->chgIData(oldp+45,(vlSelf->cache__DOT__current_state),32);
    bufp->chgIData(oldp+46,(((0U == vlSelf->cache__DOT__current_state)
                              ? ((IData)(vlSelf->cache__DOT__cache_miss)
                                  ? ((1U & ((0x10000U 
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
                                      ? 1U : 2U) : 0U)
                              : ((1U == vlSelf->cache__DOT__current_state)
                                  ? 2U : ((2U == vlSelf->cache__DOT__current_state)
                                           ? 3U : 0U)))),32);
    bufp->chgCData(oldp+47,((0xffU & (vlSelf->addr_i 
                                      >> 2U))),8);
    bufp->chgIData(oldp+48,((vlSelf->addr_i >> 0xaU)),22);
    bufp->chgIData(oldp+49,(vlSelf->cache__DOT__unnamedblk1__DOT__i),32);
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
