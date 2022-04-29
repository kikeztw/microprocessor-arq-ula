#include "mux_wb.h"

MuxWB::MuxWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(op);
  sensitive << opCodeIn << readDataIn << resultAluIn;
}

void MuxWB::op() {
  auto op_code = opCodeIn.read();
  auto read_data_in = readDataIn.read();
  auto result_alu_in = resultAluIn.read();

  // std::cout << "\nEstoy en MUXWB: " << result_alu_in << "\n";
  if (op_code == LW) {
    resultOut.write(read_data_in);
    // lee
  } else if (op_code == SW) {
    return;
  } else {
    // escribe
    resultOut.write(result_alu_in);
  }
}
