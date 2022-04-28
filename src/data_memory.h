#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <map>
#include <string>
#include <systemc.h>

class DataMemory : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in<sc_uint<5>> rwIn; // direccion donde se va escribir
  sc_in<sc_int<32>> wIn;  // valor de lo que se va a escribir

  sc_out<sc_int<32>> rwOut; // dato que se lee
  // que tamanio ???

  std::vector<int> L1_D;

  std::map<std::string, int> labels;
  SC_CTOR(DataMemory);

private:
  void read();
  void write();
};

#endif
