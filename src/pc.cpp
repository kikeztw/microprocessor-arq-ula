#include "pc.h"
#include <sysc/kernel/sc_module.h>
#include <sysc/kernel/sc_module_name.h>

PC::PC(sc_module_name name) : sc_module(name) {
  SC_METHOD(op);
  sensitive << addressPC;
}

// no estoy seguro , si aca es asi , no se si sera con sincronizacion de reloj
// como en la celda , si clkIn es 0 escribe y 1 lee
void PC::op() {
  address = addressBlock.read();
  addressBlock.write(addressBlock.read());
}
