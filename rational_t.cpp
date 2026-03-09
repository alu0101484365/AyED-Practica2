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

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
/**
 * @brief Obtiene el numerador de nuestro numero racional
 */
inline int rational_t::get_num() const {
  return num_;
}


/**
 * @brief Obtiene el denominador de nuestro numero racional
 */
inline int rational_t::get_den() const {
  return den_;
}


/**
 * @brief Establece un valor (nuevo) en el numerador
 */
void rational_t::set_num(const int n) {
  num_ = n;
}


/**
 * @brief Establece un valor (nuevo) en el denominador
 */ 
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}


/**
 * @brief Encargado de obtener el resultado de nuestro número racional
 */
inline double rational_t::value() const { 
  return double(get_num()) / get_den();
}


/**
 * @brief Devuelve el opuesto del número racional.
 */
rational_t  rational_t::opposite() const { 
  return rational_t((-1)*get_num(), get_den());
}


/**
 * @brief Devuelve el recíproco del número racional.
 */
rational_t rational_t::reciprocal() const { 
  return rational_t(get_den(), get_num());
}



// comparaciones
/**
 * @brief Encargada de verificar si el valor absoluto de la resta de 2 valores |a - b| 
 *        es menor que un número dado
 */
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}


/**
 * @brief Encargada de verificar si el resultado de la resta de 2 valores a - b
 *        es mayor que un número dado
 */
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}


/**
 * @brief Encargada de verificar si el resultado de la resta de 2 valores b - a
 *        es mayor que un número dado
 */
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}


// operaciones
/**
 * @brief Encargada de sumar una variable tipo rational_t con el parámetro pasado como argumento
 */
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}


/**
 * @brief Encargada de restar una variable tipo rational_t con el parámetro pasado como argumento
 */
rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}


/**
 * @brief Encargada de multiplicar una variable tipo rational_t con el parámetro pasado como argumento
 */
rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}


/**
 * @brief Encargada de dividir una variable tipo rational_t con el parámetro pasado como argumento
 */
rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}


// FASE I: operadores
/**
 * @brief Operador suma entre dos números racionales.
 */
rational_t operator+(const rational_t& a, const rational_t& b) {
  return a.add(b);
}


/**
 * @brief Operador resta entre dos números racionales.
 */
rational_t operator-(const rational_t& a, const rational_t& b) {
  return a.substract(b);
}


/**
 * @brief Operador multiplicación entre dos números racionales.
 */
rational_t operator*(const rational_t& a, const rational_t& b) {
  return a.multiply(b);
}


/**
 * @brief Operador división entre dos números racionales.
 */
rational_t operator/(const rational_t& a, const rational_t& b) {
  return a.divide(b);
}



// E/S
/**
 * @brief Encargada de mostrar por pantalla con un formato legible la variable de tipo rational_t
 */
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}


/**
 * @brief Encarga de pedir al usuario los valores de los atributos de la variable de tipo rational_t
 */
void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}



ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}


istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}