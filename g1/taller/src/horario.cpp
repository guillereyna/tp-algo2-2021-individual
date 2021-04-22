//
// Created by Guille on 19/04/2021.
//

#include "horario.h"

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}

uint Horario::hora() const {
    return hora_;
}

uint Horario::min() const {
    return min_;
}

bool Horario::operator==(const Horario o) const {
    return this->hora() == o.hora() && this->min() == o.min();
}

ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(const Horario h) const {
    bool res = false;
    if (this->hora() < h.hora()) {
        res = true;
    } else {
        if (this->min() < h.min()) {
            res = true;
        } else { res = false; };
    }
    return res;
}