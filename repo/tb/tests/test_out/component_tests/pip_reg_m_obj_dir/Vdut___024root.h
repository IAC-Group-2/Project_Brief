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
    VL_IN8(en_i,0,0);
    VL_IN8(RegWriteE_i,0,0);
    VL_OUT8(RegWriteM_o,0,0);
    VL_IN8(ResultSrcE_i,1,0);
    VL_OUT8(ResultSrcM_o,1,0);
    VL_IN8(MemWriteE_i,0,0);
    VL_OUT8(MemWriteM_o,0,0);
    VL_IN8(funct3E_i,2,0);
    VL_OUT8(funct3M_o,2,0);
    VL_IN8(RdE_i,4,0);
    VL_OUT8(RdM_o,4,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(ALUResultE_i,31,0);
    VL_OUT(ALUResultM_o,31,0);
    VL_IN(WriteDataE_i,31,0);
    VL_OUT(WriteDataM_o,31,0);
    VL_IN(PCPlus4E_i,31,0);
    VL_OUT(PCPlus4M_o,31,0);

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
