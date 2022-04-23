#ifndef UTILS_H
#define UTILS_H
#include <systemc.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

enum Instruction { add = 1, addi, sub, subi, lw, sw, beq, ble, jalr };

enum registros {
  x0 = 0,
  x1 = 1,
  x2,
  x3,
  x4,
  x5,
  x6,
  x7,
  x8,
  x9,
  x10,
  x11,
  x12,
  x13,
  x14,
  x15,
  x16,
  x17,
  x18,
  x19,
  x20,
  x21,
  x22,
  x23,
  x24,
  x25,
  x26,
  x27,
  x28,
  x29,
  x30,
  x31,
  zero = x0,
  ra = x1,
  sp = x2,
  gp = x3,
  tp = x4,
  t0 = x5,
  t1 = x6,
  t2 = x7,
  s0 = x8,
  fp = x8,
  s1 = x9,
  a0 = x10,
  a1 = x11,
  a2 = x12,
  a3 = x13,
  a4 = x14,
  a5 = x15,
  a6 = x16,
  a7 = x17,
  s2 = x18,
  s3 = x19,
  s4 = x20,
  s5 = x21,
  s6 = x22,
  s7 = x23,
  s8 = x24,
  s9 = x25,
  s10 = x26,
  s11 = x27,
  t3 = x28,
  t4 = x29,
  t5 = x30,
  t6 = x31
};

class string
{  // previously as struct

 public:
  std::string str;
  void set(std::string tmp)
  {
    str = tmp;
  }
  std::string get() const
  {
    return this->str;
  }
  // Required by sc_signal<> and sc_fifo<>
  string &operator=(const string &rhs)
  {
    str = rhs.str;
    return *this;
  }
  // Required by sc_signal<>
  bool operator==(const string &rhs) const
  {
    return str == rhs.str;
  }
  friend std::ostream &operator<<(std::ostream &file, const string &trans);
  friend void sc_trace(sc_trace_file *&tf, const string &trans, std::string nm);
};

void read(const std::string &path,
          std::vector<std::string> *L1I,
          std::map<std::string, int> *dic,
          std::vector<int> *L1D,
          std::map<std::string, int> *dicB);
#endif  // !UTILS_H
