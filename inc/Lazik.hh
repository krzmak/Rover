#pragma once

#include <chrono>
#include <thread>
#include "ObiektGeom.hh"

class Lazik: public ObiektGeom, public matrixrot{
private:
    double Kat_orientacji = 0;
    double odleglosc_do_przejechania;
    Vector3d _Przesuniecie;
public:
void Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik) override;
void przesun_lazik(double odleglosc);
void obroc_lazik(double kat);
using ObiektGeom::ObiektGeom;
};
