#include "probka_regolitu.hh"

void probka_regolitu::Czykolizja(const std::shared_ptr<ObiektGeom>& Wsk_lazik)
{
    if(Obrys.czy_nakladaja(Wsk_lazik -> Obrys) == true)
     std::cout<<"najechano probke regolitu"<<std::endl;
}

std::ostream &operator << (std::ostream &out, probka_regolitu &tmp) {
        out << "[ " << tmp.get_nazwa() << " ]\n";
    return out;
}
