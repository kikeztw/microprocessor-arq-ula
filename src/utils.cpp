#include "utils.h"

// sobrecarga de funcion para funcionar sc_in<string>
std::ostream &operator<<(std::ostream &os, const string &trans) {
  os << trans.get();
  return os;
}
// end
// trace function, only required if actually used
void sc_trace(sc_trace_file *&tf, const string &trans, std::string nm) {
  sc_trace(tf, trans, nm + ".str");
} // end trace

void clear(){
    cout << "\x1B[2J\x1B[H";
}


// ------------------------------------------------------ end sobrecarga

// static bool _text = false;
// static bool _data = false;
// void read(const std::string &path, std::vector<std::string> *L1I,
//           std::vector<int> *L1D, std::map<std::string, int> *dic = NULL,
//           std::map<std::string, int> *dicB = NULL) {
//   int i = 0;
//   int direccionID{0};
//   std::ifstream input_file(path);
//   if (!input_file.is_open()) {
//     std::cerr << "Could not open the file - '" << path << "'" << std::endl;
//     exit(EXIT_FAILURE);
//   }

//   std::string linea;
//   while (std::getline(input_file, linea)) {
//     std::stringstream stream(linea);
//     std::string valor;

//     // std::cout << "Contenido de la linea:\n";
//     while (std::getline(stream, valor, '\t')) {
//       if (valor == ".data") {
//         _data = true;
//         _text = false;
//         continue;
//       }

//       if (valor == ".text") {
//         _text = true;
//         _data = false;
//         continue;
//       }

//       if (_data) {
//         // std::remove_if(valor.begin(), valor.begin() + 2, ::isspace);
//         std::string v;
//         // std::cout << valor.find(":") + 1 << std::endl;
//         std::stringstream d(valor.substr(valor.find(":") + 1));
//         while (std::getline(d, v, ',')) {
//           // std::cout << v;
//           L1D->push_back(std::stoi(v));
//           i += 4;
//         }

//         dicB->insert({valor.substr(2, valor.find(":")), i});
//       }
//       if (_text) {
//         if (valor[valor.find(":")] == ':') {
//           (*dic).insert({valor.substr(2, valor.find(":")), i});
//           continue;
//         }
//         // valor.pop_back();
//         // valor.pop_back();
//         L1I->push_back(valor.substr(4));
//         i++;
//       }
//     }
//     // std::cout << "Fin de la linea\n";
//   }
//   // std::string allAss =
//   // std::string((std::istreambuf_iterator<char>(input_file)),
//   // std::istreambuf_iterator<char>());
// }
