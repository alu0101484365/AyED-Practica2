/**
 * AUTOR: Raúl Navarro Cobos
 * FECHA: 03/03/2026
 * EMAIL: alu0101484365@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRACTICA: 2
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
 *              "C++ Programming Style Guidelines"
 *              https://geosoft.no/development/cppstyle.html
 * COMPILACION: g++ -g rational_t.cpp main_p2.cpp -o main_p2
 */
#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

/**
 * @brief Clase plantilla que implementa una matriz.
 * @tparam T Tipo de dato de los elementos.
 */
template<class T>
class matrix_t {
  public:

    /**
     * @brief Constructor de la matriz.
     * @param m Número de filas.
     * @param n Número de columnas.
     */
    matrix_t(const int = 0, const int = 0);

    /**
     * @brief Destructor de la matriz.
     */
    ~matrix_t();
    
    /**
     * @brief Redimensiona la matriz.
     * @param m Número de filas.
     * @param n Número de columnas.
     */
    void resize(const int, const int);
    
    /**
     * @brief Obtiene el número de filas.
     * @return Número de filas.
     */
    int get_m(void) const;

    /**
     * @brief Obtiene el número de columnas.
     * @return Número de columnas.
     */
    int get_n(void) const;
    
    /**
     * @brief Accede a un elemento de la matriz.
     * @param i Fila.
     * @param j Columna.
     * @return Referencia al elemento.
     */
    T& at(const int, const int);

    /**
     * @brief Operador de acceso a la matriz.
     * @param i Fila.
     * @param j Columna.
     * @return Referencia al elemento.
     */
    T& operator()(const int, const int);
    
    /**
     * @brief Acceso constante a un elemento.
     * @param i Fila.
     * @param j Columna.
     * @return Referencia constante.
     */
    const T& at(const int, const int) const;

    /**
     * @brief Operador de acceso constante.
     * @param i Fila.
     * @param j Columna.
     * @return Referencia constante.
     */
    const T& operator()(const int, const int) const;
    
    /**
     * @brief Multiplica dos matrices.
     * @param A Primera matriz.
     * @param B Segunda matriz.
     */
    void multiply(const matrix_t<T>&, const matrix_t<T>&);

    /**
     * @brief Muestra la matriz por pantalla.
     * @param os Flujo de salida.
     */
    void write(ostream& = cout) const;

    /**
     * @brief Lee la matriz desde un flujo de entrada.
     * @param is Flujo de entrada.
     */
    void read(istream& = cin);

  private:

    int m_, n_;   /// Número de filas y columnas
    vector_t<T> v_; /// Vector que almacena los elementos
    
    /**
     * @brief Calcula la posición lineal del elemento (i,j).
     * @param i Fila.
     * @param j Columna.
     * @return Posición en el vector interno.
     */
    int pos(const int, const int) const;
};



/**
 * @brief Constructor de la matriz.
 */
template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



/**
 * @brief Destructor de la matriz.
 */
template<class T> matrix_t<T>::~matrix_t() {}



/**
 * @brief Redimensiona la matriz.
 */
template<class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



/**
 * @brief Devuelve el número de filas de la matriz.
 */
template<class T> inline int matrix_t<T>::get_m() const {
  return m_;
}



/**
 * @brief Devuelve el número de columnas de la matriz.
 */
template<class T> inline int matrix_t<T>::get_n() const {
  return n_;
}



/**
 * @brief Accede a un elemento de la matriz con comprobación de rango.
 */
template<class T> T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



/**
 * @brief Operador de acceso a un elemento de la matriz.
 */
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}



/**
 * @brief Accede de forma constante a un elemento de la matriz con comprobación de rango.
 */
template<class T> const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



/**
 * @brief Operador de acceso constante a un elemento de la matriz.
 */
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const { 
  return at(i, j);
}



/**
 * @brief Escribe la matriz en un flujo de salida.
 */
template<class T> void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



/**
 * @brief Lee las dimensiones y los elementos de la matriz desde un flujo de entrada.
 */
template<class T> void matrix_t<T>::read(istream& is) { 
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}



/**
 * @brief Calcula la posición lineal correspondiente a un elemento de la matriz.
 */
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}


// FASE III: producto matricial
/**
 * @brief Calcula el producto de dos matrices y almacena el resultado en la matriz actual.
 */
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for (int i = 1; i <= A.get_m(); i++) {
    for (int j = 1; j <= B.get_n(); ++j) {
      at(i,j) = T();
      for (int k = 1; k <= A.get_n(); k++) at(i,j) = at(i,j) + (A(i,k) * B(k,j));
    }
  }
}