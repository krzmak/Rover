#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#pragma once
#include <string>
#include "vektor3d.hh"
#include "matrix3d.hh"
#include "vector.hh"
#include "obrysxy.hh"
#include "vektor2d.hh"
#include "memory"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "../pliki_do_rysowania"

class ObiektGeom {
  protected:
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    Vector3d _Skala;
    Vector3d _Polozenie;
    matrixrot MacRotacji;
  
  public:

    obrysxy Obrys;

    virtual void Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik){std::shared_ptr<ObiektGeom> A = Wsk_lazik;};//Kazda metoda virtualna musi byc zefiniowana (same puste nawiasy by wystarczyly {}, ale daje error unused variable)

    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, Vector3d Skala, Vector3d Polozenie);

    int WezKolorID() const { return _KolorID; }
  
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
  
    const std::string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }

    bool Przelicz_i_Zapisz_Wierzcholki();

    void wypisz_obrys();				     
};

#endif
