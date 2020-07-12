#ifndef __PERSONA_HXX__
#define __PERSONA_HXX__

#include "Persona.h"
#include <string.h>
#include <iostream>

using namespace std;
Persona::Persona()
{

}
Persona::Persona( string nombres,string apellidos,string iD,string direccion,string ciudad,string telefono, string idRegion)
{
  this->nombres = nombres;
  this->apellidos = apellidos;
  this->iD=iD;
  this->direccion = direccion;
  this->ciudad = ciudad;
  this->telefono = telefono;
  this->idRegion = idRegion;

}

void Persona::setNombres(string nombres)
{
  this->nombres = nombres;
}
string Persona::getNombres()
{
  return this->nombres;
}
void Persona::setApellidos(string apellidos)
{
  this->apellidos = apellidos;
}
string Persona::getApellidos()
{
  return this->apellidos;
}
void Persona::setiD(string iD)
{
  this->iD=iD;
}
string Persona::getiD()
{
  return this->iD;
}
void Persona::setDireccion(string direccion)
{
  this->direccion = direccion;
}
string Persona::getDireccion()
{
  return this->direccion;
}
void Persona::setCiudad(string ciudad)
{
  this->ciudad = ciudad;
}
string Persona::getCiudad()
{
  return this->ciudad;
}
void Persona::setTelefono(string telefono)
{
  this->telefono = telefono;
}
string Persona::getTelefono()
{
  return this->telefono;
}
void Persona::print(){
	cout<<"	 "<<this->nombres<<endl;
}
void Persona::setIdRegion(string idRegion)
{
	this->idRegion = idRegion;
}
string Persona::getIdRegion()
{
	return this->idRegion;
}


#endif //__PERSONA_HXX__
