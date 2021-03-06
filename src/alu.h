
#ifndef ALU_H
#define ALU_H

#include "utils.h"
#include <systemc.h>

class ALU : public sc_module {
public:
  SC_CTOR(ALU) {
    SC_METHOD(operation);
    sensitive << opA << opB << op;
  }
  sc_in<sc_uint<5>> op;
  sc_in<sc_int<32>> opA, opB;
  sc_out<bool> zero;
  sc_out<sc_int<32>> result;

  // ~ALU(); // Destructor
private:
  void operation();
};

#endif // !camino
