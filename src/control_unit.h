#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "utils.h"
#include <regex>
#include <sstream>
#include <string>
#include <systemc.h>
#include <vector>

class ControlUnit : public sc_module {
public:
  sc_in<string> sIn;
  // senal de control
  sc_out<sc_uint<5>> controlOut;
  // direccion de registro a guardar
  sc_out<sc_uint<5>> rwOut;
  // direccion de registro a
  sc_out<sc_uint<5>> raOut;
  // direccion de registro b
  sc_out<sc_uint<5>> rbOut;
  // valor inmediato a
  sc_out<sc_int<32>> aOut;
  // valor inmediato b;
  sc_out<sc_int<32>> bOut;
  // tag en caso de salto de linea
  sc_out<string> tagOut;

  SC_CTOR(ControlUnit);

private:
  int data[6] = {0, 0, 0, 0, 0, 0};
  std::string tag;
  void operation();
  void flush();
  void readInstruction(); // Esta funcion Lee la instruccion
  std::vector<std::string> split(std::string,
                                 char); // Esta funcion hace split de la linea
  bool compareString(
      std::string,
      std::string); // Compara dos strings ( 0 diferentes. 1 iguales)
};

#endif
