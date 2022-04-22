#ifndef camino
#define camino

#include <sysc/communication/sc_clock.h>
#include <systemc.h>

#include "modules/phase1/Adder.h"
#include "modules/phase1/instruction_memory.h"
#include "modules/phase1/pc.h"
#include "modules/phase1/register_if_id.h"
#include "utils/utils.h"
/**
 * @class DataPath
 * @brief Clase que encapsula los modulos para lograr el DataPath de datos
 * encauzado o Data Path
 * @details ejecuta las operaciones correspondientes en cada ciclo de reloj
 */

class DataPath : public sc_module
{
 public:
  sc_in<bool> clkIn;
  SC_CTOR(DataPath);

  ~DataPath();  // Destructor

  // cables sumador
  sc_signal<sc_uint<32>> SgInadd;
  sc_signal<sc_uint<32>> SgOutadd;

  // cables IM
  sc_signal<sc_uint<32>> SgInim;
  sc_signal<string> SgOutim;

  // cables pc
  sc_signal<bool> clk;
  sc_in<sc_uint<32>> SgInPC;
  sc_signal<sc_uint<32>> SgOutPC;

  // cables registros Encauzamiento
  sc_out<sc_uint<32>> Sg_cpOutre;
  sc_out<string> Sg_stringDOutre;
  Adder adder;
  InstructioMemory im;
  PC pc;
  RegisterIFID re;

 private:
  // void IF();
  // void ID();
  // void EX();
  // void MEM();
  // void WB();
};

#endif  // !camino
