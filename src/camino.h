#ifndef camino
#define camino

#include <sysc/communication/sc_clock.h>
#include <systemc.h>

/**
 * @class DataPath
 * @brief Clase que encapsula los modulos para lograr el DataPath de datos
 * encauzado o Data Path
 * @details ejecuta las operaciones correspondientes en cada ciclo de reloj
 */

class DataPath : public sc_module {
public:
  sc_in<bool> clkIn;
  SC_CTOR(DataPath);

  ~DataPath(); // Destructor
private:
  void IF();
  void ID();
  void EX();
  void MEM();
  void WB();
};

#endif // !camino
