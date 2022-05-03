#ifndef REGISTER_H
#define REGISTER_H

#include "Cell.h"
#include <sysc/communication/sc_signal.h>
#include <systemc.h>

class Register : public sc_module {
public:
  sc_out<sc_int<32>> wOut;
  sc_in<sc_int<32>> wIn;
  sc_in<bool> clkIn /* , weIn */;

  SC_CTOR(Register);

  sc_vector<Cell> celdas;

private:
  // sc_signal<bool>

  void assambly();
  sc_signal<bool> wSg[32], dataSg[32];
};

#endif
