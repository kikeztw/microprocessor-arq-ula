#include "register_file.h"

RegisterFile::RegisterFile(sc_module_name nm) : sc_module(nm) {
  for(short i=0; i<32; i++)
    registros[i] = 0;

  // Solo se puede escribir cuando el reloj está en 0 (clkIn.neg() representa que el reloj está en 0)
  SC_METHOD(write);
  sensitive << clkIn.neg();

  // Solo se puede leer cuando el reloj están en 1 (clkIn.pos() representa que el reloj está en 1)
  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterFile::read()
{
    aOut.write(registros[raIn.read()]);
    bOut.write(registros[rbIn.read()]);
}

void RegisterFile::write()
{
    if(weIn.read())
    {
        registros[rwIn.read()] = wIn.read();        
    }

}