#ifndef CELL_H
#define CELL_H

#include <systemc.h>

/* El módulo Cell básicamente es una "celda" de memoria en la cual se almacena 1 b
t; y sobre ésta celda se harán operaciones de lectura y escritura (de
scritura solo cuando esté habilitada). */
class Cell : public sc_module {
public:
  /* weIn: significa write enable input (es un booleano que indica si se
    habilita o no la escritura) clkIn: ésta celda recibe el clock como entrada 
    ara saber en qué momento leer y en qué momento escribir (escribir si es que
    está habilitada la escritura) con weIn. wIn: para cuando se vaya a escribir,
    se usará el dato wIn de entrada.
  */
  sc_in<bool> /* weIn, */ clkIn, wIn;
  /* La manera de simular el almacenamiento no es nada del otro mundo, es
  sencillamente declararlo dentro
  del módulo. En éste caso el almacenamiento de la celda es un bit que r
  presentamos como un booleano. */
  bool storage;
  sc_out<bool> dataOut;

  SC_CTOR(Cell);

private:
  // Podemos separar las operaciones de escritura y de lectura para tener un
  // código más legible.
  void read();
  void write();
};

#endif
