#include "camino.h"

// static bool stop = true;

DataPath::DataPath(sc_module_name name)
    : sc_module(name), adder("sumador"), im("im_"), pc("pc"),
     re("re_"), cu("cu"), reIFEX("re_ifex"), rf("rf_") {

   sgRwRb = 0;
   sgWRb = 0;

   pc.clkIn(clkIn);
   pc.addressPC(SgOutadd);
   pc.addressBlock(SgOutPC);

   adder.sIn(SgOutPC);
   adder.sOut(SgOutadd);

   im.address(SgOutPC);
   im.block(SgOutim);

   re.cpIn(SgOutPC);
   re.insIn(SgOutim);
   re.clkIn(clkIn);
   re.cpOut(Sg_cpOutre);
   re.insOut(Sg_stringDOutre);

   cu.sIn(Sg_stringDOutre);
   cu.controlOut(SgControlOut[0]);
   cu.rwOut(SgControlOut[1]);
   cu.raOut(SgControlOut[2]);
   cu.rbOut(SgControlOut[3]);
   cu.aOut(SgValoresInmediatos[0]);
   cu.bOut(SgValoresInmediatos[1]);
   cu.tagOut(SgTagOut);

   rf.rwIn(sgRwRb);
   rf.wIn(sgWRb);
   rf.raIn(SgControlOut[2]);
   rf.rbIn(SgControlOut[3]);
   rf.aOut(sgRfOut[0]);
   rf.bOut(sgRfOut[1]);

   reIFEX.clkIn(clkIn);
   reIFEX.rRg1In(sgRfOut[0]);
   reIFEX.rRg2In(sgRfOut[0]);
   reIFEX.cpIn(Sg_cpOutre);
   reIFEX.immIn(SgValoresInmediatos[0]);
   reIFEX.immIn2(SgValoresInmediatos[1]);
   reIFEX.tagIn(SgTagOut);
   reIFEX.rwIn(SgControlOut[1]);

   reIFEX.aOut(sgReIDEXValues[0]);
   reIFEX.bOut(sgReIDEXValues[1]);
   reIFEX.cpOut(sgReIDEXCp);
   reIFEX.tagOut(sgReIDEXTag);
   reIFEX.rwOut(sgReIDEXRw);
   

  SC_METHOD(test);
    sensitive << clkIn.neg();
  dont_initialize();


}

void DataPath::log()
{
  std::cout << std::endl << std::setw(6) << sc_time_stamp();
  std::cout << std::setw(3) << "";
  std::cout << std::setw(3) << clkIn.read();
  std::cout << std::setw(3) << "";
  std::cout << std::setw(32);
}


void DataPath::test()
{
  std::cout << "\n============IF============";
    log();
    std::cout << "PC out: " << SgOutPC.read();
    log();
    std::cout << "adder in: " << SgOutPC.read()  << ", out:" << SgOutadd.read();
    log();
    std::cout << "IM in: " << SgOutPC.read() << ", out:" << SgOutim.read();
    log();
    std::cout << "PC in: " << SgOutadd.read();  
    log();
    std::cout << "IF/ID in: (instr:" << SgOutim.read() << ", pc:" << SgOutPC.read() << ")";
    
    std::cout << "\n============ID============";
    log();
    std::cout << "IF/ID in: (instr:" << Sg_stringDOutre.read() << ", pc:" << Sg_cpOutre.read() << ")";
    log();  
    std::cout << "CU in: " << Sg_stringDOutre.read();
      log();  
    std::cout << "CU out: [sg ctrl:" << SgControlOut[0].read() 
    << ", sg rw:"<< SgControlOut[1].read() 
    << ", sg ra:"<< SgControlOut[2].read()
    << ", sg rb:"<< SgControlOut[3].read()
    << ", sg vi a:" << SgValoresInmediatos[0].read()
    << ", sg vi b:" << SgValoresInmediatos[1].read()
    << ", tag: " << SgTagOut.read().str    << "]";
}

DataPath::~DataPath() {}

