#include "instruction_memory.h"

#include <sysc/datatypes/int/sc_uint.h>

#include <cmath>

#include "utils.h"

InstructioMemory::InstructioMemory(sc_module_name nm) : sc_module(nm)
{
  SC_METHOD(read);
  sensitive << address;
  // dont_initialize();
}
void InstructioMemory::read()
{
  string a;
  auto addres = address.read();
  std::string block;

  if (addres >= L1_I.size())
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
    n = block.find(pair.first);

    if (n != std::string::npos) {
      block.replace(block.begin() + n, block.end(),
                    std::to_string(pair.second));
    }
  }

  // traduce las etiquetas de valores en memoria de datos
  if (pointer_l1D != NULL) {
    for (auto &pair : *pointer_l1D) {
      n = block.find(pair.first);

      if (n != std::string::npos) {
        block.replace(block.begin() + n, block.end(),
                      std::to_string(pair.second));
      }
    }
  }

  a.set(block);
  sc_uint<5> op = getOP(block);
  sc_uint<5> rd = getRd(block);
  sc_uint<5> rs1 = getRs1(block, op);
  sc_uint<5> rs2 = getRs2(block, op);
  sc_uint<32> imm = getimm(block, op);
  this->op->write(op);
  this->rd.write(rd);
  this->rs1->write(rs1);
  this->rs2->write(rs2);
  this->imm.write(imm);
  // std::cout << "\nop: " << op << "  rd: " << rs1 << "  rs1: " << rs1 << "\n";
  this->block->write(a);
}

