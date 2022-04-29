#include "mux_wb.h"

MuxWB::MuxWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << opCodeIn;
}

void MuxWB::op() {
  auto op_code = opCodeIn.read();
  auto read_data_in = readDataIn.read();
  auto result_alu_in  = resultAluIn.read();
  

  if(addressIn_ <0 )
    addressIn_  = addressIn_ * -1;
  
   if (op_code == LW || op_code == SW) {
    resultOut.write(read_data_in);
    // lee
  } else {
    // escribe
    resultOut.write(read_data_in);
  }
}
