#include "camino.h"
// static bool stop = true;

DataPath::DataPath(sc_module_name name)
    : sc_module(name), adder("sumador"), im("im_"), pc("pc"), re("re_"),
      cu("cu"), reIDEX("re_ifex"), rf("rf_"), adder2("sumador2"), alu("alu"),
      andBranch("andBranch"), muxCp("muxCp"), reEXMEM("reEXMEm"),
      dataMem("dataMem"), reMEMWB("reMEMWB"), muxWB("mux_ultima_etapa") {

  sgRwRb = 0;
  sgWRb = 0;
  sgBranch = 0;
  sgEXMEMaddOut = 0;

  muxCp.s0In(sgBranch);
  muxCp.aIn(SgOutadd);
  muxCp.bIn(sgEXMEMaddOut);
  muxCp.cOut(sgMuxOut);

  pc.clkIn(clkIn);
  pc.addressPC(sgMuxOut);
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

  rf.clkIn(clkIn);
  rf.rwIn(sgRwRb);
  rf.wIn(sgWRb);
  rf.raIn(SgControlOut[2]);
  rf.rbIn(SgControlOut[3]);
  rf.aOut(sgRfOut[0]);
  rf.bOut(sgRfOut[1]);

  reIDEX.clkIn(clkIn);
  reIDEX.rRg1In(sgRfOut[0]);
  reIDEX.rRg2In(sgRfOut[1]); // deberia ser 1

  reIDEX.cpIn(Sg_cpOutre);
  reIDEX.immIn(SgValoresInmediatos[0]);
  reIDEX.immIn2(SgValoresInmediatos[1]);
  reIDEX.tagIn(SgTagOut);
  reIDEX.rwIn(SgControlOut[1]);
  reIDEX.ctrlIn(SgControlOut[0]);

  reIDEX.aOut(sgReIDEXValues[0]);
  reIDEX.bOut(sgReIDEXValues[1]); //
  reIDEX.cpOut(sgReIDEXCp);
  reIDEX.tagOut(sgReIDEXTag);
  reIDEX.rwOut(sgReIDEXRw);
  reIDEX.ctrlOut(sgReIDEXCtrl);

  alu.op(sgReIDEXCtrl);
  alu.opA(sgReIDEXValues[0]);
  alu.opB(sgReIDEXValues[1]);
  alu.result(sgResult);
  alu.zero(sgZero);

  adder2.sIn(sgReIDEXTag);
  adder2.sOut(sgAdder2Out);

  reEXMEM.addIn(sgAdder2Out);
  reEXMEM.aluIn(sgResult);
  reEXMEM.rwIn(sgReIDEXRw);
  reEXMEM.ctrlIn(sgReIDEXCtrl);
  reEXMEM.zeroFlagIn(sgZero);
  reEXMEM.clkIn(clkIn);
  reEXMEM.valIn(sgReIDEXValues[0]);

  reEXMEM.addOut(sgEXMEMaddOut);
  reEXMEM.aluOut(sgEXMEMaluOut);
  reEXMEM.rwOut(sgEXMEMrwOut);
  reEXMEM.ctrlOut(sgEXMEMctrlOut);
  reEXMEM.zeroFlagOut(sgEXMEMzeroFlagOut);
  reEXMEM.valOut(sgEXMEMval);

  andBranch.zeroIn(sgEXMEMzeroFlagOut);
  andBranch.addIn(sgEXMEMaddOut);
  andBranch.sOut(sgBranch);

  dataMem.opCodeIn(sgEXMEMctrlOut);
  dataMem.addressIn(sgEXMEMaluOut); //  sc_in<sc_uint<32>>
  dataMem.valueIn(sgEXMEMval);      // sc_in<sc_int<32>>

  dataMem.valueOut(sgvalue); // sc_out<sc_int<32>>

  reMEMWB.clkIn(clkIn);
  reMEMWB.rdIn(sgEXMEMrwOut);
  reMEMWB.opCodeIn(sgEXMEMctrlOut);
  reMEMWB.readDataIn(sgvalue);
  reMEMWB.resultAluIn(sgEXMEMaluOut);

  reMEMWB.rdOut(sgRwRb);
  reMEMWB.opCodeOut(sgMEMWBCtrlOut);
  reMEMWB.readDataOut(sgMEMWBdataOut);
  reMEMWB.resultAluOut(sgMEMWBaluOut);

  muxWB.opCodeIn(sgMEMWBCtrlOut);
  muxWB.readDataIn(sgMEMWBdataOut);
  muxWB.resultAluIn(sgMEMWBaluOut);

  muxWB.resultOut(sgWRb);

  SC_METHOD(test);
  sensitive << clkIn.neg();
  dont_initialize();
}

