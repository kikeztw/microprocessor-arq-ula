#include "Adder.h"

Adder::Adder(sc_module_name nm) : sc_module(nm)
{
  SC_METHOD(operation);
  sensitive << sIn;
}

void Adder::operation()
{
  std::cout << sc_time_stamp() << "  adder write:" << (sIn.read() + 1) << "\n";
  sOut.write(sIn.read() + 1);
}
