#include "phase1.h"

#include <iomanip>
#include <iostream>

CIF::CIF(sc_module_name name)
    : sc_module(name), adder("sumador"), im("im_"), pc("pc"), re("re_")

{
  pc.clkIn(clkIn);
  pc.addressPC(SgOutadd);
  pc.addressBlock(SgOutPC);

  adder.sIn(SgOutPC);
  adder.sOut(SgOutadd);

  im.address(SgOutPC);
  im.block(SgOutim);
  im.op(Sgop);
  im.rd(Sgrd);
  im.rs1(Sgrs1);
  im.rs2(Sgrs2);
  im.imm(Sgimm);

  re.cpIn(SgOutPC);
  re.insIn(SgOutim);
  re.opIn(Sgop);
  re.rdIn(Sgrd);
  re.rs1In(Sgrs1);
  re.rs2In(Sgrs2);
  re.immIn(Sgimm);

  re.clkIn(clkIn);
  re.cpOut(Sg_cpOutre);
  re.insOut(Sg_stringDOutre);
  re.opOut(SgopOut);
  re.rdOut(SgrdOut);
  re.rs1Out(Sgrs1Out);
  re.rs2Out(Sgrs2Out);
  re.immOut(SgimmOut);

  SC_METHOD(test)
  sensitive << clkIn;
}
void CIF::log()
{
  std::cout << std::endl << std::setw(6) << sc_time_stamp();
  std::cout << std::setw(3) << "";
  std::cout << std::setw(3) << clkIn.read();
  std::cout << std::setw(3) << "";
  std::cout << std::setw(32);
}

void CIF::test()
{
  if (clkIn.read() == 1) {
    std::cout << "\n============IF============";
    log();
    std::cout << "PC out: " << SgOutPC.read();
    log();
    std::cout << "adder in: " << SgOutPC.read() << ", out:" << SgOutadd.read();
    log();
    std::cout << "IM in: " << SgOutPC.read() << ", out:" << SgOutim.read();
    log();
    std::cout << "IM in: " << SgOutPC.read() << ", out= "
              << "op: " << Sgop.read() << ", rd: " << Sgrd.read()
              << ", rs1: " << Sgrs1.read() << ", rs2: " << Sgrs2.read()
              << ", imm: " << Sgimm.read();
  } else {
    std::cout << "\n============IF============";
    log();
    std::cout << "PC in: " << SgOutadd.read();
    log();
    std::cout << "IF/ID in: (instr:" << SgOutim.read()
              << ", pc:" << SgOutPC.read() << ")";
  }
}
CIF::~CIF()
{
}
