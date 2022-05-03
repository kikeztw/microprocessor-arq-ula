#include "Cell.h"

Cell::Cell(sc_module_name nm) : sc_module(nm) {
  storage = 0;

  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg() << wIn;

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void Cell::read() { dataOut.write(storage); }

void Cell::write() {
  // if (weIn.read())
  storage = wIn.read();
}
