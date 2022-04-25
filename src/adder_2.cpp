#include "adder_2.h"

Adder2::Adder2(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << sIn;
}

void Adder2::operation() { 
    std::string s  = sIn.read().str;
    if(s != "" && isNumber(s))
    {
        int linea = std::stoi(s);
        sOut.write(linea);
    }
    else
        sOut.write(0);
}

bool Adder2::isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}