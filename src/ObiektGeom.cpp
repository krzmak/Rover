#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"



using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID,
            Vector3d Skala,
            Vector3d Polozenie
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
  _Skala = Skala;
  _Polozenie = Polozenie;
}

void ObiektGeom::wypisz_obrys()
{
    std::cout<<"Wierzcholek dolny prawy"<<Obrys.W_dolnyprawy<<std::endl;
    std::cout<<"Wierzcholek gorny lewy"<<Obrys.W_gornylewy<<std::endl;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  double tymczasowe_x = -100000;
  double tymczasowe_y = 100000;

  double tymczasowe_x2 = 100000;
  double tymczasowe_y2 = -100000;

  double x;
  double y;

  double x2;
  double y2;

  double  WspX, WspY, WspZ;
  int Indeks_Wiersza = 0;
  
  StrmWe >> WspX >> WspY >> WspZ;

  if (StrmWe.fail())return false;
  
  do {
    WspX = WspX*_Skala[0];
    WspY = WspY*_Skala[1];  
    WspZ = WspZ*_Skala[2];
    double wsp[] = {WspX,WspY,WspZ};
    Vector3d Wspolrzendne = wsp;
  
    Wspolrzendne = MacRotacji * Wspolrzendne;
    Wspolrzendne = Wspolrzendne + _Polozenie;

    WspX = Wspolrzendne[0];
    WspY = Wspolrzendne[1];
    WspZ = Wspolrzendne[2];

    if(WspY <= tymczasowe_y && WspZ == 0)
    {
      y = WspY;
      tymczasowe_y = WspY;
    }

      if(WspX >= tymczasowe_x && WspZ == 0)
    {
      x = WspX;
      tymczasowe_x = WspX;
    }

    if(WspY >= tymczasowe_y2 && WspZ == 0)
    {
       y2 = WspY;
       tymczasowe_y2 = WspY;
    }

      if(WspX <= tymczasowe_x2 && WspZ == 0)
    {
      x2 = WspX;
      tymczasowe_x2 = WspX;
    }

    StrmWy << WspX << " " << WspY << " " << WspZ << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> WspX >> WspY >> WspZ;
    
  } while (!StrmWe.fail());

  Obrys.W_dolnyprawy[0] = x;
  Obrys.W_dolnyprawy[1] = y;

  Obrys.W_gornylewy[0] = x2;
  Obrys.W_gornylewy[1] = y2;
  

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

template class Vector<double, 3>;
template class Matrix<double, 3>;
template class Vector<double, 2>;