#include "instruction_memory.h"

InstructioMemory::InstructioMemory(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(read);
  sensitive << address;
}
void InstructioMemory::read() {

  string a;
  auto addres = address.read();
  std::string block;

  if (addres >= (L1_I.size() + 3))
    sc_stop();

  // busca el bloque si no esta, no devuelve nada
  try {
    block = L1_I.at(addres);

  } catch (std::out_of_range const &exc) {
    a.set("");
    this->block.write(a);
    // std::cout << exc.what() << '\n';
    return;
  }

  // traduce las etiquetas de salto en valores de posiciones
  std::string::size_type n;
  for (auto &pair : labels) {
    n = block.find(pair.first.substr(0, pair.first.size() - 1));
 
    if (n != std::string::npos) {
      block.replace(block.begin() + n, block.end(),
                    std::to_string(pair.second));

      //std::cout << block << std::endl;
    }
  }

  // traduce las etiquetas de valores en memoria de datos
  if (pointer_l1D != NULL) {
    for (auto &pair : *pointer_l1D) {
      n = block.find(pair.first);

      if (n != std::string::npos) {
        block.replace(block.begin() + n, block.end(),
                      std::to_string(pair.second));
        // std::cout << "found: " << block << '\n';
      }
    }
  }

  a.set(block);
  this->block->write(a);
}
