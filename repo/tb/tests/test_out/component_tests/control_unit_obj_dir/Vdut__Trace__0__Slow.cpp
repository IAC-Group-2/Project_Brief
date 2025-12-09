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
    tracep->declBus(c+5,"op_i", false,-1, 6,0);
    tracep->declBus(c+6,"funct3_i", false,-1, 2,0);
    tracep->declBus(c+7,"funct7_i", false,-1, 6,0);
    tracep->declBit(c+8,"RegWrite_o", false,-1);
    tracep->declBit(c+9,"MemWrite_o", false,-1);
    tracep->declBus(c+10,"ALUControl_o", false,-1, 3,0);
    tracep->declBit(c+11,"ALUSrc_o", false,-1);
    tracep->declBit(c+12,"ALUSrcA_o", false,-1);
    tracep->declBus(c+13,"ImmSrc_o", false,-1, 2,0);
    tracep->declBus(c+14,"ResultSrc_o", false,-1, 1,0);
    tracep->declBit(c+15,"Jump_o", false,-1);
    tracep->declBit(c+16,"Branch_o", false,-1);
    tracep->pushNamePrefix("control_unit ");
    tracep->declBus(c+5,"op_i", false,-1, 6,0);
    tracep->declBus(c+6,"funct3_i", false,-1, 2,0);
    tracep->declBus(c+7,"funct7_i", false,-1, 6,0);
    tracep->declBit(c+8,"RegWrite_o", false,-1);
    tracep->declBit(c+9,"MemWrite_o", false,-1);
    tracep->declBus(c+10,"ALUControl_o", false,-1, 3,0);
    tracep->declBit(c+11,"ALUSrc_o", false,-1);
    tracep->declBit(c+12,"ALUSrcA_o", false,-1);
    tracep->declBus(c+13,"ImmSrc_o", false,-1, 2,0);
    tracep->declBus(c+14,"ResultSrc_o", false,-1, 1,0);
    tracep->declBit(c+15,"Jump_o", false,-1);
    tracep->declBit(c+16,"Branch_o", false,-1);
    tracep->declBit(c+1,"branch", false,-1);
    tracep->declBus(c+2,"ALUOp", false,-1, 1,0);
    tracep->declBit(c+3,"jump", false,-1);
    tracep->declBit(c+4,"jalr", false,-1);
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
    bufp->fullBit(oldp+1,(vlSelf->control_unit__DOT__branch));
    bufp->fullCData(oldp+2,(vlSelf->control_unit__DOT__ALUOp),2);
    bufp->fullBit(oldp+3,(vlSelf->control_unit__DOT__jump));
    bufp->fullBit(oldp+4,(vlSelf->control_unit__DOT__jalr));
    bufp->fullCData(oldp+5,(vlSelf->op_i),7);
    bufp->fullCData(oldp+6,(vlSelf->funct3_i),3);
    bufp->fullCData(oldp+7,(vlSelf->funct7_i),7);
    bufp->fullBit(oldp+8,(vlSelf->RegWrite_o));
    bufp->fullBit(oldp+9,(vlSelf->MemWrite_o));
    bufp->fullCData(oldp+10,(vlSelf->ALUControl_o),4);
    bufp->fullBit(oldp+11,(vlSelf->ALUSrc_o));
    bufp->fullBit(oldp+12,(vlSelf->ALUSrcA_o));
    bufp->fullCData(oldp+13,(vlSelf->ImmSrc_o),3);
    bufp->fullCData(oldp+14,(vlSelf->ResultSrc_o),2);
    bufp->fullBit(oldp+15,(vlSelf->Jump_o));
    bufp->fullBit(oldp+16,(vlSelf->Branch_o));
}
