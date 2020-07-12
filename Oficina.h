#ifndef __OFICINA_H__
#define __OFICINA_H__

#include "Region.h"
#include "Paquete.h"

#include <string.h>
#include <list>

using namespace std;
class Oficina
{
  private:
  string iD;
  string nombre;
  string direccion;
  string ciudad;
  list<Region> regionesR;
  list<Paquete> paquetes;
  public:

  Oficina(string iD,string nombre,string direccion,string ciudad);
  Oficina();
  void setId(string pId);
  void addPaquete(Paquete p);
  string getId();
  void setNombre(string pNombre);
  string getNombre();
  void setDireccion(string pDireccion);
  string getDireccion();
  void setCiudad(string pCiudad);
  string getCiudad();
  void setRegiones(list<Region> pRegiones);
  list<Region> getRegiones();
  list<Paquete> getPaquetes();
  void setPaquetes(list<Paquete> pPaquetes);
  bool existenciaRegion(string iD_R);
  bool existenciaPaquete(string iD_P);
  void agregarPaquete(Paquete p);
  Region *buscarRegion(string id, string nombre);
  int crearRegion(string nombre, string iD);
  bool existeRegion(string id);
  bool eliminarPaquete(string guia);
  bool operator==(const Oficina& a){
  	return this->iD==a.iD;
  }
};

#include "Oficina.hxx"
#endif
