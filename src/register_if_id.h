#ifndef REGISTER_IF_ID_H
#define REGISTER_IF_ID_H

#include <systemc.h>
#include "str.h"
#include <string>

class RegisterIFID: public sc_module {
    public:

    SC_CTOR(RegisterIFID);
    
    sc_in<sc_uint<32>> cpIn; 
    sc_in<string> insIn;
    sc_in<bool> clkIn;
    sc_out<sc_uint<32>> cpOut;
    sc_out<string> insOut;


    private:
    std::string insSt;
    sc_uint<32> cpSt; 
    void read();
    void write();

};
#endif