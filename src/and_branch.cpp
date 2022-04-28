#include "and_branch.h"

AndBranch::AndBranch(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << addIn << zeroIn;
}

void AndBranch::operation() { 
  if(zeroIn.read() == 1 && addIn.read() != 0)
    sOut.write(true);
  else
    sOut.write(false);
}
