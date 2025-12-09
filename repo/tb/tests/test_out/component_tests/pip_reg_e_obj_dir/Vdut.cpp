// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdut.h"
#include "Vdut__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdut::Vdut(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdut__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , clr_i{vlSymsp->TOP.clr_i}
    , en_i{vlSymsp->TOP.en_i}
    , RegWriteD_i{vlSymsp->TOP.RegWriteD_i}
    , RegWriteE_o{vlSymsp->TOP.RegWriteE_o}
    , ResultSrcD_i{vlSymsp->TOP.ResultSrcD_i}
    , ResultSrcE_o{vlSymsp->TOP.ResultSrcE_o}
    , MemWriteD_i{vlSymsp->TOP.MemWriteD_i}
    , MemWriteE_o{vlSymsp->TOP.MemWriteE_o}
    , JumpD_i{vlSymsp->TOP.JumpD_i}
    , JumpE_o{vlSymsp->TOP.JumpE_o}
    , BranchD_i{vlSymsp->TOP.BranchD_i}
    , BranchE_o{vlSymsp->TOP.BranchE_o}
    , ALUControlD_i{vlSymsp->TOP.ALUControlD_i}
    , ALUControlE_o{vlSymsp->TOP.ALUControlE_o}
    , ALUSrcAD_i{vlSymsp->TOP.ALUSrcAD_i}
    , ALUSrcAE_o{vlSymsp->TOP.ALUSrcAE_o}
    , funct3D_i{vlSymsp->TOP.funct3D_i}
    , funct3E_o{vlSymsp->TOP.funct3E_o}
    , ALUSrcD_i{vlSymsp->TOP.ALUSrcD_i}
    , ALUSrcE_o{vlSymsp->TOP.ALUSrcE_o}
    , Rs1D_i{vlSymsp->TOP.Rs1D_i}
    , Rs1E_o{vlSymsp->TOP.Rs1E_o}
    , Rs2D_i{vlSymsp->TOP.Rs2D_i}
    , Rs2E_o{vlSymsp->TOP.Rs2E_o}
    , RdD_i{vlSymsp->TOP.RdD_i}
    , RdE_o{vlSymsp->TOP.RdE_o}
    , RD1D_i{vlSymsp->TOP.RD1D_i}
    , RD1E_o{vlSymsp->TOP.RD1E_o}
    , RD2D_i{vlSymsp->TOP.RD2D_i}
    , RD2E_o{vlSymsp->TOP.RD2E_o}
    , PCD_i{vlSymsp->TOP.PCD_i}
    , PCE_o{vlSymsp->TOP.PCE_o}
    , ImmExtD_i{vlSymsp->TOP.ImmExtD_i}
    , ImmExtE_o{vlSymsp->TOP.ImmExtE_o}
    , PCPlus4D_i{vlSymsp->TOP.PCPlus4D_i}
    , PCPlus4E_o{vlSymsp->TOP.PCPlus4E_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdut::Vdut(const char* _vcname__)
    : Vdut(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdut::~Vdut() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdut___024root___eval_initial(Vdut___024root* vlSelf);
void Vdut___024root___eval_settle(Vdut___024root* vlSelf);
void Vdut___024root___eval(Vdut___024root* vlSelf);
#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
void Vdut___024root___final(Vdut___024root* vlSelf);

static void _eval_initial_loop(Vdut__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdut___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdut___024root___eval_settle(&(vlSymsp->TOP));
        Vdut___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vdut::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdut::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdut___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdut___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vdut::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdut::final() {
    Vdut___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdut::hierName() const { return vlSymsp->name(); }
const char* Vdut::modelName() const { return "Vdut"; }
unsigned Vdut::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdut::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdut___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdut::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdut___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
