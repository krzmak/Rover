#include "lazik_sfr.hh"

void lazik_sfr::Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik)
{
     if(Obrys.czy_nakladaja(Wsk_lazik -> Obrys) == true)
     {
     std::shared_ptr<probka_regolitu> Probka;
     Probka = std::static_pointer_cast<probka_regolitu>(Wsk_lazik);
     std::cout<<"Lazik zebral probke"<<std::endl;
     _lista_probek.push_back(Probka);
       std::cout<<"lista probek:"<<std::endl;
    for(auto const &i: _lista_probek)
     {
    std::cout<< *i <<std::endl;
     }
     }   
}