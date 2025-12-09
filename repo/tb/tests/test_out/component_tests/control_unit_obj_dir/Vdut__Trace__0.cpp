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
        bufp->chgBit(oldp+0,(vlSelf->control_unit__DOT__branch));
        bufp->chgCData(oldp+1,(vlSelf->control_unit__DOT__ALUOp),2);
        bufp->chgBit(oldp+2,(vlSelf->control_unit__DOT__jump));
        bufp->chgBit(oldp+3,(vlSelf->control_unit__DOT__jalr));
    }
    bufp->chgCData(oldp+4,(vlSelf->op_i),7);
    bufp->chgCData(oldp+5,(vlSelf->funct3_i),3);
    bufp->chgCData(oldp+6,(vlSelf->funct7_i),7);
    bufp->chgBit(oldp+7,(vlSelf->RegWrite_o));
    bufp->chgBit(oldp+8,(vlSelf->MemWrite_o));
    bufp->chgCData(oldp+9,(vlSelf->ALUControl_o),4);
    bufp->chgBit(oldp+10,(vlSelf->ALUSrc_o));
    bufp->chgBit(oldp+11,(vlSelf->ALUSrcA_o));
    bufp->chgCData(oldp+12,(vlSelf->ImmSrc_o),3);
    bufp->chgCData(oldp+13,(vlSelf->ResultSrc_o),2);
    bufp->chgBit(oldp+14,(vlSelf->Jump_o));
    bufp->chgBit(oldp+15,(vlSelf->Branch_o));
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
