#include "register_ex_mem.h"

RegisterEXMEM::RegisterEXMEM(sc_module_name nm) : sc_module(nm) {
  addStore = 0;
  aluStore = 0;
  rwStore = 0;
  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();
  

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterEXMEM::read() {
  //valores
  addOut.write(addStore);
  aluOut.write(aluStore);
  //direccion de registro de guardado
  rwOut.write(rwStore);
  zeroFlagOut.write(zeroFlagStore);
  ctrlOut.write(ctrlStore);
}

void RegisterEXMEM::write() {
  // valores 
  ctrlStore = ctrlIn.read();
  zeroFlagStore = zeroFlagIn.read();
  addStore = addIn.read();
  aluStore = aluIn.read();
  // direccion
  rwStore = rwIn.read();
}
