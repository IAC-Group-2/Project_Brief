// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"

class Vdut__Syms;

class Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(op_i,6,0);
    VL_IN8(funct3_i,2,0);
    VL_IN8(funct7_i,6,0);
    VL_OUT8(RegWrite_o,0,0);
    VL_OUT8(MemWrite_o,0,0);
    VL_OUT8(ALUControl_o,3,0);
    VL_OUT8(ALUSrc_o,0,0);
    VL_OUT8(ALUSrcA_o,0,0);
    VL_OUT8(ImmSrc_o,2,0);
    VL_OUT8(ResultSrc_o,1,0);
    VL_OUT8(Jump_o,0,0);
    VL_OUT8(Branch_o,0,0);
    CData/*0:0*/ control_unit__DOT__branch;
    CData/*1:0*/ control_unit__DOT__ALUOp;
    CData/*0:0*/ control_unit__DOT__jump;
    CData/*0:0*/ control_unit__DOT__jalr;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
