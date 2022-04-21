#include "Testbench.h"
#include <iomanip>
#include <sysc/datatypes/int/sc_uint.h>
// #include "register_file.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {
  std::cout << Sg_cpIntre.read() << std::endl;
  std::cout << Sg_stringDInre.read() << std::endl;
}

void Testbench::test() {
  SgOutPC->write(0);
  print();
  sc_stop();
}
