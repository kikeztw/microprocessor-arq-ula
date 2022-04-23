#ifndef REGISTER_IF_EX_H
#define REGISTER_IF_EX_H

#include "utils.h"
#include <string>
#include <systemc.h>

class RegisterIFEX : public sc_module {
public:
  
  // clock
  sc_in<bool> clkIn;
  // input
  sc_in<sc_int<32>> rRg1In, rRg2In;
  sc_in<sc_int<32>> immIn, immIn2,cpIn;
  // output
  sc_out<sc_int<32>> cpOut, immOut, immOut2;
  sc_out<sc_int<32>> rd1Out, rd2Out;

  SC_CTOR(RegisterIFEX);
private:
  std::string rRg1Store, rRg2InStore;
  sc_uint<32> cpStore, immStore, immStore2;
  void read();
  void write();
};

#endif
