#include "Arbol.h"

// ------------------------------------------------------------------------
template< class T >
Arbol<T>::Arbol() 
{
raiz=NULL;
}

// ------------------------------------------------------------------------
template< class T >
Arbol<T>::Arbol(const T& val) {
  Nodo<T> *nnodo = new Nodo<T>(val);
  this->raiz = nnodo;
}

// ------------------------------------------------------------------------
template< class T >
Arbol<T>::~Arbol() {
  if (this->raiz != NULL)
    delete this->raiz;
}

// ------------------------------------------------------------------------
template< class T >
bool Arbol<T>::esVacio() {
  if (this->raiz == NULL)
    return true;
  else
    return false;
}

// ------------------------------------------------------------------------
template< class T >
Nodo<T>* Arbol<T>::obtenerRaiz() {
  return this->raiz;
}

// ------------------------------------------------------------------------
template< class T >
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz) {
  this->raiz = nraiz;
}

// ------------------------------------------------------------------------
template< class T >
bool Arbol<T>::insertarNodo(T& padre, T& n) {
  bool ins = false;
  if (!this->esVacio()) {
    ins = this->raiz->insertarNodo(padre,n);
  }
  return ins;
}

// ------------------------------------------------------------------------
template< class T >
bool Arbol<T>::eliminarNodo(T& n) {
  bool ins = false;
  if(!this->esVacio())
  {
    ins = this->raiz->eliminarNodo(n);
  }
  return ins;
}

// ------------------------------------------------------------------------
template< class T >
Nodo<T>* Arbol<T>::buscarNodo(string id) {
  Nodo<T> *devolver;
  if (!this->esVacio())
  {
    devolver = this->raiz->buscarNodo(id);
  }
  return devolver;

}

// ------------------------------------------------------------------------
template< class T >
int Arbol<T>::altura() {
  int altura = 0;
  if (!this->esVacio())
  {
    altura = this->raiz->altura();
  }
  return altura;
}

// ------------------------------------------------------------------------
template< class T >
unsigned int Arbol<T>::tamano() {
  int tamano = 0;
  if (!this->esVacio())
  {
    tamano = this->raiz->tamano();
  }
  return tamano;

}

// ------------------------------------------------------------------------
template< class T >
list<T> Arbol<T>::preOrden() {
  if (!this->esVacio()) {
    return this->raiz->preOrden();
  }
	
}

// ------------------------------------------------------------------------
template< class T >
void Arbol<T>::posOrden() {
  if (!this->esVacio()) {
    this->raiz->posOrden();
    std::cout << std::endl;
  }
}

// ------------------------------------------------------------------------
template< class T >
void Arbol<T>::inOrden() {
     if (!this->esVacio()) {
    this->raiz->inOrden();
    std::cout << std::endl;
  }
}

// ------------------------------------------------------------------------
template< class T >
void Arbol<T>::nivelOrden() {
  if (!this->esVacio()) {
    std::cout<<this->raiz->obtenerDato()<<"\t";
    this->raiz->nivelOrden();
    std::cout << std::endl;
  }
}

template<class T>
list<T*> Arbol<T>::toList(){
	return this->raiz->toList();
}

// eof - Arbol.hxx
