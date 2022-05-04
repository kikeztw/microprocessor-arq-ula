#include "camino.h"
#include "utils.h"
#include <systemc.h>

int sc_main(int argc, char **argv) {
  clear();

  std::cout << "\n\nIniciando simulador...\n\n\n";
  std::string path = "./ejemplo03.asm";
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);
  DataPath cam("camino");

  cam.clkIn(clock);

  read(path, &cam.im.L1_I, &cam.im.labels, &cam.dataMem.L1_D, NULL);

  std::vector<int> *a = &cam.dataMem.L1_D;
  std::map<std::string, int> *aux_ = &cam.im.labels;
  for (auto g : *(a)) {
    std::cout << "dato: " << g << "\n";
  }
  for (auto aux : *aux_) {
    std::cout << "etiqueta: " << aux.first << "posicion: " << aux.second
              << std::endl;
  }

  sc_start();

  return 0;
}
