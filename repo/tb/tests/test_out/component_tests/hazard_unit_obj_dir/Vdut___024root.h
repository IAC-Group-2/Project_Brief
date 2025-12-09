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
    VL_IN8(Rs1D_i,4,0);
    VL_IN8(Rs2D_i,4,0);
    VL_IN8(Rs1E_i,4,0);
    VL_IN8(Rs2E_i,4,0);
    VL_IN8(RdE_i,4,0);
    VL_IN8(ResultSrcE0_i,0,0);
    VL_IN8(RdM_i,4,0);
    VL_IN8(RegWriteM_i,0,0);
    VL_IN8(RdW_i,4,0);
    VL_IN8(RegWriteW_i,0,0);
    VL_IN8(PCSrcE_i,0,0);
    VL_IN8(CacheStall_i,0,0);
    VL_OUT8(ForwardAE_o,1,0);
    VL_OUT8(ForwardBE_o,1,0);
    VL_OUT8(StallF_o,0,0);
    VL_OUT8(StallD_o,0,0);
    VL_OUT8(StallE_o,0,0);
    VL_OUT8(StallM_o,0,0);
    VL_OUT8(StallW_o,0,0);
    VL_OUT8(FlushD_o,0,0);
    VL_OUT8(FlushE_o,0,0);
    CData/*0:0*/ hazard_unit__DOT__lwStall;

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
