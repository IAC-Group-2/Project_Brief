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
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"en_i", false,-1);
    tracep->declBit(c+3,"clr_i", false,-1);
    tracep->declBus(c+4,"PCF_i", false,-1, 31,0);
    tracep->declBus(c+5,"PCD_o", false,-1, 31,0);
    tracep->declBus(c+6,"InstrF_i", false,-1, 31,0);
    tracep->declBus(c+7,"InstrD_o", false,-1, 31,0);
    tracep->declBus(c+8,"PCPlus4F_i", false,-1, 31,0);
    tracep->declBus(c+9,"PCPlus4D_o", false,-1, 31,0);
    tracep->pushNamePrefix("pip_reg_d ");
    tracep->declBus(c+10,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+10,"INSTRUCTION_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"en_i", false,-1);
    tracep->declBit(c+3,"clr_i", false,-1);
    tracep->declBus(c+4,"PCF_i", false,-1, 31,0);
    tracep->declBus(c+5,"PCD_o", false,-1, 31,0);
    tracep->declBus(c+6,"InstrF_i", false,-1, 31,0);
    tracep->declBus(c+7,"InstrD_o", false,-1, 31,0);
    tracep->declBus(c+8,"PCPlus4F_i", false,-1, 31,0);
    tracep->declBus(c+9,"PCPlus4D_o", false,-1, 31,0);
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
    bufp->fullBit(oldp+1,(vlSelf->clk_i));
    bufp->fullBit(oldp+2,(vlSelf->en_i));
    bufp->fullBit(oldp+3,(vlSelf->clr_i));
    bufp->fullIData(oldp+4,(vlSelf->PCF_i),32);
    bufp->fullIData(oldp+5,(vlSelf->PCD_o),32);
    bufp->fullIData(oldp+6,(vlSelf->InstrF_i),32);
    bufp->fullIData(oldp+7,(vlSelf->InstrD_o),32);
    bufp->fullIData(oldp+8,(vlSelf->PCPlus4F_i),32);
    bufp->fullIData(oldp+9,(vlSelf->PCPlus4D_o),32);
    bufp->fullIData(oldp+10,(0x20U),32);
}
