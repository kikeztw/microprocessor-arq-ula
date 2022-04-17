#include "camino.h"
#include <sysc/kernel/sc_externs.h>
#include <systemc.h>

int sc_main(int argc, char **argv) {
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);
  DataPath cam("camino");

  cam.clkIn(clock);

  sc_start();

  return 0;
}
