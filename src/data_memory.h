#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H


#include <systemc.h>


class DataMemory:  public sc_module {
  public:

    sc_in<bool> clkIn;
    sc_in<sc_uint<5>> rwIn; // direccion donde se va escribir
    sc_in<sc_int<32>> wIn; // valor de lo que se va a escribir

    sc_out<sc_uint<5>> rwOut; // dato que se lee
    // que tamanio ??? 
    sc_int<32> memory[32];

    SC_CTOR(DataMemory);
  private:
    void read();
    void write();
};


#endif