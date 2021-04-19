//
// Created by Guille on 19/04/2021.
//

#ifndef TALLER_HORARIO_H
#define TALLER_HORARIO_H
#include "fecha.h"

class Horario {
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator==(Horario o);
        bool operator<(Horario h);

    private:
        uint hora_;
        uint min_;
    };

ostream& operator<<(ostream& os, Horario h);

#endif //TALLER_HORARIO_H
