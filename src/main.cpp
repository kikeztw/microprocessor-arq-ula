// #include "Testbench.h"
#include <sysc/kernel/sc_externs.h>
#include <systemc.h>

#include <ctime>

#include "datapath.h"
#include "utils.h"
int sc_main(int argc, char **argv)
{
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);
  std::string path = "./tests/ejemplo04.asm";
  sc_clock clock("clock", period, 0.5, delay, false);
  DataPath cam("camino");
  // Testbench test("test");

  sc_signal<sc_uint<32>> SgOutPC;
  sc_signal<sc_uint<32>> Sg_cpIntre;
  sc_signal<string> Sg_stringDInre;

  cam.clkIn(clock);
  // lee el .asm indicado
  read(path, &cam.inf.im.L1_I, &cam.inf.im.labels, NULL, NULL);
  // cam.SgInPC(SgOutPC);
  // cam.Sg_cpOutre(Sg_cpIntre);
  // cam.Sg_stringDOutre(Sg_stringDInre);

  // test.SgOutPC(SgOutPC);
  // test.Sg_cpIntre(Sg_cpIntre);
  // test.Sg_stringDInre(Sg_stringDInre);
  // test.clkIn(clock);

  sc_start();

  return 0;
}
