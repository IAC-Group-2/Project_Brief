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
    VL_IN8(RegWriteM_i,0,0);
    VL_OUT8(RegWriteW_o,0,0);
    VL_IN8(ResultSrcM_i,1,0);
    VL_OUT8(ResultSrcW_o,1,0);
    VL_IN8(RdM_i,4,0);
    VL_OUT8(RdW_o,4,0);
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(ALUResultM_i,31,0);
    VL_OUT(ALUResultW_o,31,0);
    VL_IN(ReadDataM_i,31,0);
    VL_OUT(ReadDataW_o,31,0);
    VL_IN(PCPlus4M_i,31,0);
    VL_OUT(PCPlus4W_o,31,0);

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
