#include "register_id_ex.h"

RegisterIDEX::RegisterIDEX(sc_module_name nm) : sc_module(nm) {
  tagStore = "";
  aStore = 0;
  bStore = 0;
  vStore = 0;
  cpStore = 0;
  rwStore = 0;
  ctrlStore = 0;
  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();
  

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterIDEX::read() {

  string temptag;
  // tag
  temptag.set(tagStore);
  tagOut.write(temptag);

  // PC and Imm
  cpOut.write(cpStore);
  //valores
  aOut.write(aStore);
  bOut.write(bStore);
  vOut.write(vStore);
  //direccion de registro de guardado
  rwOut.write(rwStore);
  
  ctrlOut.write(ctrlStore);
  

}

void RegisterIDEX::write() {
  // register 1 and 2
  tagStore = tagIn.read().str;
  // PC write
  cpStore = cpIn.read();
  // valores 
  aStore = rRg1In.read();
  bStore = rRg2In.read();
  if(immIn.read() != 0)
    aStore = immIn.read();
  if(immIn2.read() != 0)
    bStore = immIn2.read();
  // direccion
  rwStore = rwIn.read();
  ctrlStore = ctrlIn.read();

  vStore = 0;

  if(ctrlIn.read() == SW)
  {
    vStore = rRg1In.read();
    aStore = rRg2In.read();
    bStore = immIn2.read();
  }

}
