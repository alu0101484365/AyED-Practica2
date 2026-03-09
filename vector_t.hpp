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

using namespace std;

/**
 * @brief Clase plantilla que implementa un vector dinámico.
 * @tparam T Tipo de dato almacenado en el vector.
 */
template<class T>
class vector_t {
  public:

    /**
     * @brief Constructor del vector.
     * @param n Tamaño inicial del vector.
     */
    vector_t(const int = 0);

    /**
     * @brief Destructor del vector.
     */
    ~vector_t();
    
    /**
     * @brief Cambia el tamaño del vector.
     * @param n Nuevo tamaño.
     */
    void resize(const int);
    
    /**
     * @brief Obtiene el valor de una posición del vector.
     * @param i Índice del elemento.
     * @return Valor almacenado en la posición i.
     */
    T get_val(const int) const;

    /**
     * @brief Obtiene el tamaño del vector.
     * @return Número de elementos del vector.
     */
    int get_size(void) const;
    
    /**
     * @brief Modifica el valor de una posición del vector.
     * @param i Índice del elemento.
     * @param d Nuevo valor.
     */
    void set_val(const int, const T);
    
    /**
     * @brief Acceso a un elemento del vector con comprobación.
     * @param i Índice del elemento.
     * @return Referencia al elemento.
     */
    T& at(const int);

    /**
     * @brief Operador de acceso al vector.
     * @param i Índice del elemento.
     * @return Referencia al elemento.
     */
    T& operator[](const int);
    
    /**
     * @brief Acceso constante a un elemento del vector.
     * @param i Índice del elemento.
     * @return Referencia constante al elemento.
     */
    const T& at(const int) const;

    /**
     * @brief Operador de acceso constante.
     * @param i Índice del elemento.
     * @return Referencia constante al elemento.
     */
    const T& operator[](const int) const;

    /**
     * @brief Muestra el vector por pantalla.
     * @param os Flujo de salida.
     */
    void write(ostream& = cout) const;

    /**
     * @brief Lee los valores del vector desde un flujo de entrada.
     * @param is Flujo de entrada.
     */
    void read(istream& = cin);

  private:
    T *v_;     /// Puntero al array de datos
    int sz_;   /// Tamaño del vector
    
    /**
     * @brief Reserva memoria para el vector.
     */
    void build(void);

    /**
     * @brief Libera la memoria del vector.
     */
    void destroy(void);
};


/**
 * @brief Constructor del vector.
 */
template<class T> vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}



/**
 * @brief Destructor del vector.
 */
template<class T> vector_t<T>::~vector_t() {
  destroy();
}



/**
 * @brief Reserva memoria para los elementos del vector.
 */
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}



/**
 * @brief Libera la memoria reservada por el vector.
 */
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}



/**
 * @brief Redimensiona el vector.
 */
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}



/**
 * @brief Devuelve el valor almacenado en una posición del vector.
 */
template<class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief Devuelve el tamaño del vector.
 */
template<class T> inline int vector_t<T>::get_size() const {
  return sz_;
}



/**
 * @brief Modifica el valor de una posición del vector.
 */
template<class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



/**
 * @brief Accede a un elemento del vector con comprobación de rango.
 */
template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief Operador de acceso a un elemento del vector.
 */
template<class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}



/**
 * @brief Accede de forma constante a un elemento del vector con comprobación de rango.
 */
template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief Operador de acceso constante a un elemento del vector.
 */
template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}



/**
 * @brief Escribe el contenido del vector en un flujo de salida.
 */
template<class T> void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}



/**
 * @brief Lee el tamaño y los elementos del vector desde un flujo de entrada.
 */
template<class T> void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i) is >> at(i);
}


// FASE II: producto escalar
/**
 * @brief Calcula el producto escalar de dos vectores.
 */
template<class T> T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  T result = T();
  assert(v.get_size() == w.get_size());
  for (int i{0}; i < v.get_size(); i++) result = result + (v.at(i) * w.at(i));
  return result;
}



/**
 * @brief Calcula el producto escalar de dos vectores de números racionales.
 */
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  double result{0.0};
  assert(v.get_size() == w.get_size());
  for (int i{0}; i < v.get_size(); i++) result = result + (v.at(i) * w.at(i)).value();
  return result;
}