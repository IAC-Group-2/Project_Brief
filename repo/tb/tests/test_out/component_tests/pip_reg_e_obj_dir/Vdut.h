// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VDUT_H_
#define VERILATED_VDUT_H_  // guard

#include "verilated.h"

class Vdut__Syms;
class Vdut___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class Vdut VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vdut__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_i,0,0);
    VL_IN8(&clr_i,0,0);
    VL_IN8(&en_i,0,0);
    VL_IN8(&RegWriteD_i,0,0);
    VL_OUT8(&RegWriteE_o,0,0);
    VL_IN8(&ResultSrcD_i,1,0);
    VL_OUT8(&ResultSrcE_o,1,0);
    VL_IN8(&MemWriteD_i,0,0);
    VL_OUT8(&MemWriteE_o,0,0);
    VL_IN8(&JumpD_i,0,0);
    VL_OUT8(&JumpE_o,0,0);
    VL_IN8(&BranchD_i,0,0);
    VL_OUT8(&BranchE_o,0,0);
    VL_IN8(&ALUControlD_i,3,0);
    VL_OUT8(&ALUControlE_o,3,0);
    VL_IN8(&ALUSrcAD_i,0,0);
    VL_OUT8(&ALUSrcAE_o,0,0);
    VL_IN8(&funct3D_i,2,0);
    VL_OUT8(&funct3E_o,2,0);
    VL_IN8(&ALUSrcD_i,0,0);
    VL_OUT8(&ALUSrcE_o,0,0);
    VL_IN8(&Rs1D_i,4,0);
    VL_OUT8(&Rs1E_o,4,0);
    VL_IN8(&Rs2D_i,4,0);
    VL_OUT8(&Rs2E_o,4,0);
    VL_IN8(&RdD_i,4,0);
    VL_OUT8(&RdE_o,4,0);
    VL_IN(&RD1D_i,31,0);
    VL_OUT(&RD1E_o,31,0);
    VL_IN(&RD2D_i,31,0);
    VL_OUT(&RD2E_o,31,0);
    VL_IN(&PCD_i,31,0);
    VL_OUT(&PCE_o,31,0);
    VL_IN(&ImmExtD_i,31,0);
    VL_OUT(&ImmExtE_o,31,0);
    VL_IN(&PCPlus4D_i,31,0);
    VL_OUT(&PCPlus4E_o,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vdut___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vdut(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vdut(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vdut();
  private:
    VL_UNCOPYABLE(Vdut);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
