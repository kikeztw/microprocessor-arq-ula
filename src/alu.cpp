#include "alu.h"
void ALU::operation() {

  sc_int<32> dataA, dataB, res;
  zero = false;
  dataA = opA.read();
  dataB = opB.read();

  switch (op.read()) {

    case AND:
      res = dataA && dataB;
      break;

    case OR:
      res = dataA || dataB;
      break;

    case SUM:
      res = dataA + dataB;
      break;

    case SUB:
      res = dataA - dataB;
      break;

    default:
      res = 0;
    break;
  }
  result.write(res);
  if (res == 0)
    zero = true;
}
