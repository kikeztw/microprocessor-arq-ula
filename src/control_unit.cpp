#include "control_unit.h"

ControlUnit::ControlUnit(sc_module_name nm) : sc_module(nm) {
  tag = "";
  SC_METHOD(operation);
  sensitive << sIn;
}

void ControlUnit::operation() {
  readInstruction();
  flush();
  // no se puede usar 0 como valor inmediato; se debe usar el registro x0
  controlOut.write(data[0]);

  string tmp;


    switch (data[0])
    {
    //save word
    case SW:
      raOut.write(data[1]);
      bOut.write(data[2]);
      rbOut.write(data[3]);
    break;

    //salto
    case 3:
    case 4:
    case 5:
      tmp.str = tag;
      tagOut.write(tmp);
      raOut.write(data[1]);
      // si tiene valor inmediato que sea en el segundo operando
      if (data[4] == 0)
        rbOut.write(data[2]);
      else {
        rbOut.write(0);
        bOut.write(data[2]);
      }

      break;
    // noramles
    default:
      rwOut.write(data[1]);
      if (data[4] == 0)
        raOut.write(data[2]);
      else {
        raOut.write(0);
        aOut.write(data[2]);
      }

      if (data[5] == 0)
        rbOut.write(data[3]);
      else {
        rbOut.write(0);
        bOut.write(data[3]);
      }
      break;
    }

}

void ControlUnit::flush() {
  controlOut.write(0);
  rwOut.write(0);
  raOut.write(0);
  rbOut.write(0);
  aOut.write(0);
  bOut.write(0);
  string a;
  a.str = "";
  tagOut.write(a);
}

// ------FUNCION LEER INSTRUCCION, RECIBE EL STRING Y 4 ENTEROS---------

void ControlUnit::readInstruction() {

  std::string instruction = sIn.read().str;

  if (instruction == "") {
    data[0] = 0; // entonces pondemos la instruccion addi,x0,zero,1 que no hace nada
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
    return;
  }

  data[0] = 0;
  data[4] = 0;
  data[5] = 0;

  // data hace referencia a 4 resultados, 0. Instruccion  1. Registro
  // Destino  2. Primer dato  3. Segundo dato
  std::vector<std::string> Dic = {"add", "sub", "beq", "bne", "blt",
  "div", "mod", "mulh", "mull", "and", "or", "lw","sw" };
  std::vector<std::string> parts, parts1;
  // separamos el string en 4 strings

  std::regex re("[\\s|,())]");
  std::sregex_token_iterator first{instruction.begin(), instruction.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
  std::vector<std::string> tokens{first, last};

  for(auto i: tokens){
    if(!i.empty()){
      parts.push_back(i);
    }
  }

  // std::cout << "\ntest:";
  // for(int i=0;i<parts.size(); i++)
  //   std::cout << parts[i] << ",";

  int size = Dic.size();
  // Aignamos en data[0] que instruccion vamos a hacer
  for (int i = 0; i < size; i++) {
    if (compareString(parts[0], Dic[i]) == 1) {

      data[0] = i + 1;
      break;
    }
  }

  // Quitamos la x del registro destino
  if (parts[1][0] == 'x' || parts[1][0] == 'X') {
    parts[1][0] = parts[1][1];
    parts[1][1] = parts[1][2];
    parts[1][2] = parts[1][3];
  } // Asignamos el valor del registro destino
  data[1] = atoi(parts[1].c_str());

  // Quitamos la x del dato 1
  if (parts[2][0] == 'x' || parts[2][0] == 'X') {
    parts[2][0] = parts[2][1];
    parts[2][1] = parts[2][2];
    parts[2][2] = parts[2][3];
  } else {
    // si es valor inmediato
    data[4] = 1;
  }

  // Asignamos el valor de dato 1
  data[2] = atoi(parts[2].c_str());

  // si es salto
  if (data[0] == 3 || data[0] == 4 || data[0] == 5) {
    data[5] = 2;
    tag = parts[3];
  } else {
    // Quitamos la x del dato 2
    if (parts[3][0] == 'x' || parts[3][0] == 'X') {
      parts[3][0] = parts[3][1];
      parts[3][1] = parts[3][2];
      parts[3][2] = parts[3][3];
    } else {
      // si es valor inmediato
      data[5] = 1;
    }
    // Asignamos el valor del registro
    data[3] = atoi(parts[3].c_str());
  }

  if (data[0] == 0) { // en el caso de que la instruccion sea invalida, data
                      // seguira siendo 99
    data[0] =
        0; // entonces pondemos la instruccion addi,x0,zero,1 que no hace nada
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    data[5] = 0;
  }
}

// -------- FUNCION HACER SPLIT A UN STRING ------- RECIBE EL STRING Y EL
// SEPARADOR

std::vector<std::string> ControlUnit::split(std::string str, char pattern) {

  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

// ----------------FUNCION COMPARA DOS STRING, 0 DIF 1 IGUALES --------------
bool ControlUnit::compareString(std::string A, std::string B) {
  if (A.size() != B.size())
    return 0;
  int t = A.size();
  for (int i = 0; i < t; i++) {
    if (A[i] != B[i])
      return 0;
  }
  return 1;
}
