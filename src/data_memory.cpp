#include "data_memory.h"

DataMemory::DataMemory(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(op);
  sensitive << opCodeIn ;
  dont_initialize();
}

void DataMemory::op() {
  auto op_code = opCodeIn.read();
  auto addressIn_ = addressIn.read();

  if(addressIn_ <0 )
    addressIn_  = addressIn_ * -1;
  
  if (op_code == LW) {
    valueOut.write(L1_D[addressIn_]);
    // lee
  } else if (op_code == SW) {
    // escribe
    L1_D[addressIn_] = valueIn.read();
  }
}
