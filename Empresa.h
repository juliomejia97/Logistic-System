#ifndef __EMPRESA_H__
#define __EMPRESA_H__
#include "Oficina.h"
#include "Persona.h"
#include "Graph.h"
#include "Arbol.h"
#include "Nodo.h"
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

class Empresa{
	public:
		Empresa(string nombre);
		string getNombre();
		list<Persona> getDirectorio();
		Graph<Oficina,double> getOficinas();
		void setNombre(string nombre);
		void setDirectorio(list<Persona> directorio);
		void setOficinas(Graph<Oficina,double> oficinas);

		Oficina stringToOficina(string line);
		int cargarPersonas(string archivo);
		bool existenciaPersona(string);
		bool existenciaPaquete(string);
		int registrarPersona( string nombres,string apellidos,string iD,string direccion,string ciudad,string telefono,string idR);
		int registrarPaquete(double peso,string tipoContenido,string numGuia,string cedulaR,string cedulaD);
		Persona buscarPersona(string id);
		Oficina *buscarOficina(string id);
		Oficina* buscarOficinaRegion(string idRegion);
		int cargarPaquete(string archivo);
		void conteoPaquetes();
		void listarPersonas();
		bool existeOficina(string id);
		int crearOficina(string id,string nombre,string direcion,string ciudad);
		int cargarOficina(string archivo);
  	int cargarRegion(string archivo);
	int cargarConexion(string archivo);
	int crearConexion(string id0,string id1,double dist);
    int crearRegion(string id_O,string id,string nombre);
  	int registrarOficina(string id,string nombre,string direccion,string ciudad);
		int registrarRegion(string id_O,string id,string nombre);
		void mostrarOficinas();
		void repartirPaquetes();
		list<string> camino(string id0,string id1);
	private:
		string nombre;
		list<Persona> directorio;
		Graph<Oficina,double> oficinas;
		int x;
};

#include "Empresa.hxx"
#endif