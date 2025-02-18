#pragma once

#include <chrono>
#include <thread>
#include "ObiektGeom.hh"


class probka_regolitu: public ObiektGeom
{
public:
    using ObiektGeom::ObiektGeom;

    void Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik) override;
    std::string get_nazwa(){return this -> _NazwaObiektu;};

};

std::ostream &operator << (std::ostream &out, probka_regolitu &tmp);