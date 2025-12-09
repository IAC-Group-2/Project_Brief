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
    VL_IN8(clk_i,0,0);
    VL_IN8(clr_i,0,0);
    VL_IN8(en_i,0,0);
    VL_IN8(RegWriteD_i,0,0);
    VL_OUT8(RegWriteE_o,0,0);
    VL_IN8(ResultSrcD_i,1,0);
    VL_OUT8(ResultSrcE_o,1,0);
    VL_IN8(MemWriteD_i,0,0);
    VL_OUT8(MemWriteE_o,0,0);
    VL_IN8(JumpD_i,0,0);
    VL_OUT8(JumpE_o,0,0);
    VL_IN8(BranchD_i,0,0);
    VL_OUT8(BranchE_o,0,0);
    VL_IN8(ALUControlD_i,3,0);
    VL_OUT8(ALUControlE_o,3,0);
    VL_IN8(ALUSrcAD_i,0,0);
    VL_OUT8(ALUSrcAE_o,0,0);
    VL_IN8(funct3D_i,2,0);
    VL_OUT8(funct3E_o,2,0);
    VL_IN8(ALUSrcD_i,0,0);
    VL_OUT8(ALUSrcE_o,0,0);
    VL_IN8(Rs1D_i,4,0);
    VL_OUT8(Rs1E_o,4,0);
    VL_IN8(Rs2D_i,4,0);
    VL_OUT8(Rs2E_o,4,0);
    VL_IN8(RdD_i,4,0);
    VL_OUT8(RdE_o,4,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(RD1D_i,31,0);
    VL_OUT(RD1E_o,31,0);
    VL_IN(RD2D_i,31,0);
    VL_OUT(RD2E_o,31,0);
    VL_IN(PCD_i,31,0);
    VL_OUT(PCE_o,31,0);
    VL_IN(ImmExtD_i,31,0);
    VL_OUT(ImmExtE_o,31,0);
    VL_IN(PCPlus4D_i,31,0);
    VL_OUT(PCPlus4E_o,31,0);

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
