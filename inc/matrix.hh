#pragma once

#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include<iomanip>

template<typename TYP, int ROZMIAR>
class Matrix {
private:
    TYP value[ROZMIAR][ROZMIAR];               // Wartosci macierzy
    double EliminacjaGaussa_ObliczWyznacznik();
public:
    Matrix<TYP,ROZMIAR>(TYP [ROZMIAR][ROZMIAR]);            // Konstruktor klasy

    Matrix<TYP,ROZMIAR>();                               // Konstruktor klasy

    Vector<TYP,ROZMIAR> operator * (Vector<TYP,ROZMIAR> tmp);           // Operator mnożenia przez wektor

    Matrix<TYP,ROZMIAR> operator + (Matrix<TYP,ROZMIAR> tmp);

    TYP  &operator () (unsigned int row, unsigned int column);
    
    const TYP &operator () (unsigned int row, unsigned int column) const;

    double ObliczWyznacznik() const;

    Matrix swap(int colum_to_swap, Vector<TYP,ROZMIAR> tmp,Matrix<TYP,ROZMIAR> &M);
};

template<typename TYP, int ROZMIAR>
std::istream &operator>>(std::istream &in, Matrix<TYP,ROZMIAR> &mat);

template<typename TYP, int ROZMIAR>
std::ostream &operator<<(std::ostream &out, Matrix<TYP,ROZMIAR> const &mat);



