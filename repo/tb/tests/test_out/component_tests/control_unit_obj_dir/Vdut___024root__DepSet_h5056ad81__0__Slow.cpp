// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
}

void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vdut___024root___final(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___final\n"); );
}

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->op_i = VL_RAND_RESET_I(7);
    vlSelf->funct3_i = VL_RAND_RESET_I(3);
    vlSelf->funct7_i = VL_RAND_RESET_I(7);
    vlSelf->RegWrite_o = VL_RAND_RESET_I(1);
    vlSelf->MemWrite_o = VL_RAND_RESET_I(1);
    vlSelf->ALUControl_o = VL_RAND_RESET_I(4);
    vlSelf->ALUSrc_o = VL_RAND_RESET_I(1);
    vlSelf->ALUSrcA_o = VL_RAND_RESET_I(1);
    vlSelf->ImmSrc_o = VL_RAND_RESET_I(3);
    vlSelf->ResultSrc_o = VL_RAND_RESET_I(2);
    vlSelf->Jump_o = VL_RAND_RESET_I(1);
    vlSelf->Branch_o = VL_RAND_RESET_I(1);
    vlSelf->control_unit__DOT__branch = VL_RAND_RESET_I(1);
    vlSelf->control_unit__DOT__ALUOp = VL_RAND_RESET_I(2);
    vlSelf->control_unit__DOT__jump = VL_RAND_RESET_I(1);
    vlSelf->control_unit__DOT__jalr = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
