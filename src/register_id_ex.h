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
  sc_in<string> tagIn;
  sc_in<sc_uint<32>> immIn, immIn2,cpIn, rRg1In, rRg2In;
  // output
  sc_out<sc_uint<32>> cpOut, immOut, immOut2, rd1Out, rd2Out;
  sc_out<string> tagOut;

  SC_CTOR(RegisterIFEX);
private:
  std::string tagStore;
  sc_uint<32> cpStore, immStore, immStore2, rRg1Store, rRg2InStore;
  void read();
  void write();
};

#endif
