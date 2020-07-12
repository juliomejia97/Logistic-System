#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "Nodo.h"

template <class T>
class Arbol {
  protected:
    Nodo<T>* raiz;
  
  public:
    //definicion mas corta del tipo
    typedef std::list< Nodo<T>* > TList;
  
  public:
    //constructores
    Arbol();
    Arbol(const T& val);
    //destructor
    ~Arbol();
    //verificador
    bool esVacio();
    //manipuladores raiz
    Nodo<T>* obtenerRaiz();
    void fijarRaiz(Nodo<T>* nraiz);
    //modificadores arbol
    bool insertarNodo(T& padre, T& n);
    bool eliminarNodo(T& n);
    Nodo<T>* buscarNodo(string id);
    int altura();
    unsigned int tamano();
    list<T> preOrden();
    void posOrden();
    void inOrden();
    void nivelOrden();
	list<T*> toList();
};

#include "Arbol.hxx"

#endif // __ARBOL__H__

// eof - Arbol.h

