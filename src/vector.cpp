#include "vector.hh"

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR>::Vector() {
    for (int i = 0; i < ROZMIAR; ++i) {
        size[i] = 0;
    }
    maksymalna_ilosc_wektorow += 1;
    ile_stworzono_wektorow +=1;
}



/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR>::Vector(TYP tmp[ROZMIAR]) {
    for (int i = 0; i < ROZMIAR; ++i) {
        size[i] = tmp[i];
    }
    maksymalna_ilosc_wektorow += 1;
    ile_stworzono_wektorow +=1;
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR> Vector<TYP,ROZMIAR>::operator + (const Vector<TYP,ROZMIAR> &v) {
    Vector<TYP,ROZMIAR> result;
    for (int i = 0; i < ROZMIAR; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR> Vector<TYP,ROZMIAR>::operator - (const Vector<TYP,ROZMIAR> &v) {
    Vector<TYP,ROZMIAR> result;
    for (int i = 0; i < ROZMIAR; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR> Vector<TYP,ROZMIAR>::operator * (const double &tmp) {
    Vector<TYP,ROZMIAR> result;
    for (int i = 0; i < ROZMIAR; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR> Vector<TYP,ROZMIAR>::operator / (const double &tmp) {
    Vector<TYP,ROZMIAR> result;

    for (int i = 0; i < ROZMIAR; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <typename TYP, int ROZMIAR>
const TYP &Vector<TYP,ROZMIAR>::operator [] (int index) const {
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <typename TYP, int ROZMIAR>
TYP &Vector<TYP,ROZMIAR>::operator[](int index) {
    return const_cast<TYP &>(const_cast<const Vector<TYP,ROZMIAR> *>(this)->operator[](index));
}

template class Vector<double, 3>;
template class Vector<double, 2>;

