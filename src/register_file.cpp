#include "register_file.h"

RegisterFile::RegisterFile(sc_module_name nm)
    : sc_module(nm), registros("_reg", 32) {

  for (short i = 0; i < 32; i++) {
    registros[i].clkIn(clkIn);
    // registros[i].weIn(weIn);
    registros[i].wOut(wOutSg[i]);
    registros[i].wIn(wInSg[i]);
  }

  // for(short i=0; i<32; i++)
  // registros[i] = 0;

  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa 
  // ue el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que 
  // l reloj está en 1)
  SC_METHOD(read);
  sensitive << raIn << rbIn;
}

void RegisterFile::read() {
  auto addressA = raIn.read();
  auto addressB = rbIn.read();

  // weIn = true;
  sc_int<32> valA = wOutSg[addressA].read();
  sc_int<32> valB = wOutSg[addressB].read();

  aOut.write(valA);
  bOut.write(valB);

  // aOut.write(registros[raIn.read()]);
  // bOut.write(registros[rbIn.read()]);
}

void RegisterFile::write() {
  // registros[rwIn.read()] = wIn.read();
  // registros[0] = 0;

  // weIn = true;
  auto addresW = rwIn.read();
  if (addresW == 0)
    return;
  wInSg[addresW] = wIn.read();
}

void RegisterFile::assambly() {}
