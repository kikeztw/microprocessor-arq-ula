#ifndef AND_BRANCH_H
#define AND_BRANCH_H

#include <systemc.h>
#include "utils.h"

class AndBranch : public sc_module {
public:
  sc_in<sc_uint<32>> addIn;
  sc_in<bool> zeroIn;
  sc_out<bool> sOut;

  SC_CTOR(AndBranch);

private:
  void operation();
};

#endif