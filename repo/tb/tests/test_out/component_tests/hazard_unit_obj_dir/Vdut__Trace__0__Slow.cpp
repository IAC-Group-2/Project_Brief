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
    tracep->declBus(c+1,"Rs1D_i", false,-1, 4,0);
    tracep->declBus(c+2,"Rs2D_i", false,-1, 4,0);
    tracep->declBus(c+3,"Rs1E_i", false,-1, 4,0);
    tracep->declBus(c+4,"Rs2E_i", false,-1, 4,0);
    tracep->declBus(c+5,"RdE_i", false,-1, 4,0);
    tracep->declBit(c+6,"ResultSrcE0_i", false,-1);
    tracep->declBus(c+7,"RdM_i", false,-1, 4,0);
    tracep->declBit(c+8,"RegWriteM_i", false,-1);
    tracep->declBus(c+9,"RdW_i", false,-1, 4,0);
    tracep->declBit(c+10,"RegWriteW_i", false,-1);
    tracep->declBit(c+11,"PCSrcE_i", false,-1);
    tracep->declBit(c+12,"CacheStall_i", false,-1);
    tracep->declBus(c+13,"ForwardAE_o", false,-1, 1,0);
    tracep->declBus(c+14,"ForwardBE_o", false,-1, 1,0);
    tracep->declBit(c+15,"StallF_o", false,-1);
    tracep->declBit(c+16,"StallD_o", false,-1);
    tracep->declBit(c+17,"StallE_o", false,-1);
    tracep->declBit(c+18,"StallM_o", false,-1);
    tracep->declBit(c+19,"StallW_o", false,-1);
    tracep->declBit(c+20,"FlushD_o", false,-1);
    tracep->declBit(c+21,"FlushE_o", false,-1);
    tracep->pushNamePrefix("hazard_unit ");
    tracep->declBus(c+23,"REGISTER_ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"Rs1D_i", false,-1, 4,0);
    tracep->declBus(c+2,"Rs2D_i", false,-1, 4,0);
    tracep->declBus(c+3,"Rs1E_i", false,-1, 4,0);
    tracep->declBus(c+4,"Rs2E_i", false,-1, 4,0);
    tracep->declBus(c+5,"RdE_i", false,-1, 4,0);
    tracep->declBit(c+6,"ResultSrcE0_i", false,-1);
    tracep->declBus(c+7,"RdM_i", false,-1, 4,0);
    tracep->declBit(c+8,"RegWriteM_i", false,-1);
    tracep->declBus(c+9,"RdW_i", false,-1, 4,0);
    tracep->declBit(c+10,"RegWriteW_i", false,-1);
    tracep->declBit(c+11,"PCSrcE_i", false,-1);
    tracep->declBit(c+12,"CacheStall_i", false,-1);
    tracep->declBus(c+13,"ForwardAE_o", false,-1, 1,0);
    tracep->declBus(c+14,"ForwardBE_o", false,-1, 1,0);
    tracep->declBit(c+15,"StallF_o", false,-1);
    tracep->declBit(c+16,"StallD_o", false,-1);
    tracep->declBit(c+17,"StallE_o", false,-1);
    tracep->declBit(c+18,"StallM_o", false,-1);
    tracep->declBit(c+19,"StallW_o", false,-1);
    tracep->declBit(c+20,"FlushD_o", false,-1);
    tracep->declBit(c+21,"FlushE_o", false,-1);
    tracep->declBit(c+22,"lwStall", false,-1);
    tracep->popNamePrefix(1);
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
    bufp->fullCData(oldp+1,(vlSelf->Rs1D_i),5);
    bufp->fullCData(oldp+2,(vlSelf->Rs2D_i),5);
    bufp->fullCData(oldp+3,(vlSelf->Rs1E_i),5);
    bufp->fullCData(oldp+4,(vlSelf->Rs2E_i),5);
    bufp->fullCData(oldp+5,(vlSelf->RdE_i),5);
    bufp->fullBit(oldp+6,(vlSelf->ResultSrcE0_i));
    bufp->fullCData(oldp+7,(vlSelf->RdM_i),5);
    bufp->fullBit(oldp+8,(vlSelf->RegWriteM_i));
    bufp->fullCData(oldp+9,(vlSelf->RdW_i),5);
    bufp->fullBit(oldp+10,(vlSelf->RegWriteW_i));
    bufp->fullBit(oldp+11,(vlSelf->PCSrcE_i));
    bufp->fullBit(oldp+12,(vlSelf->CacheStall_i));
    bufp->fullCData(oldp+13,(vlSelf->ForwardAE_o),2);
    bufp->fullCData(oldp+14,(vlSelf->ForwardBE_o),2);
    bufp->fullBit(oldp+15,(vlSelf->StallF_o));
    bufp->fullBit(oldp+16,(vlSelf->StallD_o));
    bufp->fullBit(oldp+17,(vlSelf->StallE_o));
    bufp->fullBit(oldp+18,(vlSelf->StallM_o));
    bufp->fullBit(oldp+19,(vlSelf->StallW_o));
    bufp->fullBit(oldp+20,(vlSelf->FlushD_o));
    bufp->fullBit(oldp+21,(vlSelf->FlushE_o));
    bufp->fullBit(oldp+22,(vlSelf->hazard_unit__DOT__lwStall));
    bufp->fullIData(oldp+23,(5U),32);
}
