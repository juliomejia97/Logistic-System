#ifndef __NODO__H__
#define __NODO__H__

#include <iostream>
#include <list>

template< class T >
class Nodo {
  public:
    //definicion mas corta del tipo
    typedef std::list< Nodo<T>* > TList;
  
  public:
    //constructores
    Nodo();
    Nodo(const T& val);
    //destructor
    ~Nodo();
    //manipuladores dato
    T& obtenerDato();
    void fijarDato(T& val);
    //manipuladores lista descendientes
    TList& obtenerDesc();
    void fijarDesc(TList& listaDesc);
    //modificadores lista descendientes
    void adicionarDesc(T& nval);
    bool eliminarDesc(T& val);
    Nodo<T>* buscarDesc(T& val);
    void limpiarLista();
    unsigned int numDesc();
    //operaciones para arbol
    bool insertarNodo(T& padre, T& n);
    bool eliminarNodo(T& n);
    Nodo<T>* buscarNodo(string val);
	list<T*> toList();
    int altura();
    unsigned int tamano();
    list<T> preOrden();
    void posOrden();
    void inOrden();
    void nivelOrden();
  
  protected:
    T dato;
    TList desc;
};

#include "Nodo.hxx"

#endif // __NODO__H__

// eof - Nodo.h

