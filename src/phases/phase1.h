#ifndef PHASE_1_H
#define PHASE_1_H

#include <sysc/communication/sc_clock.h>
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

  // cables registros Encauzamiento
  sc_signal<sc_uint<32>> Sg_cpOutre;
  sc_signal<string> Sg_stringDOutre;

  Adder adder;
  InstructioMemory im;
  PC pc;
  RegisterIFID re;

 private:
  void log();
  void test();
};

#endif  // !
