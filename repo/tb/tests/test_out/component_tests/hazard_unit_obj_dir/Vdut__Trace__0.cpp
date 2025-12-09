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
    bufp->chgCData(oldp+0,(vlSelf->Rs1D_i),5);
    bufp->chgCData(oldp+1,(vlSelf->Rs2D_i),5);
    bufp->chgCData(oldp+2,(vlSelf->Rs1E_i),5);
    bufp->chgCData(oldp+3,(vlSelf->Rs2E_i),5);
    bufp->chgCData(oldp+4,(vlSelf->RdE_i),5);
    bufp->chgBit(oldp+5,(vlSelf->ResultSrcE0_i));
    bufp->chgCData(oldp+6,(vlSelf->RdM_i),5);
    bufp->chgBit(oldp+7,(vlSelf->RegWriteM_i));
    bufp->chgCData(oldp+8,(vlSelf->RdW_i),5);
    bufp->chgBit(oldp+9,(vlSelf->RegWriteW_i));
    bufp->chgBit(oldp+10,(vlSelf->PCSrcE_i));
    bufp->chgBit(oldp+11,(vlSelf->CacheStall_i));
    bufp->chgCData(oldp+12,(vlSelf->ForwardAE_o),2);
    bufp->chgCData(oldp+13,(vlSelf->ForwardBE_o),2);
    bufp->chgBit(oldp+14,(vlSelf->StallF_o));
    bufp->chgBit(oldp+15,(vlSelf->StallD_o));
    bufp->chgBit(oldp+16,(vlSelf->StallE_o));
    bufp->chgBit(oldp+17,(vlSelf->StallM_o));
    bufp->chgBit(oldp+18,(vlSelf->StallW_o));
    bufp->chgBit(oldp+19,(vlSelf->FlushD_o));
    bufp->chgBit(oldp+20,(vlSelf->FlushE_o));
    bufp->chgBit(oldp+21,(vlSelf->hazard_unit__DOT__lwStall));
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
