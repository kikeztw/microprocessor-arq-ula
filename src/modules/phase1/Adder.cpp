#include "Adder.h"

#include <sysc/kernel/sc_simcontext.h>

Adder::Adder(sc_module_name nm) : sc_module(nm)
{
  SC_METHOD(operation);
  sensitive << sIn;
  // dont_initialize();
}

void Adder::operation()
{
  sOut.write(sIn.read() + 1);
}
