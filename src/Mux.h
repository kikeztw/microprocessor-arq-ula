#ifndef MUX_CP_H
#define MUX_CP_H

#include <systemc.h>


class Mux: public sc_module {
public:
  sc_in<sc_uint<32>> aIn, bIn;
  sc_in<bool> s0In;
  sc_out<sc_uint<32>> cOut;

  SC_CTOR(Mux);

private:
  // En ésta función se realizará la operación de mux.
  void operation();
};

#endif
