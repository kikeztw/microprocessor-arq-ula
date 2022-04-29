#ifndef MUX_WB_H
#define MUX_WB_H

#include "utils.h"
#include <map>
#include <string>
#include <systemc.h>

class MuxWB : public sc_module {
public:
  sc_in<sc_uint<5>> opCodeIn;    // me indica si  cual de los dos mandar
  sc_in<sc_int<32>> readDataIn;  // viene de la cache datos
  sc_in<sc_int<32>> resultAluIn; // viene del resultado de la alu

  sc_out<sc_int<32>> resultOut; // salida

  SC_CTOR(MuxWB);

private:
  void op();
};

#endif