std::vector<std::string> split(std::string block)
{
  std::vector<std::string> aux;
  std::stringstream stream(block);
  std::string valor;

  // std::cout << "Contenido de la linea:\n";
  while (std::getline(stream, valor, ' ')) {
    valor.erase(std::remove(valor.begin(), valor.end(), ' '), valor.end());
    valor.erase(std::remove(valor.begin(), valor.end(), ','), valor.end());
    valor.erase(std::remove(valor.begin(), valor.end(), '('), valor.end());
    valor.erase(std::remove(valor.begin(), valor.end(), ')'), valor.end());
    aux.push_back(valor);
  }
  return aux;
};
bool isNumber(const std::string &str)
{
  for (char const &c : str) {
    if (std::isdigit(c) == 0)
      return false;
  }
  return true;
}
sc_uint<5> InstructioMemory::getimm(std::string &block, sc_uint<5> &op)
{
  std::vector<std::string> split_ = split(block);

  if (op == lw || op == sw) {
    return isNumber(split_[2]) ? std::stoi(split_[2]) : 0;
  } else if (isNumber(split_[3])) {
    return std::stoi(split_[3]);
  };

  return 0;
}
sc_uint<5> InstructioMemory::getRs2(std::string &block, sc_uint<5> &op)
{
  std::vector<std::string> split_ = split(block);

  auto found = [&](std::string copy) {
    if (op == lw || op == sw) {
      return false;
    } else {
      if (split_[3] == copy) {
        return true;
      }
    }

    return false;
  };

  if (found("zero")) {
    return zero;
  } else if (found("ra")) {
    return ra;
  } else if (found("sp")) {
    return sp;
  } else if (found("gp")) {
    return gp;
  } else if (found("tp")) {
    return tp;
  } else if (found("t0")) {
    return t0;
  } else if (found("t1")) {
    return t1;
  } else if (found("t2")) {
    return t2;
  } else if (found("s0")) {
    return s0;
    // } else if (found("fp")) {
    //   return fp;
    //
  } else if (found("s1")) {
    return s1;
  } else if (found("a0")) {
    return a0;
  } else if (found("a1")) {
    return a1;
  } else if (found("a2")) {
    return a2;
  } else if (found("a3")) {
    return a3;
  } else if (found("a4")) {
    return a4;
  } else if (found("a5")) {
    return a5;
  } else if (found("a6")) {
    return a6;
  } else if (found("a7")) {
    return a7;
  } else if (found("s2")) {
    return s2;
  } else if (found("s3")) {
    return s3;
  } else if (found("s4")) {
    return s4;
  } else if (found("s5")) {
    return s5;
  } else if (found("s6")) {
    return s6;
  } else if (found("s7")) {
    return s7;
  } else if (found("s8")) {
    return s8;
  } else if (found("s9")) {
    return s9;
  } else if (found("s10")) {
    return s10;
  } else if (found("s11")) {
    return s11;
  } else if (found("t3")) {
    return t3;
  } else if (found("t4")) {
    return t4;
  } else if (found("t5")) {
    return t5;
  } else if (found("t6")) {
    return t6;
  }
  return x0;
}
sc_uint<5> InstructioMemory::getRs1(std::string &block, sc_uint<5> &op)
{
  std::vector<std::string> split_ = split(block);

  auto found = [&](std::string copy) {
    if (op == lw || op == sw) {
      if (split_[3] == copy) {
        return true;
      }
    } else {
      if (split_[2] == copy) {
        return true;
      }
    }

    return false;
  };

  if (found("zero")) {
    return zero;
  } else if (found("ra")) {
    return ra;
  } else if (found("sp")) {
    return sp;
  } else if (found("gp")) {
    return gp;
  } else if (found("tp")) {
    return tp;
  } else if (found("t0")) {
    return t0;
  } else if (found("t1")) {
    return t1;
  } else if (found("t2")) {
    return t2;
  } else if (found("s0")) {
    return s0;
    // } else if (found("fp")) {
    //   return fp;
    //
  } else if (found("s1")) {
    return s1;
  } else if (found("a0")) {
    return a0;
  } else if (found("a1")) {
    return a1;
  } else if (found("a2")) {
    return a2;
  } else if (found("a3")) {
    return a3;
  } else if (found("a4")) {
    return a4;
  } else if (found("a5")) {
    return a5;
  } else if (found("a6")) {
    return a6;
  } else if (found("a7")) {
    return a7;
  } else if (found("s2")) {
    return s2;
  } else if (found("s3")) {
    return s3;
  } else if (found("s4")) {
    return s4;
  } else if (found("s5")) {
    return s5;
  } else if (found("s6")) {
    return s6;
  } else if (found("s7")) {
    return s7;
  } else if (found("s8")) {
    return s8;
  } else if (found("s9")) {
    return s9;
  } else if (found("s10")) {
    return s10;
  } else if (found("s11")) {
    return s11;
  } else if (found("t3")) {
    return t3;
  } else if (found("t4")) {
    return t4;
  } else if (found("t5")) {
    return t5;
  } else if (found("t6")) {
    return t6;
  }
  return x0;
}
sc_uint<5> InstructioMemory::getRd(std::string &block)
{
  std::vector<std::string> split_ = split(block);

  auto found = [&](std::string copy) {
    if (split_[1] == copy) {
      return true;
    }
    return false;
  };

  if (found("zero")) {
    return zero;
  } else if (found("ra")) {
    return ra;
  } else if (found("sp")) {
    return sp;
  } else if (found("gp")) {
    return gp;
  } else if (found("tp")) {
    return tp;
  } else if (found("t0")) {
    return t0;
  } else if (found("t1")) {
    return t1;
  } else if (found("t2")) {
    return t2;
  } else if (found("s0")) {
    return s0;
    // } else if (found("fp")) {
    //   return fp;
    //
  } else if (found("s1")) {
    return s1;
  } else if (found("a0")) {
    return a0;
  } else if (found("a1")) {
    return a1;
  } else if (found("a2")) {
    return a2;
  } else if (found("a3")) {
    return a3;
  } else if (found("a4")) {
    return a4;
  } else if (found("a5")) {
    return a5;
  } else if (found("a6")) {
    return a6;
  } else if (found("a7")) {
    return a7;
  } else if (found("s2")) {
    return s2;
  } else if (found("s3")) {
    return s3;
  } else if (found("s4")) {
    return s4;
  } else if (found("s5")) {
    return s5;
  } else if (found("s6")) {
    return s6;
  } else if (found("s7")) {
    return s7;
  } else if (found("s8")) {
    return s8;
  } else if (found("s9")) {
    return s9;
  } else if (found("s10")) {
    return s10;
  } else if (found("s11")) {
    return s11;
  } else if (found("t3")) {
    return t3;
  } else if (found("t4")) {
    return t4;
  } else if (found("t5")) {
    return t5;
  } else if (found("t6")) {
    return t6;
  }
  return x0;
}
sc_uint<5> InstructioMemory::getOP(std::string &block_)
{
  std::vector<std::string> split_ = split(block_);

  auto found = [&](std::string copy) {
    if (split_[0] == copy) {
      return true;
    }
    return false;
  };
  if (found("addi")) {
    return addi;
  } else if (found("add")) {
    return add;
  } else if (found("lw")) {
    return lw;
  } else if (found("beq")) {
    return beq;
  } else if (found("ble")) {
    return ble;
  } else if (found("jalr")) {
    return jalr;
  }

  return 0;
}
