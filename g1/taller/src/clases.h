//
// Created by Guille on 19/04/2021.
//

#ifndef TALLER_CLASES_H
#define TALLER_CLASES_H

using namespace std;

class Fecha {
public:
    bool operator==(Fecha o);
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();

private:
    int mes_;
    int dia_;
};

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

class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string msg);
    Fecha fecha();
    Horario horario();
    string mensaje();

private:
    string msg_;
    Horario horario_;
    Fecha fecha_;
};

#endif //TALLER_CLASES_H
