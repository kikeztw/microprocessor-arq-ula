#include "register_mem_wb.h"


RegisterMEMWB::RegisterMEMWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(write);
  sensitive << clkIn.neg();

  SC_METHOD(read);
  sensitive << clkIn.pos();
}

void RegisterMEMWB::read() {
}

void RegisterMEMWB::write() {

}
