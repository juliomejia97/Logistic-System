#include <iostream>
#include <string.h>
#include "Arbol.h"
#include "Nodo.h"
#include <list>
using namespace std;


int main(){
	Arbol<int> a=Arbol<int>();
	a.fijarRaiz(new Nodo<int>(0));
	a.insertarNodo(0,1);
	a.insertarNodo(0,2);
	a.insertarNodo(0,3);
	a.insertarNodo(2,4);
	list<int> L=a.preOrden();
	for(auto i=L.begin();i!=end();i++){
		cout<<(*i)<<endl;
	}
}


