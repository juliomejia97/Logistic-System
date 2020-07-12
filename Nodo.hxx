#include "Nodo.h"
#include <queue>
using namespace std;

// ------------------------------------------------------------------------
template< class T >
Nodo<T>::Nodo() {
  this->desc.clear();
}

// ------------------------------------------------------------------------
template< class T >
Nodo<T>::Nodo(const T& val) {
  this->dato = val;
  this->desc.clear();
}

// ------------------------------------------------------------------------
template< class T >
Nodo<T>::~Nodo() {
  typename TList::iterator it;
  for (it = this->desc.begin(); it != this->desc.end(); it++)
    delete *it;
  this->desc.clear();
}

// ------------------------------------------------------------------------
template< class T >
T& Nodo<T>::obtenerDato() {
  return this->dato;
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::fijarDato(T& val) {
  this->dato = val;
}

// ------------------------------------------------------------------------
template< class T >
typename Nodo<T>::TList& Nodo<T>::obtenerDesc() {
  return this->desc;
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::fijarDesc(TList& listaDesc) {
  this->desc = listaDesc;
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::adicionarDesc(T& nval) {
  Nodo<T> *nnodo = new Nodo<T>;
  nnodo->dato = nval;
  this->desc.push_back(nnodo);
}

// ------------------------------------------------------------------------
template< class T >
bool Nodo<T>::eliminarDesc(T& val){
  bool encontro = false;
  Nodo<T> *p_it;
  TList info = obtenerDesc();
  typename TList::iterator it;

  for (it = this->desc.begin(); it != this->desc.end(); it++) {
    p_it = *it;
    if (p_it->obtenerDato() == val){
      encontro = true;
      break;
      }
  }
  if(encontro = true)
  info.erase(it);

  return encontro;

}

// ------------------------------------------------------------------------
template< class T >
Nodo<T>* Nodo<T>::buscarDesc(T& val) {
  Nodo<T> *p_it;
  typename TList::iterator it;

  for (it = this->desc.begin(); it != this->desc.end(); it++) {
    p_it = *it;
    if (p_it->obtenerDato() == val)
      break;
  }
  return p_it;
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::limpiarLista() {
 this->desc.clear();
}

// ------------------------------------------------------------------------
template< class T >
unsigned int Nodo<T>::numDesc() {
	return this->desc.size();

}

// ------------------------------------------------------------------------
template< class T >
bool Nodo<T>::insertarNodo(T& padre, T& n) {
  bool encontro = 0;
  if(this->obtenerDato().getId()!= padre.getId())
  {
    if(this->numDesc()!=0)
    {
      for(typename TList::iterator it = this->desc.begin(); it != this->desc.end(); it++)
      {
        encontro = (*it)->insertarNodo(padre, n);
      }
      return encontro;
    }else
    {
      return encontro;
    }
  }else
  {
    encontro = 1;
    this->adicionarDesc(n);
    return encontro;
  }

}

// ------------------------------------------------------------------------
//pista: recursividad
template< class T >
bool Nodo<T>::eliminarNodo(T& n) {
  bool encontro =  false;
  if(this->numDesc()!=0)
  {
    for(typename TList::iterator it=this->desc.begin(); it!=this->desc.end();it++)
    {
      Nodo<T>* aux = *it;
      if((*it)->obtenerDato()!=n)
      {
        encontro = (*it)->eliminarNodo(n);
      }
      else
      {
        encontro = true;
        if(aux->numDesc()!=0)
        {
          for(typename TList::iterator i = aux->desc.begin(); i!=aux->desc.end();i++)
          {
            this->adicionarDesc((*i)->obtenerDato());
          }
        }
        it = this->desc.erase(it);
        delete aux;
      }
    }
    return encontro;
  }
  else{
    return encontro;
  }
}
// ------------------------------------------------------------------------
template< class T >
Nodo<T>* Nodo<T>::buscarNodo(string id) {
  Nodo<T> *devolver = NULL;
  if(this->obtenerDato().getId()==id)
  {
    devolver = this;
    return devolver;
  }
  if(this->numDesc()!= 0)
  {
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      devolver = (*it)->buscarNodo(id);
	  if(devolver!=NULL){
	  	return devolver;
	  }
    }
  }
  return NULL;

}

// ------------------------------------------------------------------------
template< class T >
int Nodo<T>::altura() {
  if(this->numDesc()!=0)
  {
    int max = -1;
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      int aux = (*it)->altura();
      if(aux>max)
      {
        max = aux;
      }
    }
    return max+1;
  }else{
    return 0;
  }


}

// ------------------------------------------------------------------------
template< class T >
unsigned int Nodo<T>::tamano() {
  if(this->numDesc()!=0)
  {
    int max=0;
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      int aux = (*it)->tamano();
      if(aux>max)
      {
        max=aux;
      }
    }
    return max + this->numDesc();
  }else{
    return 0;
  }
}

// ------------------------------------------------------------------------
template< class T >
list<T> Nodo<T>::preOrden() {
	list<T> L=list<T>();
  L.push_back(this->dato);
  if (this->numDesc() != 0) {
    typename TList::iterator it;
    for (it = desc.begin(); it != desc.end(); it++) {
      L.splice(L.end(),(*it)->preOrden());
    }
  }
  return L;
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::posOrden() {
  if(this->numDesc()!=0)
  {
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      (*it)->posOrden();
    }
  }
    std::cout << this->dato.getId() << "\t";
}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::inOrden() {

    if(this->numDesc()!=0)
  {
       int i=0;
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      (*it)->inOrden(); 
        /*if(i==0){std::cout << this->dato << "\t";}
        i++;*/
    }
  }else
    {
    std::cout << this->dato << "\t";
    }

    return;


}

// ------------------------------------------------------------------------
template< class T >
void Nodo<T>::nivelOrden() {

  if(this->numDesc()!=0)
  {
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {
      std::cout << (*it)->obtenerDato()<< "\t";

    }
    for(typename TList::iterator it = this->desc.begin(); it!= this->desc.end(); it++)
    {

      (*it)->nivelOrden();
    }
  }
}


template<class T>
list<T*> Nodo<T>::toList(){
	list<T*> L=list<T*>();
	L.push_back(&(this->dato));
	for(auto i=desc.begin();i!=desc.end();i++){
		L.splice(L.end(),(*i)->toList());
	}
	return L;
}
// eof - Nodo.hxx
