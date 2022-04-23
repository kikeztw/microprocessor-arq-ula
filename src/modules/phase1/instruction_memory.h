#ifndef L1_H
#define L1_H

#include <sysc/datatypes/int/sc_uint.h>
#include <sysc/utils/sc_vector.h>

#include <iostream>
#include <map>
#include <string>

#include "utils.h"
// #include <sysc/communication/sc_signal_ports.h>
#include <systemc.h>

/**
 * @class InstructionMemory
 * @brief  Modulo de Cache L1 de instrucciones
 */

class InstructioMemory : sc_module
{
 public:
  // sc_in<bool> clkIn;
  sc_in<sc_uint<32>> address;
  sc_out<string> block;

  // codigo operacion
  sc_out<sc_uint<5>> op;
  // // registro a guardar
  sc_out<sc_uint<5>> rd;
  // // registro 1 a leer
  sc_out<sc_uint<5>> rs1;
  // // registro 2 a leer
  sc_out<sc_uint<5>> rs2;
  // // valor inmediato
  sc_out<sc_uint<32>> imm;

  SC_CTOR(InstructioMemory);
  // cache l1 instrucciones
  std::vector<std::string> L1_I;
  // labes para los saltos pero en Instrucciones
  std::map<std::string, int> labels;

  // dato que me va a ayudar a decodificar direccion de memoria para cada una de
  // los datos en memoria
  std::map<std::string, int> *pointer_l1D = NULL;

 private:
  void read();
  sc_uint<5> getOP(std::string &block);
  sc_uint<5> getRd(std::string &block);
  sc_uint<5> getRs1(std::string &block, sc_uint<5> &op);
  sc_uint<5> getRs2(std::string &block, sc_uint<5> &op);
  sc_uint<5> getimm(std::string &block, sc_uint<5> &op);
};
#endif  // !PC_H
