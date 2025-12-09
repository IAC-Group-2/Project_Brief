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
    tracep->declBit(c+33,"clk_i", false,-1);
    tracep->declBus(c+34,"A1_i", false,-1, 4,0);
    tracep->declBus(c+35,"A2_i", false,-1, 4,0);
    tracep->declBus(c+36,"A3_i", false,-1, 4,0);
    tracep->declBus(c+37,"WD3_i", false,-1, 31,0);
    tracep->declBit(c+38,"WE3_i", false,-1);
    tracep->declBus(c+39,"RD1_o", false,-1, 31,0);
    tracep->declBus(c+40,"RD2_o", false,-1, 31,0);
    tracep->declBus(c+41,"A0_o", false,-1, 31,0);
    tracep->pushNamePrefix("regfile ");
    tracep->declBus(c+42,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+43,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+33,"clk_i", false,-1);
    tracep->declBus(c+34,"A1_i", false,-1, 4,0);
    tracep->declBus(c+35,"A2_i", false,-1, 4,0);
    tracep->declBus(c+36,"A3_i", false,-1, 4,0);
    tracep->declBus(c+37,"WD3_i", false,-1, 31,0);
    tracep->declBit(c+38,"WE3_i", false,-1);
    tracep->declBus(c+39,"RD1_o", false,-1, 31,0);
    tracep->declBus(c+40,"RD2_o", false,-1, 31,0);
    tracep->declBus(c+41,"A0_o", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"mem", true,(i+0), 31,0);
    }
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
    bufp->fullIData(oldp+1,(vlSelf->regfile__DOT__mem[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->regfile__DOT__mem[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->regfile__DOT__mem[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->regfile__DOT__mem[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->regfile__DOT__mem[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->regfile__DOT__mem[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->regfile__DOT__mem[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->regfile__DOT__mem[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->regfile__DOT__mem[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->regfile__DOT__mem[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->regfile__DOT__mem[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->regfile__DOT__mem[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->regfile__DOT__mem[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->regfile__DOT__mem[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->regfile__DOT__mem[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->regfile__DOT__mem[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->regfile__DOT__mem[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->regfile__DOT__mem[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->regfile__DOT__mem[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->regfile__DOT__mem[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->regfile__DOT__mem[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->regfile__DOT__mem[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->regfile__DOT__mem[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->regfile__DOT__mem[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->regfile__DOT__mem[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->regfile__DOT__mem[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->regfile__DOT__mem[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->regfile__DOT__mem[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->regfile__DOT__mem[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->regfile__DOT__mem[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->regfile__DOT__mem[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->regfile__DOT__mem[31]),32);
    bufp->fullBit(oldp+33,(vlSelf->clk_i));
    bufp->fullCData(oldp+34,(vlSelf->A1_i),5);
    bufp->fullCData(oldp+35,(vlSelf->A2_i),5);
    bufp->fullCData(oldp+36,(vlSelf->A3_i),5);
    bufp->fullIData(oldp+37,(vlSelf->WD3_i),32);
    bufp->fullBit(oldp+38,(vlSelf->WE3_i));
    bufp->fullIData(oldp+39,(vlSelf->RD1_o),32);
    bufp->fullIData(oldp+40,(vlSelf->RD2_o),32);
    bufp->fullIData(oldp+41,(vlSelf->A0_o),32);
    bufp->fullIData(oldp+42,(5U),32);
    bufp->fullIData(oldp+43,(0x20U),32);
}
