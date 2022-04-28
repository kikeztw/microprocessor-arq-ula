#ifndef REGISTER_MEM_WB_H
#define REGISTER_MEM_WB_H

#include "utils.h"
#include <string>
#include <systemc.h>

class RegisterMEMWB : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in<sc_uint<5>> rdIn;       // registro donde se va a guardar
  sc_in<sc_uint<5>> opCodeIn;   // codigo de operaciones
  sc_in<sc_int<32>> readDataIn; // dato que sale de data memory
  sc_in<sc_int<32>>
      resultAluIn; // dato que se pasa del registro de encauzamiento

  sc_out<sc_uint<5>> rdOut;
  sc_out<sc_uint<5>> opCodeOut;
  sc_out<sc_int<32>> readDataOut;
  sc_out<sc_int<32>> resultAluOut;
  SC_CTOR(RegisterMEMWB);

private:
  bool clkInS;
  sc_uint<5> rdS;        // registro donde se va a guardar
  sc_uint<5> opCodeS;    // codigo de operaciones
  sc_int<32> readDataS;  // dato que sale de data memory
  sc_int<32> resultAluS; // dato que se pasa del registro de encauzamiento

  void read();
  void write();
};

#endif
