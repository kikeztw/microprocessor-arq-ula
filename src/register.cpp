#include "register.h"
#include <sysc/kernel/sc_module.h>

Register::Register(sc_module_name nm) : sc_module(nm), celdas("_celdas", 32) {
  for (short i = 0; i < 32; i++) {
    celdas[i].clkIn(clkIn);
    celdas[i].storage = 0;
    celdas[i].weIn(weIn);
    celdas[i].wIn(wSg[i]);
    celdas[i].dataOut(dataSg[i]);
  }

  SC_METHOD(assambly);
  sensitive << wOut << wIn;
  for (short i{}; i < 32; i++) {
    sensitive /* << wSg[i]  */ << dataSg[i];
  }
}

void Register::assambly() {
  sc_uint<32> tmp;
  for (int i = 0; i < 32; i++) {
    wSg[i] = wIn.read()[i];
    tmp[i] = dataSg[i];
    // celdas[i]
    //   aSg[i] = aIn.read()[i];
    //   bSg[i] = bIn.read()[i];
    //   tmp[i] = cSg[i].read();
  }
  wOut.write(tmp);
  // cOut.write(tmp);
}
