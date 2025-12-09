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
    bufp->chgBit(oldp+2,(vlSelf->RegWriteE_i));
    bufp->chgBit(oldp+3,(vlSelf->RegWriteM_o));
    bufp->chgCData(oldp+4,(vlSelf->ResultSrcE_i),2);
    bufp->chgCData(oldp+5,(vlSelf->ResultSrcM_o),2);
    bufp->chgBit(oldp+6,(vlSelf->MemWriteE_i));
    bufp->chgBit(oldp+7,(vlSelf->MemWriteM_o));
    bufp->chgCData(oldp+8,(vlSelf->funct3E_i),3);
    bufp->chgCData(oldp+9,(vlSelf->funct3M_o),3);
    bufp->chgIData(oldp+10,(vlSelf->ALUResultE_i),32);
    bufp->chgIData(oldp+11,(vlSelf->ALUResultM_o),32);
    bufp->chgIData(oldp+12,(vlSelf->WriteDataE_i),32);
    bufp->chgIData(oldp+13,(vlSelf->WriteDataM_o),32);
    bufp->chgCData(oldp+14,(vlSelf->RdE_i),5);
    bufp->chgCData(oldp+15,(vlSelf->RdM_o),5);
    bufp->chgIData(oldp+16,(vlSelf->PCPlus4E_i),32);
    bufp->chgIData(oldp+17,(vlSelf->PCPlus4M_o),32);
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
