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



// ------FUNCION LEER INSTRUCCION, RECIBE EL STRING Y 4 ENTEROS---------


void readInstruction(std::string instruction, int data[4]){
    data[0]=99;
    //data hace referencia a 4 resultados, 0. Instruccion  1. Registro Destino  2. Primer dato  3. Segundo dato
    std::vector<std::string>Dic={"addi","add","lw","beq","ble","jarl"};
    std::vector<std::string>parts;
    //separamos el string en 4 strings
    parts=split(instruction,',');
  //Aignamos en data[0] que instruccion vamos a hacer
    for(int i=0 ; i<5 ; i++){      
        if(compareString(parts[0],Dic[i])==1){
            data[0]=i;
            break;
        }
    }
    //Quitamos la x del registro destino
    if(parts[1][0]=='x'||parts[1][0]=='X'){
        parts[1][0]=parts[1][1];
        parts[1][1]=parts[1][2];
        parts[1][2]=parts[1][3];
    }//Asignamos el valor del registro destino
    data[1]=atoi(parts[1].c_str());


    //Quitamos la x del dato 1
    if(parts[2][0]=='x'||parts[2][0]=='X'){
        parts[2][0]=parts[2][1];
        parts[2][1]=parts[2][2];
        parts[2][2]=parts[2][3];
    }//Asignamos el valor de dato 1
    data[2]=atoi(parts[2].c_str());


    //Quitamos la x del dato 2
    if(parts[3][0]=='x'||parts[3][0]=='X'){
        parts[3][0]=parts[3][1];
        parts[3][1]=parts[3][2];
        parts[3][2]=parts[3][3];
    }//Asignamos el valor del registro destino
    data[3]=atoi(parts[3].c_str());

    if(data[0]==99){//en el caso de que la instruccion sea invalida, data seguira siendo 99
        data[0]=0;//entonces pondemos la instruccion addi,x0,zero,1 que no hace nada
        data[1]=0;
        data[2]=0;
        data[3]=1;
    }
}


// -------- FUNCION HACER SPLIT A UN STRING ------- RECIBE EL STRING Y EL SEPARADOR

std::vector<std::string> split(std::string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}



// ----------------FUNCION COMPARA DOS STRING, 0 DIF 1 IGUALES --------------
bool compareString(std::string A, std::string B){
    if(A.size() != B.size())return 0;
    int t=A.size();
    for(int i=0 ; t ; i++){
        if(A[i]!=B[i])return 0;
    }
    return 1;
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
