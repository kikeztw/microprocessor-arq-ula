#include "data_memory.h"

DataMemory::DataMemory(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(op);
  sensitive << opCodeIn;
  dont_initialize();
}

void DataMemory::op() {
  auto op_code = opCodeIn.read();
  if (op_code == LW) {
    valueOut.write(L1_D[addressIn.read()]);
    // lee
  } else if (op_code == SW) {
    // escribe
    L1_D[addressIn.read()] = valueIn.read();
  }
}
