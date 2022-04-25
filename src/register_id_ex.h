#ifndef REGISTER_IF_EX_H
#define REGISTER_IF_EX_H

#include "utils.h"
#include <string>
#include <systemc.h>

class RegisterIDEX : public sc_module {
public:
  
  // clock
  sc_in<bool> clkIn;
  // input
  sc_in<string> tagIn;
  sc_in<sc_int<32>> immIn, immIn2, rRg1In, rRg2In;
  sc_in<sc_uint<32>> cpIn;
  sc_in<sc_uint<5>> rwIn, ctrlIn;
  // output
  sc_out<sc_int<32>> aOut, bOut;
  sc_out<sc_uint<32>> cpOut;
  sc_out<string> tagOut;
  sc_out<sc_uint<5>> rwOut, ctrlOut;

  SC_CTOR(RegisterIDEX);
private:
  std::string tagStore;
  sc_int<32> aStore, bStore;
  sc_uint<32> cpStore;
  sc_uint<5> rwStore, ctrlStore;

  void read();
  void write();
};

#endif
