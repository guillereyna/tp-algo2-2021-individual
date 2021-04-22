//
// Created by Guille on 19/04/2021.
//

#include "recordatorio.h"

Recordatorio::Recordatorio(Fecha f, Horario h, string msg) : msg_(msg), horario_(h), fecha_(f) {}

Fecha Recordatorio::fecha() const {
    return fecha_;
}

Horario Recordatorio::horario() const {
    return horario_;
}

string Recordatorio::mensaje() const {
    return msg_;
}

bool Recordatorio::operator<(const Recordatorio r) const {
    return this->horario() < r.horario();
}

bool Recordatorio::operator==(const Recordatorio r) const {
    return this->horario() == r.horario() && this->fecha() == r.fecha() && this->mensaje() == r.mensaje();
};

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
