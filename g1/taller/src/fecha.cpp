//
// Created by Guille on 19/04/2021.
//

#include <iostream>
#include "fecha.h"

using namespace std;

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