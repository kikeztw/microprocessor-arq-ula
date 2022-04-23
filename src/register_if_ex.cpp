#include "register_if_ex.h"

RegisterIFEX::RegisterIFEX(sc_module_name nm) : sc_module(nm) {
  tagIn = "";
  rRg1Store = 0;
  rRg2InStore = 0;
  cpSt = 0;
  immStore = 0;
  immStore2 = 0;
  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();
  

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterIFEX::read() {
  string temptag;

  // tag
  temptag.set(tagStore);
  tagOut.write(temptag);

  // PC and Imm
  cpOut.write(cpStore);
  immOut.write(immStore);
  immOut2.write(immStore2);
  rd1Out.write(rRg1Store);
  rd2Out.write(rRg2InStore);
}

void RegisterIFEX::write() {
  // register 1 and 2
  tagStore = tagIn.read().str;
  // PC write
  cpStore = cpIn.read();
  // imm input
  immStore = immIn.read();
  immStore2 = immIn2.read();
  rRg1Store = rRg1In.read();
  rRg2InStore = rRg2In.read();
}
