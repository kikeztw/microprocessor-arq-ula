#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include "utils.h"
#include <map>
#include <string>
#include <systemc.h>

class DataMemory : public sc_module {
public:
  sc_in<sc_uint<5>> opCodeIn;
  sc_in<sc_uint<32>> addressIn; // direccion donde se va escribir
  sc_in<sc_int<32>> valueIn;    // valor de lo que se va a escribir
  sc_out<sc_int<32>> valueOut;  // dato que se lee

  std::vector<int> L1_D;
  // std::map<std::string, int> labels;

  SC_CTOR(DataMemory);

private:
  void op();
};

#endif
