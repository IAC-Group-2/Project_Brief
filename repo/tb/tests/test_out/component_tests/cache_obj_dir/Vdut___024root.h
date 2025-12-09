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
    VL_IN8(rst_i,0,0);
    VL_IN8(MemWriteM_i,0,0);
    VL_IN8(ResultSrcM_i,1,0);
    VL_IN8(funct3_i,2,0);
    VL_OUT8(mem_wr_en_o,0,0);
    VL_OUT8(funct3_o,2,0);
    VL_OUT8(cache_miss_o,0,0);
    VL_OUT8(stall_o,0,0);
    CData/*0:0*/ cache__DOT__cache_en;
    CData/*0:0*/ cache__DOT__tag_0_hit;
    CData/*0:0*/ cache__DOT__tag_1_hit;
    CData/*0:0*/ cache__DOT__cache_miss;
    CData/*0:0*/ cache__DOT__cache_hit;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_IN(addr_i,31,0);
    VL_IN(data_i,31,0);
    VL_IN(mem_rd_data_i,31,0);
    VL_OUT(mem_addr_o,31,0);
    VL_OUT(mem_wr_data_o,31,0);
    VL_OUT(data_o,31,0);
    IData/*31:0*/ cache__DOT__current_state;
    IData/*31:0*/ cache__DOT__next_state;
    VlWide<4>/*112:0*/ cache__DOT__cache_set;
    IData/*31:0*/ cache__DOT__raw_cache_data;
    IData/*31:0*/ cache__DOT__raw_mem_data;
    IData/*31:0*/ cache__DOT__unnamedblk1__DOT__i;
    VlUnpacked<VlWide<4>/*112:0*/, 256> cache__DOT__cache_array;
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
