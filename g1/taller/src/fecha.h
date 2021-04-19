//
// Created by Guille on 19/04/2021.
//

#ifndef TALLER_FECHA_H
#define TALLER_FECHA_H

#include <iostream>

using uint = unsigned int;
using namespace std;

class Fecha {
public:
    bool operator==(Fecha o);
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();

private:
    int mes_;
    int dia_;
};

ostream& operator<<(ostream& os, Fecha fecha);


#endif //TALLER_FECHA_H
