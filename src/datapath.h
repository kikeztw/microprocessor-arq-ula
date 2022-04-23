#ifndef camino
#define camino

#include <sysc/communication/sc_clock.h>
#include <systemc.h>

#include "modules/phase1/Adder.h"
#include "modules/phase1/instruction_memory.h"
#include "modules/phase1/pc.h"
#include "modules/phase1/register_if_id.h"
#include "phases/phase1.h"
#include "utils/utils.h"
/**
 * @class DataPath
 * @brief Clase que encapsula los modulos para lograr el DataPath de datos
 * encauzado o Data Path
 * @details ejecuta las operaciones correspondientes en cada ciclo de reloj
 */

class DataPath : public sc_module
{
 public:
  sc_in<bool> clkIn;
  SC_CTOR(DataPath);
  ~DataPath();  // Destructor

  CIF inf;

 private:
  sc_signal<bool> SgclkIn;
  void IF();
  // void ID();
  // void EX();
  // void MEM();
  // void WB();
};

#endif  // !camino
