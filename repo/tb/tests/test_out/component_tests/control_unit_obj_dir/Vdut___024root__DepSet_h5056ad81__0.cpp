// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "verilated.h"

#include "Vdut___024root.h"

extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h2b8877be_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h45afa79b_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h17877086_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hbad56271_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_hf6daef67_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vdut__ConstPool__TABLE_h4aacde2d_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_hff092405_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h43bc9916_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vdut__ConstPool__TABLE_h087dd5e0_0;
extern const VlUnpacked<CData/*1:0*/, 1024> Vdut__ConstPool__TABLE_hfcca2a75_0;

VL_INLINE_OPT void Vdut___024root___combo__TOP__0(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___combo__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vtableidx1;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->funct3_i) << 7U) 
                    | (IData)(vlSelf->op_i));
    vlSelf->RegWrite_o = Vdut__ConstPool__TABLE_h2b8877be_0
        [__Vtableidx1];
    vlSelf->MemWrite_o = Vdut__ConstPool__TABLE_h45afa79b_0
        [__Vtableidx1];
    vlSelf->ALUSrc_o = Vdut__ConstPool__TABLE_h17877086_0
        [__Vtableidx1];
    vlSelf->ALUSrcA_o = Vdut__ConstPool__TABLE_hbad56271_0
        [__Vtableidx1];
    vlSelf->ResultSrc_o = Vdut__ConstPool__TABLE_hf6daef67_0
        [__Vtableidx1];
    vlSelf->ImmSrc_o = Vdut__ConstPool__TABLE_h4aacde2d_0
        [__Vtableidx1];
    vlSelf->control_unit__DOT__branch = Vdut__ConstPool__TABLE_hff092405_0
        [__Vtableidx1];
    vlSelf->control_unit__DOT__jump = Vdut__ConstPool__TABLE_h43bc9916_0
        [__Vtableidx1];
    vlSelf->control_unit__DOT__jalr = Vdut__ConstPool__TABLE_h087dd5e0_0
        [__Vtableidx1];
    vlSelf->control_unit__DOT__ALUOp = Vdut__ConstPool__TABLE_hfcca2a75_0
        [__Vtableidx1];
    vlSelf->Branch_o = vlSelf->control_unit__DOT__branch;
    vlSelf->Jump_o = ((IData)(vlSelf->control_unit__DOT__jump) 
                      | (IData)(vlSelf->control_unit__DOT__jalr));
    vlSelf->ALUControl_o = ((2U & (IData)(vlSelf->control_unit__DOT__ALUOp))
                             ? ((1U & (IData)(vlSelf->control_unit__DOT__ALUOp))
                                 ? 0xfU : ((4U & (IData)(vlSelf->funct3_i))
                                            ? ((2U 
                                                & (IData)(vlSelf->funct3_i))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->funct3_i))
                                                    ? 2U
                                                    : 3U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->funct3_i))
                                                    ? 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->op_i)) 
                                                     & (0x20U 
                                                        == (IData)(vlSelf->funct7_i)))
                                                     ? 7U
                                                     : 6U)
                                                    : 4U))
                                            : ((2U 
                                                & (IData)(vlSelf->funct3_i))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->funct3_i))
                                                    ? 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->op_i)) 
                                                     & (1U 
                                                        == (IData)(vlSelf->funct7_i)))
                                                     ? 0xdU
                                                     : 9U)
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->op_i)) 
                                                     & (1U 
                                                        == (IData)(vlSelf->funct7_i)))
                                                     ? 0xcU
                                                     : 8U))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->funct3_i))
                                                    ? 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->op_i)) 
                                                     & (1U 
                                                        == (IData)(vlSelf->funct7_i)))
                                                     ? 0xbU
                                                     : 5U)
                                                    : 
                                                   (((0x33U 
                                                      == (IData)(vlSelf->op_i)) 
                                                     & (1U 
                                                        == (IData)(vlSelf->funct7_i)))
                                                     ? 0xaU
                                                     : 
                                                    (((0x33U 
                                                       == (IData)(vlSelf->op_i)) 
                                                      & (0x20U 
                                                         == (IData)(vlSelf->funct7_i)))
                                                      ? 1U
                                                      : 0U))))))
                             : ((1U & (IData)(vlSelf->control_unit__DOT__ALUOp))
                                 ? 1U : 0U));
}

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    // Body
    Vdut___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->op_i & 0x80U))) {
        Verilated::overWidthError("op_i");}
    if (VL_UNLIKELY((vlSelf->funct3_i & 0xf8U))) {
        Verilated::overWidthError("funct3_i");}
    if (VL_UNLIKELY((vlSelf->funct7_i & 0x80U))) {
        Verilated::overWidthError("funct7_i");}
}
#endif  // VL_DEBUG
