#ifndef camino
#define camino

#include "Adder.h"
#include "instruction_memory.h"
#include "pc.h"
#include "register_if_id.h"
#include "control_unit.h"
#include "utils.h"
#include <systemc.h>
#include <iomanip>
/**
 * @class DataPath
 * @brief Clase que encapsula los modulos para lograr el DataPath de datos
 * encauzado o Data Path
 * @details ejecuta las operaciones correspondientes en cada ciclo de reloj
 */

class DataPath : public sc_module {
public:
  sc_in<bool> clkIn;
  SC_CTOR(DataPath);

  ~DataPath(); // Destructor

  // // cables sumador
   sc_signal<sc_uint<32>> SgInadd;
   sc_signal<sc_uint<32>> SgOutadd;

  // // cables IM
   sc_signal<sc_uint<32>> SgInim;
   sc_signal<string> SgOutim;

  // // cables pc
   sc_signal<sc_uint<32>> SgInPC;
   sc_signal<sc_uint<32>> SgOutPC;

  // // cables registros Encauzamiento
   sc_signal<sc_uint<32>> Sg_cpOutre;
   sc_signal<string> Sg_stringDOutre;

   //===================SEGUNDA ETAPA======================

   // cables de salida de la unidad de control
   sc_signal<sc_uint<5>> SgControlOut[4];
   sc_signal<sc_int<32>> SgValoresInmediatos[2];
   sc_signal<string> SgTagOut;


   Adder adder;
   InstructioMemory im;
   PC pc;
   RegisterIFID re;
   ControlUnit cu;

   private:

   void log();
   void test();

};

#endif // !camino