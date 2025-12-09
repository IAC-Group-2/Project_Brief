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
    tracep->declBit(c+3,"RegWriteE_i", false,-1);
    tracep->declBit(c+4,"RegWriteM_o", false,-1);
    tracep->declBus(c+5,"ResultSrcE_i", false,-1, 1,0);
    tracep->declBus(c+6,"ResultSrcM_o", false,-1, 1,0);
    tracep->declBit(c+7,"MemWriteE_i", false,-1);
    tracep->declBit(c+8,"MemWriteM_o", false,-1);
    tracep->declBus(c+9,"funct3E_i", false,-1, 2,0);
    tracep->declBus(c+10,"funct3M_o", false,-1, 2,0);
    tracep->declBus(c+11,"ALUResultE_i", false,-1, 31,0);
    tracep->declBus(c+12,"ALUResultM_o", false,-1, 31,0);
    tracep->declBus(c+13,"WriteDataE_i", false,-1, 31,0);
    tracep->declBus(c+14,"WriteDataM_o", false,-1, 31,0);
    tracep->declBus(c+15,"RdE_i", false,-1, 4,0);
    tracep->declBus(c+16,"RdM_o", false,-1, 4,0);
    tracep->declBus(c+17,"PCPlus4E_i", false,-1, 31,0);
    tracep->declBus(c+18,"PCPlus4M_o", false,-1, 31,0);
    tracep->pushNamePrefix("pip_reg_m ");
    tracep->declBus(c+19,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"INSTRUCTION_WIDTH", false,-1, 31,0);
    tracep->declBus(c+20,"REGISTER_ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"en_i", false,-1);
    tracep->declBit(c+3,"RegWriteE_i", false,-1);
    tracep->declBit(c+4,"RegWriteM_o", false,-1);
    tracep->declBus(c+5,"ResultSrcE_i", false,-1, 1,0);
    tracep->declBus(c+6,"ResultSrcM_o", false,-1, 1,0);
    tracep->declBit(c+7,"MemWriteE_i", false,-1);
    tracep->declBit(c+8,"MemWriteM_o", false,-1);
    tracep->declBus(c+9,"funct3E_i", false,-1, 2,0);
    tracep->declBus(c+10,"funct3M_o", false,-1, 2,0);
    tracep->declBus(c+11,"ALUResultE_i", false,-1, 31,0);
    tracep->declBus(c+12,"ALUResultM_o", false,-1, 31,0);
    tracep->declBus(c+13,"WriteDataE_i", false,-1, 31,0);
    tracep->declBus(c+14,"WriteDataM_o", false,-1, 31,0);
    tracep->declBus(c+15,"RdE_i", false,-1, 4,0);
    tracep->declBus(c+16,"RdM_o", false,-1, 4,0);
    tracep->declBus(c+17,"PCPlus4E_i", false,-1, 31,0);
    tracep->declBus(c+18,"PCPlus4M_o", false,-1, 31,0);
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
    bufp->fullBit(oldp+3,(vlSelf->RegWriteE_i));
    bufp->fullBit(oldp+4,(vlSelf->RegWriteM_o));
    bufp->fullCData(oldp+5,(vlSelf->ResultSrcE_i),2);
    bufp->fullCData(oldp+6,(vlSelf->ResultSrcM_o),2);
    bufp->fullBit(oldp+7,(vlSelf->MemWriteE_i));
    bufp->fullBit(oldp+8,(vlSelf->MemWriteM_o));
    bufp->fullCData(oldp+9,(vlSelf->funct3E_i),3);
    bufp->fullCData(oldp+10,(vlSelf->funct3M_o),3);
    bufp->fullIData(oldp+11,(vlSelf->ALUResultE_i),32);
    bufp->fullIData(oldp+12,(vlSelf->ALUResultM_o),32);
    bufp->fullIData(oldp+13,(vlSelf->WriteDataE_i),32);
    bufp->fullIData(oldp+14,(vlSelf->WriteDataM_o),32);
    bufp->fullCData(oldp+15,(vlSelf->RdE_i),5);
    bufp->fullCData(oldp+16,(vlSelf->RdM_o),5);
    bufp->fullIData(oldp+17,(vlSelf->PCPlus4E_i),32);
    bufp->fullIData(oldp+18,(vlSelf->PCPlus4M_o),32);
    bufp->fullIData(oldp+19,(0x20U),32);
    bufp->fullIData(oldp+20,(5U),32);
}
