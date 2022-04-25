#ifndef REGISTER_EX_MEM_H
#define REGISTER_EX_MEM_H

#include "utils.h"
#include <string>
#include <systemc.h>

class RegisterEXMEM : public sc_module {
public:
  
  // input
  sc_in<sc_uint<5>> rwIn, ctrlIn;
  sc_in<sc_int<32>> addIn, aluIn;
  sc_in<bool> clkIn, zeroFlagIn;
  // output
  sc_out<sc_int<32>> addOut, aluOut;
  sc_out<sc_uint<5>> rwOut, ctrlOut;
  sc_out<bool> zeroFlagOut;

  SC_CTOR(RegisterEXMEM);
private:
  // std::string tagStore;
  sc_int<32> addStore, aluStore;
  sc_uint<5> rwStore, ctrlStore;
  sc_out<bool> zeroFlagStore;

  void read();
  void write();
};

#endif
