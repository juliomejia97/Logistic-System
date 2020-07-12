#ifndef __REGION_H__
#define __REGION_H__

#include <list>
#include <string.h>
using namespace std;
class Region
{
  private:
    string nombre;
    string iD;
  public:
    Region(string nombre, string iD);
    Region();
    void setNombre(string nombre);
    string getNombre();
    void setId(string iD);
    string getiD();
};

#include "Region.hxx"
#endif
