#include "Adder.h"

Adder::Adder(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << sIn;
}

void Adder::operation() {
  std::cout << "estoy en sumador" << std::endl;
  sOut.write(sIn.read() + 1);
}