void DataPath::log() {
  std::cout << std::endl << std::setw(6) << sc_time_stamp();
  std::cout << std::setw(3) << "";
  std::cout << std::setw(3) << clkIn.read();
  std::cout << std::setw(3) << "";
  // std::cout << std::setw(32);
}

void DataPath::test() {

  std::cout << "\n======================IF====================================="
               "========";
  log();
  std::cout << "| PC  | out: " << SgOutPC.read();
  log();
  std::cout << "|ADD-1| in: " << SgOutPC.read() << ", out:" << SgOutadd.read();
  log();
  std::cout << "| IM  | in: " << SgOutPC.read() << ", out: " << SgOutim.read();
  log();
  std::cout << "| PC  | in: " << SgOutadd.read();
  log();
  std::cout << "|IF/ID| in: (instr: " << SgOutim.read()
            << ", pc: " << SgOutPC.read() << ")";

  std::cout << "\n======================ID====================================="
               "========";
  log();
  std::cout << "|IF/ID| out: (instr: " << Sg_stringDOutre.read()
            << ", pc:" << Sg_cpOutre.read() << ")";
  log();
  std::cout << "| CU  | in: " << Sg_stringDOutre.read();
  log();
  std::cout << "| CU  | out: [sg ctrl: " << SgControlOut[0].read()
            << ", sg rw:" << SgControlOut[1].read()
            << ", sg ra:" << SgControlOut[2].read()
            << ", sg rb:" << SgControlOut[3].read()
            << ", sg vi a:" << SgValoresInmediatos[0].read()
            << ", sg vi b:" << SgValoresInmediatos[1].read()
            << ", tag: " << SgTagOut.read().str << "]";

  log();
  std::cout << "| RF  | In: ["
            << ", sg ra:" << SgControlOut[2].read()
            << ", sg rb:" << SgControlOut[3].read() << "] out:[" 
            << ", a:" << sgRfOut[0].read()
            << ", b:" << sgRfOut[1].read()
            <<  "]";
  log();
  std::cout << "|ID/EX| in: [Rg1:" << sgRfOut[0] << ",Rg2:" << sgRfOut[1]
            << ",Inm1:" << SgValoresInmediatos[0].read()
            << ",Inm2:" << SgValoresInmediatos[1].read()
            << ",tag:" << SgTagOut.read().str
            << ",rw:" << SgControlOut[1].read()
            << ",ctrl:" << SgControlOut[0].read() << "]";
  std::cout << "\n======================EX====================================="
               "========";
  log();
  std::cout << "|ID/EX| out: [a:" << sgReIDEXValues[0].read()
            << ",b:" << sgReIDEXValues[1].read()
            << ",ctrl:" << sgReIDEXCtrl.read() << ",rw:" << sgReIDEXRw.read()
            << ",tag:" << sgReIDEXTag.read().str << "]";
  log();
  std::cout << "|ADD-2| in:" << sgReIDEXTag.read().str
            << ", out:" << sgAdder2Out;
  log();
  std::cout << "| ALU | in: [a:" << sgReIDEXValues[0]
            << ",b:" << sgReIDEXValues[1] << ",ctrl:" << sgReIDEXCtrl
            << "] out: [r:" << sgResult.read() << ",z:" << sgZero.read() << "]";

  log();
  std::cout << "|IX/ME| in: [alu:" << sgResult.read()
            << ",zero:" << sgZero.read() << ",add:" << sgAdder2Out
            << ",ctrl:" << sgReIDEXCtrl << "]";
              std::cout << "\n======================WB====================================="
               "========";
  log();
  std::cout << "|MEM/RW| in: [rw:" << sgEXMEMrwOut.read()
            << ",data:" << sgvalue.read() << ",alu:" << sgEXMEMaluOut.read()
            << ",ctrl:" << sgEXMEMctrlOut.read() << "]";
  log();
  std::cout << "| PC  | out: " << SgOutPC.read();
  std::cout << "\n======================FIN DE "
               "CICLO====================================\n\n";
  std::cout<<"=================ARCHIVO DE REGISTROS============================================================\n";
  std::cout<<"=x00=x01=x02=x03=x04=x05=x06=x07=x08=x09=x10";
  std::cout<<"=x11=x12=x13=x14=x15=x16=x17=x18=x19=x20=x21";
  std::cout<<"=x22=x23=x24=x25=x26=x27=x28=x29=x30=x31=\n=";
  for(short i=0; i<32; i++){
    std::cout<<" "<<rf.registros[i]<<" =";
  }
  std::cout<<"\n=================ARCHIVO DE REGISTROS============================================================\n";
  std::cout<<"\n\n";
  for(int i=0 ; i<3 ; i++)std::cout<<dataMem.L1_D[i]<<" ";
}

DataPath::~DataPath() {}