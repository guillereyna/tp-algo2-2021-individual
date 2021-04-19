//
// Created by Guille on 19/04/2021.
//

#ifndef TALLER_AGENDA_H
#define TALLER_AGENDA_H
#include <list>
#include "clases.h"

class Agenda{
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();
};

#endif //TALLER_AGENDA_H
