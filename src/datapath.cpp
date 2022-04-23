#include "datapath.h"

#include <sysc/kernel/sc_module_name.h>
#include <sysc/kernel/sc_simcontext.h>

sc_event do_decode_ev;
sc_event do_execute_ev;
sc_event do_memoryAccess_ev;
sc_event do_writeBack_ev;
sc_event do_store_ev;

// static bool stop = true;

DataPath::DataPath(sc_module_name name) : sc_module(name), inf("inf")
{
  // sc_stop();

  inf.clkIn(SgclkIn);
  // clkIn(clk);

  SC_THREAD(IF);
  sensitive << clkIn;
  dont_initialize();
  // SC_THREAD(ID);
  // sensitive << do_decode_ev;
  // // dont_initialize();
  // SC_THREAD(EX);
  // sensitive << do_execute_ev;
  // // dont_initialize();
  // SC_THREAD(MEM);
  // sensitive << do_memoryAccess_ev;
  // // dont_initialize();
  // SC_THREAD(WB);
  // sensitive << do_writeBack_ev;
  // dont_initialize();
}
DataPath::~DataPath()
{
}

void DataPath::IF()
{
  while (1) {
    wait();
    SgclkIn = clkIn.read();
    // std::cout << clkIn->read() << std::endl;
    // std::cout << clkIn->read() << std::endl;
    // operaciones
    std::cout << "\n en IF" << std::endl;
    do_decode_ev.notify(SC_ZERO_TIME);
    // wait();
  }
}

// void DataPath::ID() {
//   while (1) {
//     wait();
//     // operaciones
//     std::cout << " en ID" << std::endl;
//     do_execute_ev.notify(SC_ZERO_TIME);
//   }
// }
// void DataPath::EX() {
//   while (1) {
//     wait();
//     // operaciones
//     std::cout << " en EX" << std::endl;
//     do_memoryAccess_ev.notify(SC_ZERO_TIME);
//   }
// }
// void DataPath::MEM() {
//   while (1) {
//     wait();
//     // operaciones
//     std::cout << " en MEM" << std::endl;
//     do_writeBack_ev.notify(SC_ZERO_TIME);
//   }
// }

// void DataPath::WB() {
//   while (1) {
//     wait();
//     // operacines
//     std::cout << " en WB" << std::endl;
//     if (stop) {

//       sc_stop();
//     }
//   }
// }

//! etc
