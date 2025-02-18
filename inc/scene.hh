#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <list>
#include "ObiektGeom.hh"
#include "Lazik.hh"
#include <chrono>
#include <thread>
#include "lacze_do_gnuplota.hh"
#include "Kolory.hh"
#include "probka_regolitu.hh"
#include "PowierzchniaMarsa.hh"
#include "lazik_sfr.hh"


using namespace std::this_thread;
using namespace std::chrono;


class scena
{
public:
    std::shared_ptr<Lazik> aktywny_lazik;
    std::list<std::shared_ptr<Lazik>> lista_lazikow;
    std::list<std::shared_ptr<probka_regolitu>> lista_probek;
    std::shared_ptr<lazik_sfr> Lazik_zbierajacy;
    PzG::LaczeDoGNUPlota Lacze;


    void Doddaj ();
    void animuj_przesuniecie(double przesuniecie);
    void animuj_obrot(double kat_obr);
    void wybierz_lazika();
    scena();
    std::shared_ptr<Lazik> get(std::list<std::shared_ptr<Lazik>> lista_lazikow, int _i);
    std::shared_ptr<probka_regolitu> get(std::list<std::shared_ptr<probka_regolitu>> lista_probek, int _i);
     std::shared_ptr<ObiektGeom> get(std::list<std::shared_ptr<ObiektGeom>> lista_probek, int _i);
    void wyswietl_liste_probek();


};

void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze);
void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb);
void czekaj();