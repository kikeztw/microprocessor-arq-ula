#include "mux_wb.h"

MuxWB::MuxWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(op);
  sensitive << opCodeIn;
}

void MuxWB::op() {
  auto op_code = opCodeIn.read();
  auto read_data_in = readDataIn.read();
  auto result_alu_in = resultAluIn.read();

  if (op_code == LW || op_code == SW) {
    resultOut.write
    // lee
  } else {
    // escribe
    resultOut.write(result_alu_in);
  }
}
