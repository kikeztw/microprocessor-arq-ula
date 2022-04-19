#ifndef UTILS_H
#define UTILS_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
void read(const std::string &path, std::vector<std::string> *L1I,
          std::vector<int> *L1D, std::map<std::string, int> *dic,
          std::map<std::string, int> *dicB);
#endif // !UTILS_H
