#include "matrix.hh"

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template<typename TYP, int ROZMIAR>
Matrix<TYP,ROZMIAR>::Matrix() {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename TYP, int ROZMIAR>
Matrix<TYP,ROZMIAR>::Matrix(TYP tmp[ROZMIAR][ROZMIAR]) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template<typename TYP, int ROZMIAR>
Vector<TYP,ROZMIAR> Matrix<TYP,ROZMIAR>::operator * (Vector<TYP,ROZMIAR> tmp) {
    Vector<TYP,ROZMIAR> result;
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template<typename TYP, int ROZMIAR>
TYP &Matrix<TYP,ROZMIAR>::operator()(unsigned int row, unsigned int column) {

    if (row >= ROZMIAR) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= ROZMIAR) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template<typename TYP, int ROZMIAR>
const TYP &Matrix<TYP,ROZMIAR>::operator () (unsigned int row, unsigned int column) const {

    if (row >= ROZMIAR) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= ROZMIAR) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Przeciążenie dodawania macierzy                                           |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                    |
 |      v - wektor, czyli drugi skladnik dodawania.                           |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                            |
 */
template<typename TYP, int ROZMIAR>
Matrix<TYP,ROZMIAR> Matrix<TYP,ROZMIAR>::operator + (Matrix<TYP,ROZMIAR> tmp) {
    Matrix<TYP,ROZMIAR> result;
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                        |
 */
template<typename TYP, int ROZMIAR>
std::istream &operator>>(std::istream &in, Matrix<TYP,ROZMIAR> &mat) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template<typename TYP, int ROZMIAR>
std::ostream &operator<<(std::ostream &out, const Matrix<TYP,ROZMIAR> &mat) {
    for (int i = 0; i < ROZMIAR; ++i) {
        for (int j = 0; j < ROZMIAR; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/******************************************************************************
 |  Funkcja pomocnicza do wyznaczenia macierzy gaussa                         |
 |                                                                            |
 | Tworzy macierz trojkatna by wyliczyc wyznacznik                            |
 |  Zwraca:                                                                   |
 |     Wyznacznik danej macierzy                                              |
 */
template<typename TYP, int ROZMIAR>
double Matrix<TYP,ROZMIAR>::EliminacjaGaussa_ObliczWyznacznik()
{   
    double wyznacznik = 1;
    int i,j,k,n,l;
    n = ROZMIAR; 
    double tmp;
    double tmp2;
    bool czy_nie_udalo_sie_zamienic_wierszy = false;

    for(i=0; i<n; ++i)
	{
        if(value[i][i]==0) //procedura zamiany wierszow
        {
           czy_nie_udalo_sie_zamienic_wierszy = true;
           for(j=i;j<n;++j)
           {
            if(value[j][i]!=0) //czy to na co zamieniamy nie zawiera zera na i-tej pozycji
            {
            wyznacznik *= -1; //zamieniamy kolumny wiec "zmienniamy parzystosc" czyli mnozymy wyznacznik przez -1
            for(k=0;k<n;++k)
             {
               tmp = value[i][k]; //zamieniamy dwie wiersze ze soba
               value[i][k] = value[j][k];
               value[j][k] = tmp;
               czy_nie_udalo_sie_zamienic_wierszy = false; //zmieniamy bo wyznacznik nie bedzie zerem
             }
            }
           }
        }
        if(czy_nie_udalo_sie_zamienic_wierszy==true) //wyznacznik jest zerem bo nie znalezlismy odpowiedniej zamiany
        {
            wyznacznik = 0;
            return wyznacznik;
        }

        else
        {
		for(j=i+1; j<n; ++j)//doprowadzenie do macierzy trojkatnej
	    	{
			tmp2=value[j][i];
			for(l=i; l<n; ++l)
				value[j][l] -= (value[i][l]*tmp2)/value[i][i];
		    }
            wyznacznik *= value[i][i];
	    }
    }
 return wyznacznik;
}


/******************************************************************************
 |  Funkcja do wyznaczenia wyznacznika macierzy                               |
 |                                                                            |
 |  Funkcja wyzncza wyznacznik macierzy nie zmieniajac je zawartosci          |
 |  Zwraca:                                                                   |
 |     Wyznacznik danej macierzy                                              |
 */
template<typename TYP, int ROZMIAR>
double Matrix<TYP,ROZMIAR>::ObliczWyznacznik() const
{
    Matrix Mattmp = *this;
    return Mattmp.EliminacjaGaussa_ObliczWyznacznik();

}

/******************************************************************************
 |  Zamiana wybranej kolumny w macierzy                                       |
 |  Argumenty:                                                                |
 |      &M - wskaznik macierz ktorej kolumna bedzie zamienianna               |
 |      tmp - wektor ktory jest kolumna na ktora chcemy zamienic.             |
 |      column_to_swap - indeks kolumny ktora chcemy zamienic zaczynajac od 0 |
 |  Zwraca:                                                                   |
 |      Macierz po zamianie wybranej kolumny.                                 |
 */
template<typename TYP, int ROZMIAR>
Matrix<TYP,ROZMIAR> Matrix<TYP,ROZMIAR>::swap(int colum_to_swap, Vector<TYP,ROZMIAR> tmp, Matrix<TYP,ROZMIAR> &M)
{ 
        for (int i = 0; i < ROZMIAR; i++) 
        {
            M(i,colum_to_swap) = tmp[i];
        }   
    return M;
}

template class Matrix<double, 3>;