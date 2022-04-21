#include "Testbench.h"
#include <iomanip>
#include <sysc/datatypes/int/sc_uint.h>
#include <sysc/kernel/sc_simcontext.h>
// #include "register_file.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {
  std::cout << "time  clkIN  Cp  Block" << std::endl;
  std::cout << std::setw(4) << sc_time_stamp() << std::setw(4) << clkIn.read()
            << std::setw(5) << Sg_cpIntre.read() << std::setw(4)
            << Sg_stringDInre.read().get() << "  " << std::endl;
}

void Testbench::test() {
  SgOutPC->write(0);
  print();
  wait();
  SgOutPC->write(1);
  print();
  sc_stop();
}
