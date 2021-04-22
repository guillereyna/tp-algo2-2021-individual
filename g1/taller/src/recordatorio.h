//
// Created by Guille on 19/04/2021.
//

#ifndef TALLER_RECORDATORIO_H
#define TALLER_RECORDATORIO_H
#include "horario.h"

class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string msg);
    Fecha fecha() const;
    Horario horario() const;
    string mensaje() const;
    bool operator<(const Recordatorio r) const;
    bool operator==(const Recordatorio r) const;

private:
    string msg_;
    Horario horario_;
    Fecha fecha_;
};

ostream& operator<<(ostream& os, Recordatorio r);

#endif //TALLER_RECORDATORIO_H
