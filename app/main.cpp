#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "vektor3d.hh"
#include "vektor2d.hh"
#include "vector.hh"
#include "matrix.hh"
#include "matrix3d.hh"
#include "scene.hh"
#include "lazik_sfr.hh"

using namespace std;




/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */

int main()
{

  scena Scena;

  cout << endl << "Start programu gnuplot" << endl << endl;
  Scena.Lacze.Rysuj();

  Scena.wyswietl_liste_probek();
  Scena.wybierz_lazika();
  Scena.aktywny_lazik->wypisz_obrys();
  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  Scena.animuj_przesuniecie(80);
  Scena.aktywny_lazik->wypisz_obrys();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  Scena.animuj_obrot(90);
  Scena.aktywny_lazik->wypisz_obrys();
  
  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  Scena.animuj_przesuniecie(90);
  Scena.aktywny_lazik->wypisz_obrys();
 
  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n'); 
  Scena.animuj_obrot(90);
  Scena.aktywny_lazik->wypisz_obrys();
  
  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  Scena.animuj_przesuniecie(50);
  Scena.aktywny_lazik->wypisz_obrys();
  
  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  Scena.animuj_przesuniecie(50);
  Scena.aktywny_lazik->wypisz_obrys();

  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');
}
