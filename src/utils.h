#ifndef UTILS_H
#define UTILS_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <systemc.h>

enum OPCODES { NONE, SUM, SUB, DIV, MUL, AND, OR }; //

class string { // previously as struct

public:
  std::string str;
  void set(std::string tmp) { str = tmp; }
  std::string get() const { return this->str; }
  // Required by sc_signal<> and sc_fifo<>
  string &operator=(const string &rhs) {
    str = rhs.str;
    return *this;
  }
  // Required by sc_signal<>
  bool operator==(const string &rhs) const { return str == rhs.str; }
  friend std::ostream &operator<<(std::ostream &file, const string &trans);
  friend void sc_trace(sc_trace_file *&tf, const string &trans, std::string nm);
};

void clear();

void read(const std::string &path, std::vector<std::string> *L1I,
          std::map<std::string, int> *dic, std::vector<int> *L1D,
          std::map<std::string, int> *dicB);
#endif // !UTILS_H
