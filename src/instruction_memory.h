#ifndef L1_H
#define L1_H

#include <systemc.h>

/**
 * @class InstructionMemory
 * @brief  Modulo de Cache L1 de instrucciones
 */

class InstructioMemory : sc_module {
public:
  // sc_in<bool> clkIn;
  sc_in<sc_uint<32>> address;

  SC_CTOR(InstructioMemory);
  sc_out<sc_uint<32>> addressBlock;

private:
  // bloque de 8kb
  // cada bloque tiene 8000 bytes
  // cada byte es un bloque que se pasa a la siguiente etapa
  sc_vector<std::string> l1;
  void read();
};

#endif // !PC_H
