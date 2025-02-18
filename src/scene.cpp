#include "scene.hh"
#include <algorithm>



void czekaj()
{
    sleep_for(nanoseconds(10000000));
    sleep_until(system_clock::now() + nanoseconds(10000000));
}

void scena::animuj_przesuniecie(double przesuniecie)
{
    double male_przesuniecie = 0.5;
    int i;
    std::shared_ptr<Lazik> tymczasowy;
    std::shared_ptr<probka_regolitu> probka;
    std::shared_ptr<probka_regolitu> _probki_do_podniesienia;
    /*std::shared_ptr<ObiektGeom> obiekt1 = std::make_shared<ObiektGeom>(static_cast<ObiektGeom>();*/
    for(i = 0; i <= przesuniecie; ++i)
    {   
        czekaj();
        tymczasowy = get(lista_lazikow,1);
        tymczasowy -> Czykolizja(aktywny_lazik);
        tymczasowy = get(lista_lazikow,2);
        tymczasowy -> Czykolizja(aktywny_lazik);
        for(int j = 0;j <= 6;++j)
        {
        probka = get(lista_probek,j);
        probka -> Czykolizja(aktywny_lazik);
        }

        aktywny_lazik -> przesun_lazik(male_przesuniecie);
        aktywny_lazik -> Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
    }
}

void scena::animuj_obrot(double kat_obr)
{
    double male_obr = 0.5;
    int i;
    for(i = 0; i <= kat_obr; ++i)
    {
        czekaj();
        aktywny_lazik -> obroc_lazik(male_obr);
        aktywny_lazik -> Przelicz_i_Zapisz_Wierzcholki();
        Lacze.Rysuj();
    }
}

void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}

