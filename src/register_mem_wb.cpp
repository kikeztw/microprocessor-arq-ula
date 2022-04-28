#include "register_mem_wb.h"


RegisterMEMWB::RegisterMEMWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(write);
  sensitive << clkIn.neg();

  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterMEMWB::read() {
  regDestinyOut.write(regDestinyStore);
  rdOut.write(dataStore);
}

void RegisterMEMWB::write() {
  dataStore = rdIn.read();
  regDestinyStore = regDestinyIn.read();
}
