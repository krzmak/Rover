#pragma once

//probowalem ale nie dzialalo

#include "Lazik.hh"
#include "probka_regolitu.hh"
#include <thread>
#include <list>

class lazik_sfr: public Lazik
{
private:
    std::list<std::shared_ptr<probka_regolitu>> _lista_probek;
public:
    void Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik) override;
    using Lazik::Lazik;
};
