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
    bufp->chgBit(oldp+0,(vlSelf->clk_i));
    bufp->chgBit(oldp+1,(vlSelf->en_i));
    bufp->chgBit(oldp+2,(vlSelf->RegWriteM_i));
    bufp->chgBit(oldp+3,(vlSelf->RegWriteW_o));
    bufp->chgCData(oldp+4,(vlSelf->ResultSrcM_i),2);
    bufp->chgCData(oldp+5,(vlSelf->ResultSrcW_o),2);
    bufp->chgIData(oldp+6,(vlSelf->ALUResultM_i),32);
    bufp->chgIData(oldp+7,(vlSelf->ALUResultW_o),32);
    bufp->chgIData(oldp+8,(vlSelf->ReadDataM_i),32);
    bufp->chgIData(oldp+9,(vlSelf->ReadDataW_o),32);
    bufp->chgCData(oldp+10,(vlSelf->RdM_i),5);
    bufp->chgCData(oldp+11,(vlSelf->RdW_o),5);
    bufp->chgIData(oldp+12,(vlSelf->PCPlus4M_i),32);
    bufp->chgIData(oldp+13,(vlSelf->PCPlus4W_o),32);
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
