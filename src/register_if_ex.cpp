#include "register_if_ex.h"

RegisterIFEX::RegisterIFEX(sc_module_name nm) : sc_module(nm) {

  rRg1Store = "";
  rRg2InStore = "";
  cpSt = 0;
  immStore = 0;
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
  string tempRRg1In, tempoRRg2In;

  tempRRg1In.set(rRg1Store);
  tempoRRg2In.set(rRg2InStore);

  rd1Out.write(tempRRg1In);
  rd2Out.write(tempoRRg2In);

  // PC and Imm
  cpOut.write(cpStore);
  immOut.write(immStore);
}

void RegisterIFEX::write() {
  // register 1 and 2
  rRg1Store = rRg1In.read().str;
  rRg2InStore = rRg2In.read().str;
  // PC write
  cpStore = cpIn.read();
  // imm input
  immStore = immIn.read();
}
