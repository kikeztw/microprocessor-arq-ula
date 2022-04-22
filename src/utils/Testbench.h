#ifndef TESTBENCH_H

#include "utils.h"
#include <sysc/communication/sc_signal_ports.h>
#include <sysc/utils/sc_vector.h>
#include <systemc.h>

class Testbench : public sc_module {
public:
  sc_out<sc_uint<32>> SgOutPC;
  sc_in<sc_uint<32>> Sg_cpIntre;
  sc_in<string> Sg_stringDInre;
  sc_in<bool> clkIn;
  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif // !TESTBENCH_H
