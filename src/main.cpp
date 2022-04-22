// #include "Testbench.h"
#include <sysc/kernel/sc_externs.h>
#include <systemc.h>

#include <ctime>

#include "datapath.h"
int sc_main(int argc, char **argv)
{
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);
  DataPath cam("camino");
  // Testbench test("test");

  sc_signal<sc_uint<32>> SgOutPC;
  sc_signal<sc_uint<32>> Sg_cpIntre;
  sc_signal<string> Sg_stringDInre;

  cam.clkIn(clock);
  cam.SgInPC(SgOutPC);
  cam.Sg_cpOutre(Sg_cpIntre);
  cam.Sg_stringDOutre(Sg_stringDInre);

  // test.SgOutPC(SgOutPC);
  // test.Sg_cpIntre(Sg_cpIntre);
  // test.Sg_stringDInre(Sg_stringDInre);
  // test.clkIn(clock);

  sc_start();

  return 0;
}
