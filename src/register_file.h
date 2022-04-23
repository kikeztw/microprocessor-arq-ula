#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <systemc.h>


class RegisterFile: public sc_module {
    public:

    SC_CTOR(RegisterFile);

    sc_in<sc_uint<5>> rwIn;
    sc_in<sc_uint<5>> raIn;
    sc_in<sc_uint<5>> rbIn;
    sc_in<bool> clkIn;
    sc_in<sc_uint<32>> wIn;
    //sc_in<bool> weIn;
    sc_out<sc_uint<32>> aOut;
    sc_out<sc_uint<32>> bOut;
    sc_uint<32> registros[32];

    private:
    void read();
    void write();

};
#endif