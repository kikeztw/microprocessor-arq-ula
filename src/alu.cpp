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

  case LW:
    res = dataA + dataB;
    break;

  case SW:
    res = dataB;
    break;
  case ADD:
    res = dataA + dataB;
    break;

  case SUB:
    res = dataA - dataB;
    break;

  case BEQ:
    res = 1;
    if (dataA == dataB)
      res = 0;
    break;

  case BNE:
    res = 1;
    if (dataA != dataB)
      res = 0;
    break;

  case BLT:
    res = 1;
    if (dataA < dataB)
      res = 0;
    break;

  case DIV:
    res = dataA / dataB;
    break;

  case MOD:
    res = dataA % dataB;
    break;

  default:
    res = 0;
    break;
  }
  result.write(res);
  if (res == 0)
    zero = true;
}
