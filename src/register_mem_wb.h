#ifndef REGISTER_MEM_WB_H
#define REGISTER_MEM_WB_H

#include "utils.h"
#include <string>
#include <systemc.h>

class RegisterMEMWB : public sc_module {
public:

  sc_in<bool> clkIn;
  sc_in<sc_int<32>> rdIn; // data entrante
  sc_in<sc_uint<5>> regDestinyIn; // registro destino

  sc_out<sc_uint<5>> regDestinyOut;
  sc_out<sc_int<32>> rdOut;

  SC_CTOR(RegisterMEMWB);
private:
  // std::string tagStore;
  sc_int<32>  dataStore;
  sc_uint<5> regDestinyStore;

  void read();
  void write();
};

#endif
