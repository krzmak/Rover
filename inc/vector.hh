#pragma once

#include <iostream>


template <typename TYP, int ROZMIAR>
class Vector {

private:

    TYP size[ROZMIAR];     //Tablica wektora

    int maksymalna_ilosc_wektorow = 0;

    int ile_stworzono_wektorow = 0;

public:

    void wyswietl_stan_wektorow()
    {
        std::cout<<"ilość maksymalna wektorow"<< maksymalna_ilosc_wektorow << std::endl;
        std::cout<<"ile stworzono wektorow"<< ile_stworzono_wektorow << std::endl;
    };

    Vector<TYP,ROZMIAR>();

    ~Vector<TYP,ROZMIAR>(){maksymalna_ilosc_wektorow -= 1;};

    Vector<TYP,ROZMIAR>(TYP [ROZMIAR]);

    Vector<TYP,ROZMIAR> operator + (const Vector<TYP,ROZMIAR> &v);

    Vector<TYP,ROZMIAR> operator - (const Vector<TYP,ROZMIAR> &v);

    Vector<TYP,ROZMIAR> operator * (const double &tmp);

    Vector<TYP,ROZMIAR> operator / (const double &tmp);

    const TYP &operator [] (int index) const;

    TYP &operator [] (int index);
};

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <typename TYP, int ROZMIAR>
std::ostream &operator << (std::ostream &out, Vector<TYP,ROZMIAR> const &tmp) {
    for (int i = 0; i < ROZMIAR; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <typename TYP, int ROZMIAR>
std::istream &operator >> (std::istream &in, Vector<TYP,ROZMIAR> &tmp) {
    for (int i = 0; i < ROZMIAR; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

typedef Vector<double,3> Vector3d;
typedef Vector<double,2> Vector2d;