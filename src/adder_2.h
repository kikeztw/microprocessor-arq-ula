#ifndef ADDER_2_H
#define ADDER_2_H

#include <systemc.h>
#include "utils.h"

class Adder2 : public sc_module {
public:
  sc_in<string> sIn;
  sc_out<sc_uint<32>> sOut;

  SC_CTOR(Adder2);

private:
  void operation();
  bool isNumber(const std::string& str);
};

#endif