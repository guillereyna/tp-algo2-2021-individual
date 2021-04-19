//
// Created by Guille on 19/04/2021.
//

#include "agenda.h"

Agenda::Agenda(Fecha fecha_inicial) : fechaDeHoy_(fecha_inicial), listaDeRecordatorios_(list<Recordatorio>()) {}

void Agenda::incrementar_dia() {
    fechaDeHoy_.incrementar_dia();
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    listaDeRecordatorios_.push_back(rec);
}

Fecha Agenda::hoy() {
    return fechaDeHoy_;
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recDeHoy;
    for (auto rec : listaDeRecordatorios_) {
        if (rec.fecha() == fechaDeHoy_) {
            recDeHoy.push_back(rec);
        }
    }
    return recDeHoy;
}