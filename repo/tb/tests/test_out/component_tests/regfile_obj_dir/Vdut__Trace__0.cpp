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
        bufp->chgIData(oldp+0,(vlSelf->regfile__DOT__mem[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->regfile__DOT__mem[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->regfile__DOT__mem[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->regfile__DOT__mem[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->regfile__DOT__mem[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->regfile__DOT__mem[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->regfile__DOT__mem[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->regfile__DOT__mem[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->regfile__DOT__mem[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->regfile__DOT__mem[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->regfile__DOT__mem[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->regfile__DOT__mem[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->regfile__DOT__mem[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->regfile__DOT__mem[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->regfile__DOT__mem[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->regfile__DOT__mem[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->regfile__DOT__mem[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->regfile__DOT__mem[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->regfile__DOT__mem[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->regfile__DOT__mem[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->regfile__DOT__mem[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->regfile__DOT__mem[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->regfile__DOT__mem[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->regfile__DOT__mem[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->regfile__DOT__mem[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->regfile__DOT__mem[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->regfile__DOT__mem[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->regfile__DOT__mem[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->regfile__DOT__mem[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->regfile__DOT__mem[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->regfile__DOT__mem[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->regfile__DOT__mem[31]),32);
    }
    bufp->chgBit(oldp+32,(vlSelf->clk_i));
    bufp->chgCData(oldp+33,(vlSelf->A1_i),5);
    bufp->chgCData(oldp+34,(vlSelf->A2_i),5);
    bufp->chgCData(oldp+35,(vlSelf->A3_i),5);
    bufp->chgIData(oldp+36,(vlSelf->WD3_i),32);
    bufp->chgBit(oldp+37,(vlSelf->WE3_i));
    bufp->chgIData(oldp+38,(vlSelf->RD1_o),32);
    bufp->chgIData(oldp+39,(vlSelf->RD2_o),32);
    bufp->chgIData(oldp+40,(vlSelf->A0_o),32);
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
