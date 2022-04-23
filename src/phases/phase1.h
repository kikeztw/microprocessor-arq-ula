#ifndef PHASE_1_H
#define PHASE_1_H

#include <sysc/communication/sc_clock.h>
#include <sysc/communication/sc_signal.h>
#include <systemc.h>

#include "../modules/phase1/Adder.h"
#include "../modules/phase1/instruction_memory.h"
#include "../modules/phase1/pc.h"
#include "../modules/phase1/register_if_id.h"
#include "../utils/utils.h"
/**
 * @class CIF
 * @brief Clase que encapsula los modulos para lograr el CIF de datos
 * encauzado o Data Path
 * @details ejecuta las operaciones correspondientes en cada ciclo de reloj
 */

class CIF : public sc_module
{
 public:
  sc_in<bool> clkIn;
  SC_CTOR(CIF);

  ~CIF();  // Destructor

  // // cables sumador
  sc_signal<sc_uint<32>> SgInadd;
  sc_signal<sc_uint<32>> SgOutadd;

  // cables IM
  sc_signal<sc_uint<32>> SgInim;
  sc_signal<string> SgOutim;

  // cables pc
  sc_signal<bool> clk;
  sc_signal<sc_uint<32>> SgInPC;
  sc_signal<sc_uint<32>> SgOutPC;
  sc_signal<sc_uint<5>> Sgop;
  sc_signal<sc_uint<5>> Sgrd;
  sc_signal<sc_uint<5>> Sgrs1;
  sc_signal<sc_uint<5>> Sgrs2;
  sc_signal<sc_uint<32>> Sgimm;

  // cables registros Encauzamiento
  sc_signal<sc_uint<32>> Sg_cpOutre;
  sc_signal<string> Sg_stringDOutre;
  sc_signal<sc_uint<5>> SgopOut;
  sc_signal<sc_uint<5>> SgrdOut;
  sc_signal<sc_uint<5>> Sgrs1Out;
  sc_signal<sc_uint<5>> Sgrs2Out;
  sc_signal<sc_uint<32>> SgimmOut;

  Adder adder;
  InstructioMemory im;
  PC pc;
  RegisterIFID re;

 private:
  void log();
  void test();
};

#endif  // !
