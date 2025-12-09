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
    tracep->declBit(c+3,"RegWriteM_i", false,-1);
    tracep->declBit(c+4,"RegWriteW_o", false,-1);
    tracep->declBus(c+5,"ResultSrcM_i", false,-1, 1,0);
    tracep->declBus(c+6,"ResultSrcW_o", false,-1, 1,0);
    tracep->declBus(c+7,"ALUResultM_i", false,-1, 31,0);
    tracep->declBus(c+8,"ALUResultW_o", false,-1, 31,0);
    tracep->declBus(c+9,"ReadDataM_i", false,-1, 31,0);
    tracep->declBus(c+10,"ReadDataW_o", false,-1, 31,0);
    tracep->declBus(c+11,"RdM_i", false,-1, 4,0);
    tracep->declBus(c+12,"RdW_o", false,-1, 4,0);
    tracep->declBus(c+13,"PCPlus4M_i", false,-1, 31,0);
    tracep->declBus(c+14,"PCPlus4W_o", false,-1, 31,0);
    tracep->pushNamePrefix("pip_reg_w ");
    tracep->declBus(c+15,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+15,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+16,"REGISTER_ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"en_i", false,-1);
    tracep->declBit(c+3,"RegWriteM_i", false,-1);
    tracep->declBit(c+4,"RegWriteW_o", false,-1);
    tracep->declBus(c+5,"ResultSrcM_i", false,-1, 1,0);
    tracep->declBus(c+6,"ResultSrcW_o", false,-1, 1,0);
    tracep->declBus(c+7,"ALUResultM_i", false,-1, 31,0);
    tracep->declBus(c+8,"ALUResultW_o", false,-1, 31,0);
    tracep->declBus(c+9,"ReadDataM_i", false,-1, 31,0);
    tracep->declBus(c+10,"ReadDataW_o", false,-1, 31,0);
    tracep->declBus(c+11,"RdM_i", false,-1, 4,0);
    tracep->declBus(c+12,"RdW_o", false,-1, 4,0);
    tracep->declBus(c+13,"PCPlus4M_i", false,-1, 31,0);
    tracep->declBus(c+14,"PCPlus4W_o", false,-1, 31,0);
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
    bufp->fullBit(oldp+3,(vlSelf->RegWriteM_i));
    bufp->fullBit(oldp+4,(vlSelf->RegWriteW_o));
    bufp->fullCData(oldp+5,(vlSelf->ResultSrcM_i),2);
    bufp->fullCData(oldp+6,(vlSelf->ResultSrcW_o),2);
    bufp->fullIData(oldp+7,(vlSelf->ALUResultM_i),32);
    bufp->fullIData(oldp+8,(vlSelf->ALUResultW_o),32);
    bufp->fullIData(oldp+9,(vlSelf->ReadDataM_i),32);
    bufp->fullIData(oldp+10,(vlSelf->ReadDataW_o),32);
    bufp->fullCData(oldp+11,(vlSelf->RdM_i),5);
    bufp->fullCData(oldp+12,(vlSelf->RdW_o),5);
    bufp->fullIData(oldp+13,(vlSelf->PCPlus4M_i),32);
    bufp->fullIData(oldp+14,(vlSelf->PCPlus4W_o),32);
    bufp->fullIData(oldp+15,(0x20U),32);
    bufp->fullIData(oldp+16,(5U),32);
}
