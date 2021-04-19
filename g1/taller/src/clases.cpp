//
// Created by Guille on 19/04/2021.
//

#include <iostream>
#include "clases.h"

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia) {}

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

ostream& operator<<(ostream& os, Fecha fecha) {
    os << fecha.dia() << "/" << fecha.mes();
    return os;
}


bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia() && this->mes() == o.mes();
    return igual_dia;
}

void Fecha::incrementar_dia() {
    if (this->dia() + 1 > dias_en_mes(this->mes())) {
        dia_ = 1;
        if (this->mes() + 1 > 12){
            mes_ = 1;
        } else {
            mes_ = mes_ + 1;
        };
    } else {
        dia_ = dia_ + 1;
    }
}

Horario::Horario(uint hora, uint min) : hora_(hora), min_(min) {}

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    return this->hora() == o.hora() && this->min() == o.min();
}

ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator<(Horario h) {
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

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.horario();
    return os;
}
