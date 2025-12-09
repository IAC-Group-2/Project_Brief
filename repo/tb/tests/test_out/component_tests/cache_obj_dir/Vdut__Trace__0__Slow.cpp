// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+28,"clk_i", false,-1);
    tracep->declBit(c+29,"rst_i", false,-1);
    tracep->declBit(c+30,"MemWriteM_i", false,-1);
    tracep->declBus(c+31,"ResultSrcM_i", false,-1, 1,0);
    tracep->declBus(c+32,"funct3_i", false,-1, 2,0);
    tracep->declBus(c+33,"addr_i", false,-1, 31,0);
    tracep->declBus(c+34,"data_i", false,-1, 31,0);
    tracep->declBus(c+35,"mem_rd_data_i", false,-1, 31,0);
    tracep->declBus(c+36,"mem_addr_o", false,-1, 31,0);
    tracep->declBit(c+37,"mem_wr_en_o", false,-1);
    tracep->declBus(c+38,"mem_wr_data_o", false,-1, 31,0);
    tracep->declBus(c+39,"funct3_o", false,-1, 2,0);
    tracep->declBus(c+40,"data_o", false,-1, 31,0);
    tracep->declBit(c+41,"cache_miss_o", false,-1);
    tracep->declBit(c+42,"stall_o", false,-1);
    tracep->pushNamePrefix("cache ");
    tracep->declBus(c+51,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+51,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+52,"BYTE_WIDTH", false,-1, 31,0);
    tracep->declBus(c+52,"SET_SIZE", false,-1, 31,0);
    tracep->declBus(c+53,"TAG_SIZE", false,-1, 31,0);
    tracep->declBus(c+54,"BYTE_OFFSET_WIDTH", false,-1, 31,0);
    tracep->declBus(c+55,"WAY_WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"CACHE_WIDTH", false,-1, 31,0);
    tracep->declBit(c+28,"clk_i", false,-1);
    tracep->declBit(c+29,"rst_i", false,-1);
    tracep->declBit(c+30,"MemWriteM_i", false,-1);
    tracep->declBus(c+31,"ResultSrcM_i", false,-1, 1,0);
    tracep->declBus(c+32,"funct3_i", false,-1, 2,0);
    tracep->declBus(c+33,"addr_i", false,-1, 31,0);
    tracep->declBus(c+34,"data_i", false,-1, 31,0);
    tracep->declBus(c+35,"mem_rd_data_i", false,-1, 31,0);
    tracep->declBus(c+36,"mem_addr_o", false,-1, 31,0);
    tracep->declBit(c+37,"mem_wr_en_o", false,-1);
    tracep->declBus(c+38,"mem_wr_data_o", false,-1, 31,0);
    tracep->declBus(c+39,"funct3_o", false,-1, 2,0);
    tracep->declBus(c+40,"data_o", false,-1, 31,0);
    tracep->declBit(c+41,"cache_miss_o", false,-1);
    tracep->declBit(c+42,"stall_o", false,-1);
    tracep->declBit(c+30,"wr_en", false,-1);
    tracep->declBit(c+43,"rd_en", false,-1);
    tracep->declBit(c+1,"cache_en", false,-1);
    tracep->declBus(c+44,"byte_offset", false,-1, 1,0);
    tracep->declBit(c+45,"is_word_op", false,-1);
    tracep->declBus(c+46,"current_state", false,-1, 31,0);
    tracep->declBus(c+47,"next_state", false,-1, 31,0);
    tracep->declBus(c+48,"set_addr", false,-1, 7,0);
    tracep->declBus(c+49,"tag_addr", false,-1, 21,0);
    tracep->declBit(c+2,"cache_valid_0", false,-1);
    tracep->declBit(c+3,"cache_valid_1", false,-1);
    tracep->declBit(c+4,"cache_dirty_0", false,-1);
    tracep->declBit(c+5,"cache_dirty_1", false,-1);
    tracep->declQuad(c+6,"cache_way_0", false,-1, 55,0);
    tracep->declQuad(c+8,"cache_way_1", false,-1, 55,0);
    tracep->declBus(c+10,"cache_tag_0", false,-1, 21,0);
    tracep->declBus(c+11,"cache_tag_1", false,-1, 21,0);
    tracep->declBus(c+12,"cache_data_0", false,-1, 31,0);
    tracep->declBus(c+13,"cache_data_1", false,-1, 31,0);
    tracep->declArray(c+14,"cache_set", false,-1, 112,0);
    tracep->declBit(c+18,"lru_bit", false,-1);
    tracep->declBit(c+19,"tag_0_hit", false,-1);
    tracep->declBit(c+20,"tag_1_hit", false,-1);
    tracep->declBit(c+21,"cache_miss", false,-1);
    tracep->declBit(c+22,"cache_hit", false,-1);
    tracep->declBit(c+18,"target_way", false,-1);
    tracep->declBit(c+23,"target_dirty", false,-1);
    tracep->declBus(c+24,"target_tag", false,-1, 21,0);
    tracep->declBus(c+25,"target_data", false,-1, 31,0);
    tracep->declBus(c+26,"raw_cache_data", false,-1, 31,0);
    tracep->declBus(c+27,"raw_mem_data", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+50,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdut___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_top_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->cache__DOT__cache_en));
    bufp->fullBit(oldp+2,((1U & (vlSelf->cache__DOT__cache_set[1U] 
                                 >> 0x17U))));
    bufp->fullBit(oldp+3,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                 >> 0xfU))));
    bufp->fullBit(oldp+4,((1U & (vlSelf->cache__DOT__cache_set[1U] 
                                 >> 0x16U))));
    bufp->fullBit(oldp+5,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                 >> 0xeU))));
    bufp->fullQData(oldp+6,((0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelf->cache__DOT__cache_set[1U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelf->cache__DOT__cache_set[0U]))))),56);
    bufp->fullQData(oldp+8,((0xffffffffffffffULL & 
                             (((QData)((IData)(vlSelf->cache__DOT__cache_set[3U])) 
                               << 0x28U) | (((QData)((IData)(
                                                             vlSelf->cache__DOT__cache_set[2U])) 
                                             << 8U) 
                                            | ((QData)((IData)(
                                                               vlSelf->cache__DOT__cache_set[1U])) 
                                               >> 0x18U))))),56);
    bufp->fullIData(oldp+10,((0x3fffffU & vlSelf->cache__DOT__cache_set[1U])),22);
    bufp->fullIData(oldp+11,((0x3fffffU & ((vlSelf->cache__DOT__cache_set[3U] 
                                            << 8U) 
                                           | (vlSelf->cache__DOT__cache_set[2U] 
                                              >> 0x18U)))),22);
    bufp->fullIData(oldp+12,(vlSelf->cache__DOT__cache_set[0U]),32);
    bufp->fullIData(oldp+13,(((vlSelf->cache__DOT__cache_set[2U] 
                               << 8U) | (vlSelf->cache__DOT__cache_set[1U] 
                                         >> 0x18U))),32);
    bufp->fullWData(oldp+14,(vlSelf->cache__DOT__cache_set),113);
    bufp->fullBit(oldp+18,((1U & (vlSelf->cache__DOT__cache_set[3U] 
                                  >> 0x10U))));
    bufp->fullBit(oldp+19,(vlSelf->cache__DOT__tag_0_hit));
    bufp->fullBit(oldp+20,(vlSelf->cache__DOT__tag_1_hit));
    bufp->fullBit(oldp+21,(vlSelf->cache__DOT__cache_miss));
    bufp->fullBit(oldp+22,(vlSelf->cache__DOT__cache_hit));
    bufp->fullBit(oldp+23,((1U & ((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                                   ? (IData)((0xc000U 
                                              == (0xc000U 
                                                  & vlSelf->cache__DOT__cache_set[3U])))
                                   : (IData)((0xc00000U 
                                              == (0xc00000U 
                                                  & vlSelf->cache__DOT__cache_set[1U])))))));
    bufp->fullIData(oldp+24,((0x3fffffU & ((0x10000U 
                                            & vlSelf->cache__DOT__cache_set[3U])
                                            ? ((vlSelf->cache__DOT__cache_set[3U] 
                                                << 8U) 
                                               | (vlSelf->cache__DOT__cache_set[2U] 
                                                  >> 0x18U))
                                            : vlSelf->cache__DOT__cache_set[1U]))),22);
    bufp->fullIData(oldp+25,(((0x10000U & vlSelf->cache__DOT__cache_set[3U])
                               ? ((vlSelf->cache__DOT__cache_set[2U] 
                                   << 8U) | (vlSelf->cache__DOT__cache_set[1U] 
                                             >> 0x18U))
                               : vlSelf->cache__DOT__cache_set[0U])),32);
    bufp->fullIData(oldp+26,(vlSelf->cache__DOT__raw_cache_data),32);
    bufp->fullIData(oldp+27,(vlSelf->cache__DOT__raw_mem_data),32);
    bufp->fullBit(oldp+28,(vlSelf->clk_i));
    bufp->fullBit(oldp+29,(vlSelf->rst_i));
    bufp->fullBit(oldp+30,(vlSelf->MemWriteM_i));
    bufp->fullCData(oldp+31,(vlSelf->ResultSrcM_i),2);
    bufp->fullCData(oldp+32,(vlSelf->funct3_i),3);
    bufp->fullIData(oldp+33,(vlSelf->addr_i),32);
    bufp->fullIData(oldp+34,(vlSelf->data_i),32);
    bufp->fullIData(oldp+35,(vlSelf->mem_rd_data_i),32);
    bufp->fullIData(oldp+36,(vlSelf->mem_addr_o),32);
    bufp->fullBit(oldp+37,(vlSelf->mem_wr_en_o));
    bufp->fullIData(oldp+38,(vlSelf->mem_wr_data_o),32);
    bufp->fullCData(oldp+39,(vlSelf->funct3_o),3);
    bufp->fullIData(oldp+40,(vlSelf->data_o),32);
    bufp->fullBit(oldp+41,(vlSelf->cache_miss_o));
    bufp->fullBit(oldp+42,(vlSelf->stall_o));
    bufp->fullBit(oldp+43,((1U == (IData)(vlSelf->ResultSrcM_i))));
    bufp->fullCData(oldp+44,((3U & vlSelf->addr_i)),2);
    bufp->fullBit(oldp+45,((2U == (IData)(vlSelf->funct3_i))));
    bufp->fullIData(oldp+46,(vlSelf->cache__DOT__current_state),32);
    bufp->fullIData(oldp+47,(((0U == vlSelf->cache__DOT__current_state)
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
    bufp->fullCData(oldp+48,((0xffU & (vlSelf->addr_i 
                                       >> 2U))),8);
    bufp->fullIData(oldp+49,((vlSelf->addr_i >> 0xaU)),22);
    bufp->fullIData(oldp+50,(vlSelf->cache__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+51,(0x20U),32);
    bufp->fullIData(oldp+52,(8U),32);
    bufp->fullIData(oldp+53,(0x16U),32);
    bufp->fullIData(oldp+54,(2U),32);
    bufp->fullIData(oldp+55,(0x38U),32);
    bufp->fullIData(oldp+56,(0x71U),32);
}
