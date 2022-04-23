#ifndef PC_H
#define PC_H

#include <systemc.h>

/**
 * @class PC (contador de programa)
 * @brief Module que recibe la direccion de memoria
 */

class PC : sc_module {
public:
  // sc_in<bool> clkIn;
  // direccion de memoria a bloque que contine dato a ejecutar
  sc_in<bool> clkIn;
  sc_in<sc_uint<32>> addressPC;

  SC_CTOR(PC);
  // direccion de memoria que posee el bloque de 32 bits con:
  // 1) registro a escribir
  // 2) registros para operar (son 2)
  // 3) valor inmmediato
  // 4) op (codigo de operacion: me indica que operacion a realizar)
  sc_out<sc_uint<32>> addressBlock;

private:
  sc_uint<32> address;
  void read();
  void write();
};

#endif // !PC_H
