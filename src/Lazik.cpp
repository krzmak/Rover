#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"
#include <cmath>
using namespace std::this_thread;
using namespace std::chrono;

void Lazik::Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik)
{   
     if(Obrys.czy_nakladaja(Wsk_lazik -> Obrys) == true)
     std::cout<<"uderzono w inny Lazik"<<std::endl;
}
void Lazik::przesun_lazik(double odleglosc)
{
     _Przesuniecie[0] = cos(Kat_orientacji) * odleglosc;
     _Przesuniecie[1] = sin(Kat_orientacji) * odleglosc;
     _Przesuniecie[2] = 0;
    _Polozenie = _Polozenie + _Przesuniecie;
}

template class Vector<double, 3>;

void Lazik::obroc_lazik(double kat)
{
    Kat_orientacji += kat;
    Vector3d aktualne_polozenie;
    double zero[] = {0,0,0};
    matrixrot oz;

    aktualne_polozenie = _Polozenie; 
    _Polozenie = zero;

    MacRotacji.wypelnijRotZ(oz,Kat_orientacji);
    MacRotacji = oz;


    _Polozenie = _Polozenie + aktualne_polozenie;
}


