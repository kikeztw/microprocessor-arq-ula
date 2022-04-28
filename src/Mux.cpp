#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In << aIn << bIn;
}

void Mux::operation() {
  /* Trabajar con entradas de varios bits es igual en varios sentidos.
  Lo que verán en ésta función es perfectamente aplicable a entradas de
  cualquier cantidad de bits.
  */
  if (s0In.read()) // Si el bit de selección es 1, entonces seleccionará la segunda entrada de datos.
    cOut.write(bIn.read());
  else // Si el bit de selección no es 1, es 0, entonces seleccionará la primera entrada de datos.
    cOut.write(aIn.read());
  /* Otra manera de hacerlo, puede ser con un operador ternario:
    cOut.write(s0In.read() ? bIn.read() : aIn.read());
  */
  /* NOTA: En cuanto a c++, me gustaría resaltar que al hacer comparaciones lógicas, cualquier
  número distinto de 0 se considera equivalente a true (sea positivo o negativo el número),
  mientras que 0 se considera equivalente a false.
  */
}
