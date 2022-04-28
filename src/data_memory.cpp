#include "data_memory.h"


DataMemory::DataMemory(sc_module_name nm): sc_module(nm) {
  SC_METHOD(write);
  sensitive << clkIn.neg();

  SC_METHOD(read);
  sensitive << clkIn.pos();
}


void DataMemory::read(){
  // ???
  // rwOut.write(data[addressIn.read()]);
}

void DataMemory::write(){
  memory[rwIn.read()] = wIn.read();
}