void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(rOb.WezKolorID());
}


    std::shared_ptr<Lazik> scena::get(std::list<std::shared_ptr<Lazik>> lista_lazikow, int _i){
    std::list<std::shared_ptr<Lazik>>::iterator it = lista_lazikow.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

    std::shared_ptr<probka_regolitu> scena::get(std::list<std::shared_ptr<probka_regolitu>> lista_probek, int _i){
    std::list<std::shared_ptr<probka_regolitu>>::iterator it = lista_probek.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}

  std::shared_ptr<ObiektGeom> scena::get(std::list<std::shared_ptr<ObiektGeom>> _lista_probek, int _i){
    std::list<std::shared_ptr<ObiektGeom>>::iterator it = _lista_probek.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
  }

  void scena::wybierz_lazika()
  {
    std::cout<<"wybierz lazika wpisz od 1 do 3(kolizja dziala narazie dla lazika 1)"<<std::endl;
    int nr_lazika;
    std::cin>>nr_lazika;

    switch (nr_lazika)
    {
    case 1:
          aktywny_lazik = get(lista_lazikow,0);  
    break;

    case 2:
          aktywny_lazik = get(lista_lazikow,1);  
        break;

   case 3:
          aktywny_lazik = get(lista_lazikow,2);  
        break;
    default:
        break;
    }
  }

void scena::wyswietl_liste_probek()
{
  std::cout<<"lista probek:"<<std::endl;
  for(auto const &i: lista_probek)
  {
    std::cout << *i <<std::endl;
  }


}

scena::scena()
{
  Inicjalizuj_Lacze(Lacze);
  Inicjalizuj_PowierzchnieMarsa(Lacze);

    double Arg1[] = {0,0,0};
  Vector3d Polozenie1(Arg1);
  double Arg2[] = {20,20,10};
  Vector3d Skala1(Arg2);

  double Arg3[] = {60,60,0};
  Vector3d Polozenie2(Arg3);
  double Arg4[] = {20,20,10};
  Vector3d Skala2(Arg4);

  double Arg5[] = {-20,70,0};
  Vector3d Polozenie3(Arg5);
  double Arg6[] = {20,20,10};
  Vector3d Skala3(Arg6);

   double Arg7[] = {2,6,2};
  Vector3d Skala4(Arg7);
  double Arg8[] = {30,60,0};
  double Arg9[] = {20,60,2};
  double Arg10[] = {50,20,0};
  double Arg11[] = {50,30,0};
  double Arg12[] = {70,50,0};
  double Arg13[] = {-70,55,0};
  double Arg14[] = {-80,65,0};
  Vector3d Polozenie4(Arg8);
  Vector3d Polozenie5(Arg9);
  Vector3d Polozenie6(Arg10);
  Vector3d Polozenie7(Arg11);
  Vector3d Polozenie8(Arg12);
  Vector3d Polozenie9(Arg13);
  Vector3d Polozenie10(Arg14);

  probka_regolitu P1("../bryly_wzorcowe/szescian2.dat","P1",Kolor_Czerwony,Skala4,Polozenie4);
  
  probka_regolitu P2("../bryly_wzorcowe/szescian2.dat","P2",Kolor_Czerwony,Skala4,Polozenie5);

  probka_regolitu P3("../bryly_wzorcowe/szescian2.dat","P3",Kolor_Czerwony,Skala4,Polozenie6);

  probka_regolitu P4("../bryly_wzorcowe/szescian2.dat","P4",Kolor_Czerwony,Skala4,Polozenie7);

  probka_regolitu P5("../bryly_wzorcowe/szescian2.dat","P5",Kolor_Czerwony,Skala4,Polozenie8);

  probka_regolitu P6("../bryly_wzorcowe/szescian2.dat","P6",Kolor_Czerwony,Skala4,Polozenie9);

  probka_regolitu P7("../bryly_wzorcowe/szescian2.dat","P7",Kolor_Czerwony,Skala4,Polozenie10);
  
  Lazik L1("../bryly_wzorcowe/szescian3.dat","FSR",Kolor_JasnoNiebieski,Skala1,Polozenie1);
  Lazik L2("../bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony,Skala2,Polozenie2);
  Lazik L3("../bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony,Skala3,Polozenie3); 

  DodajDoListyRysowania(Lacze,L1);
  DodajDoListyRysowania(Lacze,L2);
  DodajDoListyRysowania(Lacze,L3);

  DodajDoListyRysowania(Lacze,P1);
  DodajDoListyRysowania(Lacze,P2);
  DodajDoListyRysowania(Lacze,P3);
  DodajDoListyRysowania(Lacze,P4);
  DodajDoListyRysowania(Lacze,P5);
  DodajDoListyRysowania(Lacze,P6);
  DodajDoListyRysowania(Lacze,P7);  

  P1.Przelicz_i_Zapisz_Wierzcholki();
  P2.Przelicz_i_Zapisz_Wierzcholki();
  P3.Przelicz_i_Zapisz_Wierzcholki();
  P4.Przelicz_i_Zapisz_Wierzcholki();
  P5.Przelicz_i_Zapisz_Wierzcholki();
  P6.Przelicz_i_Zapisz_Wierzcholki();
  P7.Przelicz_i_Zapisz_Wierzcholki();


  std::shared_ptr<probka_regolitu> _P1;
  std::shared_ptr<probka_regolitu> _P2;
  std::shared_ptr<probka_regolitu> _P3; 
  std::shared_ptr<probka_regolitu> _P4;
  std::shared_ptr<probka_regolitu> _P5;
  std::shared_ptr<probka_regolitu> _P6; 
  std::shared_ptr<probka_regolitu> _P7;

  _P1 = std::make_shared<probka_regolitu>(P1);
  _P2 = std::make_shared<probka_regolitu>(P2);
  _P3 = std::make_shared<probka_regolitu>(P3);
  _P4 = std::make_shared<probka_regolitu>(P4);
  _P5 = std::make_shared<probka_regolitu>(P5);
  _P6 = std::make_shared<probka_regolitu>(P6);
  _P7 = std::make_shared<probka_regolitu>(P7);

   lista_probek.push_back(_P1);
   lista_probek.push_back(_P2);
   lista_probek.push_back(_P3);
   lista_probek.push_back(_P4);
   lista_probek.push_back(_P5);
   lista_probek.push_back(_P6);
   lista_probek.push_back(_P7);


  L1.Przelicz_i_Zapisz_Wierzcholki();
  L2.Przelicz_i_Zapisz_Wierzcholki();
  L3.Przelicz_i_Zapisz_Wierzcholki();

  std::shared_ptr<Lazik> obiekt1;
  std::shared_ptr<Lazik> obiekt2;
  std::shared_ptr<Lazik> obiekt3; 

  obiekt1 = std::make_shared<Lazik>(L1);
  obiekt2 = std::make_shared<Lazik>(L2);  
  obiekt3 = std::make_shared<Lazik>(L3);

  lista_lazikow.push_back(obiekt1);
  lista_lazikow.push_back(obiekt2);
  lista_lazikow.push_back(obiekt3);
    

}

