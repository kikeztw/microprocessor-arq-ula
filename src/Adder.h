#ifndef ADDER_H
#define ADDER_H

#include <systemc.h>

class Adder: public sc_module{
  public:
    sc_in<sc_uint<32>> sIn;
    sc_out<bool> sOut;

    SC_CTOR(Adder);
  private:
    void operation();
};

#endif