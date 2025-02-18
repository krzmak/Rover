#include "obrysxy.hh"
bool obrysxy::czy_nakladaja(obrysxy o2)
{
    if(W_gornylewy[0] > o2.W_dolnyprawy[0] || o2.W_gornylewy[0] > W_dolnyprawy[0])
    return false;

    if(W_dolnyprawy[1]>o2.W_gornylewy[1] || o2.W_dolnyprawy[1] > W_gornylewy[1])
    return false;
    
    return true;
    
}