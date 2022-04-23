#ifndef REGISTER_IF_ID_H
#define REGISTER_IF_ID_H

#include <systemc.h>

#include <string>

#include "utils.h"

class RegisterIFID : public sc_module
{
 public:
  SC_CTOR(RegisterIFID);

  sc_in<sc_uint<32>> cpIn;
  sc_in<string> insIn;
  sc_in<sc_uint<5>> opIn;
  sc_in<sc_uint<5>> rdIn;
  sc_in<sc_uint<5>> rs1In;
  sc_in<sc_uint<5>> rs2In;
  sc_in<sc_uint<32>> immIn;

  sc_in<bool> clkIn;

  sc_out<sc_uint<32>> cpOut;
  sc_out<string> insOut;
  sc_out<sc_uint<5>> opOut;
  sc_out<sc_uint<5>> rdOut;
  sc_out<sc_uint<5>> rs1Out;
  sc_out<sc_uint<5>> rs2Out;
  sc_out<sc_uint<32>> immOut;

 private:
  std::string insSt;
  sc_uint<32> cpSt;
  void read();
  void write();
};
#endif
