#ifndef MUX_WB_H
#define MUX_WB_H

#include "utils.h"
#include <map>
#include <string>
#include <systemc.h>

class MuxWB : public sc_module {
public:
  
  sc_in<sc_uint<5>> opCodeIn;
  sc_in<sc_int<32>> readDataIn;
  sc_in<sc_int<32>> resultAluIn;

  sc_out<sc_int<32>> resultOut;
  

  SC_CTOR(MuxWB);

private:
  void op();
};

#endif