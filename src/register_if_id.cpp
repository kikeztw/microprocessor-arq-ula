#include "register_if_id.h"

RegisterIFID::RegisterIFID(sc_module_name nm) : sc_module(nm) {

  insSt = "";
  cpSt = 0;
  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterIFID::read() {
  string s;
  s.set(insSt);
  cpOut.write(cpSt);
  insOut.write(s);
}

void RegisterIFID::write() {
  insSt = insIn.read().str;
  cpSt = cpIn.read();
}
