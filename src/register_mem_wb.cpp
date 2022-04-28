#include "register_mem_wb.h"

RegisterMEMWB::RegisterMEMWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(write);
  sensitive << clkIn.neg();

  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterMEMWB::read() {
  rdOut.write(rdS);
  readDataOut.write(readDataS);
  resultAluOut.write(resultAluS);
  opCodeOut.write(opCodeS);
}

void RegisterMEMWB::write() {
  rdS = rdIn.read();
  opCodeS = opCodeIn.read();
  readDataS = readDataIn.read();
  resultAluS = resultAluIn.read();
}
