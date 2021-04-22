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
    bool operator==(const Fecha o) const;
    Fecha(int mes, int dia);
    int mes() const;
    int dia() const;
    void incrementar_dia();

private:
    int mes_;
    int dia_;
};

ostream& operator<<(ostream& os, Fecha fecha);


#endif //TALLER_FECHA_H
