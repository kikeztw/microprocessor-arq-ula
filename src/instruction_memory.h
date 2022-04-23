#ifndef L1_H
#define L1_H

#include "utils.h"
#include <iostream>
#include <map>
#include <string>
#include <systemc.h>

/**
 * @class InstructionMemory
 * @brief  Modulo de Cache L1 de instrucciones
 */

class InstructioMemory : sc_module {
public:
  // sc_in<bool> clkIn;
  sc_in<sc_uint<32>> address;
  sc_out<string> block;

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
};
#endif // !PC_H
