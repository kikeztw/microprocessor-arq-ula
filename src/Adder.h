#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder : public sc_module {
public:
  sc_in<sc_uint<32>> sIn;
  sc_out<sc_uint<32>> sOut;

  SC_CTOR(Adder);

private:
  void operation();
};

#endif
