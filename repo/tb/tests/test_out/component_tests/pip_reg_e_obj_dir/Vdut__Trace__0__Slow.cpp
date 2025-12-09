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
    tracep->declBit(c+2,"clr_i", false,-1);
    tracep->declBit(c+3,"en_i", false,-1);
    tracep->declBit(c+4,"RegWriteD_i", false,-1);
    tracep->declBit(c+5,"RegWriteE_o", false,-1);
    tracep->declBus(c+6,"ResultSrcD_i", false,-1, 1,0);
    tracep->declBus(c+7,"ResultSrcE_o", false,-1, 1,0);
    tracep->declBit(c+8,"MemWriteD_i", false,-1);
    tracep->declBit(c+9,"MemWriteE_o", false,-1);
    tracep->declBit(c+10,"JumpD_i", false,-1);
    tracep->declBit(c+11,"JumpE_o", false,-1);
    tracep->declBit(c+12,"BranchD_i", false,-1);
    tracep->declBit(c+13,"BranchE_o", false,-1);
    tracep->declBus(c+14,"ALUControlD_i", false,-1, 3,0);
    tracep->declBus(c+15,"ALUControlE_o", false,-1, 3,0);
    tracep->declBit(c+16,"ALUSrcAD_i", false,-1);
    tracep->declBit(c+17,"ALUSrcAE_o", false,-1);
    tracep->declBus(c+18,"funct3D_i", false,-1, 2,0);
    tracep->declBus(c+19,"funct3E_o", false,-1, 2,0);
    tracep->declBit(c+20,"ALUSrcD_i", false,-1);
    tracep->declBit(c+21,"ALUSrcE_o", false,-1);
    tracep->declBus(c+22,"RD1D_i", false,-1, 31,0);
    tracep->declBus(c+23,"RD1E_o", false,-1, 31,0);
    tracep->declBus(c+24,"RD2D_i", false,-1, 31,0);
    tracep->declBus(c+25,"RD2E_o", false,-1, 31,0);
    tracep->declBus(c+26,"PCD_i", false,-1, 31,0);
    tracep->declBus(c+27,"PCE_o", false,-1, 31,0);
    tracep->declBus(c+28,"Rs1D_i", false,-1, 4,0);
    tracep->declBus(c+29,"Rs1E_o", false,-1, 4,0);
    tracep->declBus(c+30,"Rs2D_i", false,-1, 4,0);
    tracep->declBus(c+31,"Rs2E_o", false,-1, 4,0);
    tracep->declBus(c+32,"RdD_i", false,-1, 4,0);
    tracep->declBus(c+33,"RdE_o", false,-1, 4,0);
    tracep->declBus(c+34,"ImmExtD_i", false,-1, 31,0);
    tracep->declBus(c+35,"ImmExtE_o", false,-1, 31,0);
    tracep->declBus(c+36,"PCPlus4D_i", false,-1, 31,0);
    tracep->declBus(c+37,"PCPlus4E_o", false,-1, 31,0);
    tracep->pushNamePrefix("pip_reg_e ");
    tracep->declBus(c+38,"PC_WIDTH", false,-1, 31,0);
    tracep->declBus(c+38,"INSTRUCTION_WIDTH", false,-1, 31,0);
    tracep->declBus(c+39,"REGISTER_ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk_i", false,-1);
    tracep->declBit(c+2,"clr_i", false,-1);
    tracep->declBit(c+3,"en_i", false,-1);
    tracep->declBit(c+4,"RegWriteD_i", false,-1);
    tracep->declBit(c+5,"RegWriteE_o", false,-1);
    tracep->declBus(c+6,"ResultSrcD_i", false,-1, 1,0);
    tracep->declBus(c+7,"ResultSrcE_o", false,-1, 1,0);
    tracep->declBit(c+8,"MemWriteD_i", false,-1);
    tracep->declBit(c+9,"MemWriteE_o", false,-1);
    tracep->declBit(c+10,"JumpD_i", false,-1);
    tracep->declBit(c+11,"JumpE_o", false,-1);
    tracep->declBit(c+12,"BranchD_i", false,-1);
    tracep->declBit(c+13,"BranchE_o", false,-1);
    tracep->declBus(c+14,"ALUControlD_i", false,-1, 3,0);
    tracep->declBus(c+15,"ALUControlE_o", false,-1, 3,0);
    tracep->declBit(c+16,"ALUSrcAD_i", false,-1);
    tracep->declBit(c+17,"ALUSrcAE_o", false,-1);
    tracep->declBus(c+18,"funct3D_i", false,-1, 2,0);
    tracep->declBus(c+19,"funct3E_o", false,-1, 2,0);
    tracep->declBit(c+20,"ALUSrcD_i", false,-1);
    tracep->declBit(c+21,"ALUSrcE_o", false,-1);
    tracep->declBus(c+22,"RD1D_i", false,-1, 31,0);
    tracep->declBus(c+23,"RD1E_o", false,-1, 31,0);
    tracep->declBus(c+24,"RD2D_i", false,-1, 31,0);
    tracep->declBus(c+25,"RD2E_o", false,-1, 31,0);
    tracep->declBus(c+26,"PCD_i", false,-1, 31,0);
    tracep->declBus(c+27,"PCE_o", false,-1, 31,0);
    tracep->declBus(c+28,"Rs1D_i", false,-1, 4,0);
    tracep->declBus(c+29,"Rs1E_o", false,-1, 4,0);
    tracep->declBus(c+30,"Rs2D_i", false,-1, 4,0);
    tracep->declBus(c+31,"Rs2E_o", false,-1, 4,0);
    tracep->declBus(c+32,"RdD_i", false,-1, 4,0);
    tracep->declBus(c+33,"RdE_o", false,-1, 4,0);
    tracep->declBus(c+34,"ImmExtD_i", false,-1, 31,0);
    tracep->declBus(c+35,"ImmExtE_o", false,-1, 31,0);
    tracep->declBus(c+36,"PCPlus4D_i", false,-1, 31,0);
    tracep->declBus(c+37,"PCPlus4E_o", false,-1, 31,0);
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
    bufp->fullBit(oldp+2,(vlSelf->clr_i));
    bufp->fullBit(oldp+3,(vlSelf->en_i));
    bufp->fullBit(oldp+4,(vlSelf->RegWriteD_i));
    bufp->fullBit(oldp+5,(vlSelf->RegWriteE_o));
    bufp->fullCData(oldp+6,(vlSelf->ResultSrcD_i),2);
    bufp->fullCData(oldp+7,(vlSelf->ResultSrcE_o),2);
    bufp->fullBit(oldp+8,(vlSelf->MemWriteD_i));
    bufp->fullBit(oldp+9,(vlSelf->MemWriteE_o));
    bufp->fullBit(oldp+10,(vlSelf->JumpD_i));
    bufp->fullBit(oldp+11,(vlSelf->JumpE_o));
    bufp->fullBit(oldp+12,(vlSelf->BranchD_i));
    bufp->fullBit(oldp+13,(vlSelf->BranchE_o));
    bufp->fullCData(oldp+14,(vlSelf->ALUControlD_i),4);
    bufp->fullCData(oldp+15,(vlSelf->ALUControlE_o),4);
    bufp->fullBit(oldp+16,(vlSelf->ALUSrcAD_i));
    bufp->fullBit(oldp+17,(vlSelf->ALUSrcAE_o));
    bufp->fullCData(oldp+18,(vlSelf->funct3D_i),3);
    bufp->fullCData(oldp+19,(vlSelf->funct3E_o),3);
    bufp->fullBit(oldp+20,(vlSelf->ALUSrcD_i));
    bufp->fullBit(oldp+21,(vlSelf->ALUSrcE_o));
    bufp->fullIData(oldp+22,(vlSelf->RD1D_i),32);
    bufp->fullIData(oldp+23,(vlSelf->RD1E_o),32);
    bufp->fullIData(oldp+24,(vlSelf->RD2D_i),32);
    bufp->fullIData(oldp+25,(vlSelf->RD2E_o),32);
    bufp->fullIData(oldp+26,(vlSelf->PCD_i),32);
    bufp->fullIData(oldp+27,(vlSelf->PCE_o),32);
    bufp->fullCData(oldp+28,(vlSelf->Rs1D_i),5);
    bufp->fullCData(oldp+29,(vlSelf->Rs1E_o),5);
    bufp->fullCData(oldp+30,(vlSelf->Rs2D_i),5);
    bufp->fullCData(oldp+31,(vlSelf->Rs2E_o),5);
    bufp->fullCData(oldp+32,(vlSelf->RdD_i),5);
    bufp->fullCData(oldp+33,(vlSelf->RdE_o),5);
    bufp->fullIData(oldp+34,(vlSelf->ImmExtD_i),32);
    bufp->fullIData(oldp+35,(vlSelf->ImmExtE_o),32);
    bufp->fullIData(oldp+36,(vlSelf->PCPlus4D_i),32);
    bufp->fullIData(oldp+37,(vlSelf->PCPlus4E_o),32);
    bufp->fullIData(oldp+38,(0x20U),32);
    bufp->fullIData(oldp+39,(5U),32);
}
