#include "data_memory.h"

DataMemory::DataMemory(sc_module_name nm) : sc_module(nm) {
  L1_D.reserve(100);
  SC_METHOD(op)
  sensitive << opCodeIn;
}

void DataMemory::op() {
  auto op_code = opCodeIn.read();
  auto addressIn_ = addressIn.read();

  if (addressIn_ < 0)
    addressIn_ = addressIn_ * -1;

  if (op_code == LW) {
    // lee
    valueOut.write(L1_D[addressIn_]);
  } else if (op_code == SW) {
    // escribe
    L1_D[addressIn_] = valueIn.read();
  }
}
