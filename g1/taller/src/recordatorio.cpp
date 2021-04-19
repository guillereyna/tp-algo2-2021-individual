//
// Created by Guille on 19/04/2021.
//

#include "recordatorio.h"

Recordatorio::Recordatorio(Fecha f, Horario h, string msg) : msg_(msg), horario_(h), fecha_(f) {}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}

string Recordatorio::mensaje() {
    return msg_;
}

bool Recordatorio::operator<(Recordatorio r) {
    return this->horario() < r.horario();
}

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
