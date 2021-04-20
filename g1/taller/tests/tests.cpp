//
// Created by Guille on 19/04/2021.
//
#include "gtest-1.8.1/gtest.h"
#include "../src/agenda.h"

TEST(agenda, test){
    EXPECT_EQ(1,1);
}

/* TEST(agenda, inicializar_agenda){
    Fecha f(1, 1);
    Agenda ag(f);
    list<Recordatorio> listaVacia;
    EXPECT_EQ(ag.hoy(), f);
    EXPECT_EQ(ag.recordatorios_de_hoy(), listaVacia);
} */