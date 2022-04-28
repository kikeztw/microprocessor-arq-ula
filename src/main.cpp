#include "camino.h"
#include "utils.h"
#include <systemc.h>

int sc_main(int argc, char **argv) {
  clear();

  std::cout << "\n\nIniciando simulador...\n\n\n";
  std::string path = "./ejemplo04.asm";
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);
  DataPath cam("camino");

  cam.clkIn(clock);

  read(path, &cam.im.L1_I, &cam.im.labels, NULL, NULL);
  sc_start();

  return 0;
}
