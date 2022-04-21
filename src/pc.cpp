#include "pc.h"
#include <sysc/kernel/sc_module.h>
#include <sysc/kernel/sc_module_name.h>

PC::PC(sc_module_name name) : sc_module(name) {

  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

// no estoy seguro , si aca es asi , no se si sera con sincronizacion de reloj
// como en la celda , si clkIn es 0 escribe y 1 lee
void PC::read() {
  // std::cout << "en pc";
  addressBlock.write(address);
}

void PC::write() { address = addressPC.read(); }
