#include "vektor2d.hh"
#include "vector.hh"


class obrysxy
{
public:
    Vector2d W_dolnylewy;
    Vector2d W_gornyprawy;
    Vector2d W_dolnyprawy;
    Vector2d W_gornylewy;
    bool czy_nakladaja(obrysxy o2);
};

