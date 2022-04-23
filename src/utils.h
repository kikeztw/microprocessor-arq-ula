#ifndef UTILS_H
#define UTILS_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <systemc.h>
#include <vector>






void readInstruction(std::string, int[]);//Esta funcion Lee la instruccion
std::vector<std::string> split(std::string, char);//Esta funcion hace split de la linea
bool compareString(std::string, std::string);//Compara dos strings ( 0 diferentes. 1 iguales)




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






// void read(const std::string &path, std::vector<std::string> *L1I,
//           std::vector<int> *L1D, std::map<std::string, int> *dic,
//           std::map<std::string, int> *dicB);
#endif // !UTILS_H


