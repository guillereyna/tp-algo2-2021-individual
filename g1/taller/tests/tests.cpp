//
// Created by Guille on 19/04/2021.
//
#include "gtest-1.8.1/gtest.h"
#include "../src/agenda.h"

TEST(agenda, inicializar_agenda){
    Fecha f(1, 1);
    Agenda ag(f);
    list<Recordatorio> listaVacia;
    EXPECT_EQ(ag.hoy(), f);
    EXPECT_EQ(ag.recordatorios_de_hoy(), listaVacia);
}

TEST(agenda, incrementar_dia){
    Fecha f(1, 1);
    Agenda ag(f);
    ag.incrementar_dia();
    f.incrementar_dia();
    EXPECT_EQ(ag.hoy(), f);
    EXPECT_EQ(ag.hoy().dia(), 2);
    EXPECT_EQ(ag.hoy().mes(), 1);
}

TEST(agenda, pasa_de_mes){
    Fecha f(12, 31);
    Agenda ag(f);

    ag.incrementar_dia();
    f.incrementar_dia();

    EXPECT_EQ(ag.hoy(), f);
    EXPECT_EQ(ag.hoy().dia(), 1);
    EXPECT_EQ(ag.hoy().mes(), 1);
}

TEST(agenda, agrega_recordatorio){
    Fecha f(12, 31);
    Agenda ag(f);
    list<Recordatorio> target;

    Fecha f2(1, 1);
    Horario h(12, 30);
    string msg = "Test";

    Recordatorio r(f2, h, msg);

    target.push_back(r);

    ag.agregar_recordatorio(r);
    ag.incrementar_dia();

    f.incrementar_dia();

    EXPECT_EQ(ag.recordatorios_de_hoy(), target);
}

TEST(agenda, orden_correcto){
    Fecha f(12, 31);
    Agenda ag(f);
    list<Recordatorio> target;

    Fecha f2(12, 31);
    Horario h(12, 30);
    Horario h2(11, 0);
    string msg = "Test";

    Recordatorio r(f2, h, msg);
    Recordatorio r2(f2, h2, msg);

    target.push_back(r2); // estan en orden correcto
    target.push_back(r);

    ag.agregar_recordatorio(r); // los agrego en orden incorrecto
    ag.agregar_recordatorio(r2);

    EXPECT_EQ(ag.recordatorios_de_hoy(), target);
}

TEST(agenda, print){
    Fecha f(12, 31);
    Agenda ag(f);

    Fecha f2(12, 31);
    Horario h(12, 30);
    Horario h2(11, 0);
    string msg = "Test";

    Recordatorio r(f2, h, msg);
    Recordatorio r2(f2, h2, msg);

    ag.agregar_recordatorio(r); // los agrego en orden incorrecto
    ag.agregar_recordatorio(r2);

    Agenda a(Fecha(5, 10));
    a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(9, 0), "Clase Algo2"));
    a.agregar_recordatorio(Recordatorio(Fecha(5, 10), Horario(11, 0), "Labo Algo2"));

    cout << ag << endl << endl << a << endl;
}