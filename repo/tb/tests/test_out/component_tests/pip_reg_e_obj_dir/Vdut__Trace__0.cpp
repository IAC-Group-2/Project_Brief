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
    bufp->chgBit(oldp+1,(vlSelf->clr_i));
    bufp->chgBit(oldp+2,(vlSelf->en_i));
    bufp->chgBit(oldp+3,(vlSelf->RegWriteD_i));
    bufp->chgBit(oldp+4,(vlSelf->RegWriteE_o));
    bufp->chgCData(oldp+5,(vlSelf->ResultSrcD_i),2);
    bufp->chgCData(oldp+6,(vlSelf->ResultSrcE_o),2);
    bufp->chgBit(oldp+7,(vlSelf->MemWriteD_i));
    bufp->chgBit(oldp+8,(vlSelf->MemWriteE_o));
    bufp->chgBit(oldp+9,(vlSelf->JumpD_i));
    bufp->chgBit(oldp+10,(vlSelf->JumpE_o));
    bufp->chgBit(oldp+11,(vlSelf->BranchD_i));
    bufp->chgBit(oldp+12,(vlSelf->BranchE_o));
    bufp->chgCData(oldp+13,(vlSelf->ALUControlD_i),4);
    bufp->chgCData(oldp+14,(vlSelf->ALUControlE_o),4);
    bufp->chgBit(oldp+15,(vlSelf->ALUSrcAD_i));
    bufp->chgBit(oldp+16,(vlSelf->ALUSrcAE_o));
    bufp->chgCData(oldp+17,(vlSelf->funct3D_i),3);
    bufp->chgCData(oldp+18,(vlSelf->funct3E_o),3);
    bufp->chgBit(oldp+19,(vlSelf->ALUSrcD_i));
    bufp->chgBit(oldp+20,(vlSelf->ALUSrcE_o));
    bufp->chgIData(oldp+21,(vlSelf->RD1D_i),32);
    bufp->chgIData(oldp+22,(vlSelf->RD1E_o),32);
    bufp->chgIData(oldp+23,(vlSelf->RD2D_i),32);
    bufp->chgIData(oldp+24,(vlSelf->RD2E_o),32);
    bufp->chgIData(oldp+25,(vlSelf->PCD_i),32);
    bufp->chgIData(oldp+26,(vlSelf->PCE_o),32);
    bufp->chgCData(oldp+27,(vlSelf->Rs1D_i),5);
    bufp->chgCData(oldp+28,(vlSelf->Rs1E_o),5);
    bufp->chgCData(oldp+29,(vlSelf->Rs2D_i),5);
    bufp->chgCData(oldp+30,(vlSelf->Rs2E_o),5);
    bufp->chgCData(oldp+31,(vlSelf->RdD_i),5);
    bufp->chgCData(oldp+32,(vlSelf->RdE_o),5);
    bufp->chgIData(oldp+33,(vlSelf->ImmExtD_i),32);
    bufp->chgIData(oldp+34,(vlSelf->ImmExtE_o),32);
    bufp->chgIData(oldp+35,(vlSelf->PCPlus4D_i),32);
    bufp->chgIData(oldp+36,(vlSelf->PCPlus4E_o),32);
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
