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

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
# define EPSILON 1e-6
# define ZERO 0e-6

using namespace std;

class rational_t {
  // pautas de estilos [44] y [73]: primero "public" y después "private"
public:
  /**
   * @brief Este es el constructor de nuestra clase "rational_t" (en este caso, por defecto tiene unos valores)
   * @param numero_entero
   * @param numero_entero
   */
  rational_t(const int = 0, const int = 1);

  /**
   * @brief Este es el destructor de nuestra clase "rational_t"
   */
  ~rational_t() {}
  
  // pauta de estilo [71]: indentación a 2 espacios
  
  // Getters
  /**
   * @brief Obtiene el denominador de nuestro numero racional
   * @return numero_entero que se encuentra almacenado en den_
   */
  int get_num() const;


  /**
   * @brief Obtiene el denominador de nuestro numero racional
   * @return numero_entero que se encuentra almacenado en den_
   */
  int get_den() const;
  
  // Setters

  /**
   * @brief Establece un valor (nuevo) en el numerador
   * @param numero_entero Será el nuevo valor
   */
  void set_num(const int);

  /**
   * @brief Establece un valor (nuevo) en el denominador
   * @param numero_entero Será el nuevo valor
   */
  void set_den(const int);

  /**
   * @brief Encargado de obtener el resultado de nuestro número racional
   * @return el valor tras realizar la división
   */
  double value(void) const;

  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  // FASE II
  /**
   * @brief Encargada de verificar si el valor absoluto de la resta de 2 valores |a - b|
   *        es menor que un número dado
   * @param variable de tipo rational_t, será el otro operando a usar
   * @param EPSILON contiene el número 1e-6
   * @return true o false, dependiendo del resultado de la verificación previamente hecha
   */
  bool is_equal(const rational_t&, const double precision = EPSILON) const;


  /**
   * @brief Encargada de verificar si el resultado de la resta de 2 valores a - b
   *        es mayor que un número dado
   * @param variable de tipo rational_t, será el otro operando a usar
   * @param EPSILON contiene el número 1e-6
   * @return true o false, dependiendo del resultado de la verificación previamente hecha
   */
  bool is_greater(const rational_t&, const double precision = EPSILON) const;


  /**
   * @brief Encargada de verificar si el resultado de la resta de 2 valores b - a
   *        es mayor que un número dado
   * @param variable de tipo rational_t, será el otro operando a usar
   * @param EPSILON contiene el número 1e-6
   * @return true o false, dependiendo del resultado de la verificación previamente hecha
   */
  bool is_less(const rational_t&, const double precision = EPSILON) const;


  /**
   * @brief Encargada de verificar si el numero racional es igual a 0
   * @param EPSILON contiene el número 1e-6
   * @return true o false, dependiendo del resultado de la verificación previamente hecha
   */
  bool is_zero(const double precision = ZERO) const;
  
  // FASE III
  /**
   * @brief Encargada de sumar una variable tipo rational_t con el parámetro pasado como argumento
   * @param variable de tipo rational_t, sera el otro operando a usar
   * @return número tipo rational_t
   */
  rational_t add(const rational_t&) const;
  
  
  /**
   * @brief Encargada de restar una variable tipo rational_t con el parámetro pasado como argumento
   * @param variable de tipo rational_t, sera el otro operando a usar
   * @return número tipo rational_t
   */  
  rational_t substract(const rational_t&) const;
  
 
  /**
   * @brief Encargada de multiplicar una variable tipo rational_t con el parámetro pasado como argumento
   * @param variable de tipo rational_t, sera el otro operando a usar
   * @return número tipo rational_t
   */  
  rational_t multiply(const rational_t&) const;
  

  /**
   * @brief Encargada de dividir una variable tipo rational_t con el parámetro pasado como argumento
   * @param variable de tipo rational_t, sera el otro operando a usar
   * @return número tipo rational_t
   */
  rational_t divide(const rational_t&) const;


  /**
   * @brief Encargada de mostrar por pantalla con un formato legible la variable de tipo rational_t
   * @param cout - tipo ostream
   */
  void write(ostream& = cout) const;
  
  
  /**
   * @brief Encarga de pedir al usuario los valores de los atributos de la variable de tipo rational_t
   * @param cin - tipo istream
   */
  void read(istream& = cin);
  
private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);