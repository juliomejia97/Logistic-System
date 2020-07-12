#ifndef __REGION_HXX__
#define __REGION_HXX__

#include"Region.h"
#include"Paquete.h"

using namespace std;
Region::Region(string nombre, string iD)
{
  this->nombre = nombre;
  this->iD = iD;
}
Region::Region(){

}
void Region::setNombre(string nombre)
{
  this->nombre = nombre;
}
string Region::getNombre()
{
  return this->nombre;
}
void Region::setId(string iD)
{
  this->iD=iD;
}
string Region::getiD()
{
  return this->iD;
}
#endif
