#ifndef camino
#define camino

// modules
#include "Adder.h"
#include "instruction_memory.h"
#include "pc.h"
#include "control_unit.h"
#include "alu.h"
#include "adder_2.h"
#include "register_file.h"
// registro de encauzamiento
#include "register_if_id.h"
#include "register_id_ex.h"
#include "register_ex_mem.h"
// utils
#include "utils.h"
// default
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

   // cables de write back
    sc_signal<sc_uint<5>> sgRwRb;
    sc_signal<sc_int<32>> sgWRb;
   // cable archivos de registros
    sc_signal<sc_int<32>> sgRfOut[2];

   // cables salidas de registros ID/EX
   sc_signal<sc_int<32>> sgReIDEXValues[2];
   sc_signal<sc_uint<32>> sgReIDEXCp;
   sc_signal<sc_uint<5>> sgReIDEXRw, sgReIDEXCtrl;
   sc_signal<string> sgReIDEXTag;
   //cable salida adder2
   sc_signal<sc_uint<32>> sgAdder2Out; // <-----

   //===================TERCERA ETAPA======================

    //sc_signal<sc_uint<4>> sOpAlu;
    sc_signal<bool> sgZero;
    sc_signal<sc_int<32>> sgResult;

    sc_signal<sc_int<32>> sgEXMEMaluOut;
    sc_signal<sc_uint<32>> sgEXMEMaddOut;
    sc_signal<sc_uint<5>> sgEXMEMrwOut, sgEXMEMctrlOut;
    sc_signal<bool> sgEXMEMzeroFlagOut;
  
    // modules
    Adder adder;
    RegisterFile rf;
    InstructioMemory im;
    PC pc;
    ControlUnit cu;
    Adder2 adder2;
    ALU alu;
    // registros de encauzamiento
    RegisterIFID re;
    RegisterIDEX reIDEX;
    RegisterEXMEM reEXMEM;
   

  private:

   void log();
   void test();

};

#endif // !camino
