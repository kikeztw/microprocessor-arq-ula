#include "instruction_memory.h"

InstructioMemory::InstructioMemory(sc_module_name nm)
    : sc_module(nm), l1("l1", 1000) {

  // leeria el archivo
  SC_METHOD(read);
  sensitive << address;
}
void InstructioMemory::read() {
  // addressBlock = l1[address];
}

// #include "instruction_memory.h"

// InstructioMemory::InstructioMemory(sc_module_name name)
//     : sc_module(name), l1("l1", 8) {
//   for (short i = 0; i < 8; i++) {
//     // hacer un resize de 8000 bytes en cada posicion del vector
//     l1[i].init(8000);
//   }
//   SC_METHOD(read);
//   sensitive << address;
// }
// void InstructioMemory::read() {
//   auto add = address.read();
//   // addressBlock->write();
// }
