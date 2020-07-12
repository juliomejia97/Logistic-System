#ifndef __PERSONA_H__
#define __PERSONA_H__



#include <string.h>
#include <string>

using namespace std;

class Persona
{
  private:
    string nombres;
    string apellidos;
    string iD;
    string direccion;
    string ciudad;
    string telefono;
	string idRegion;
  public:
    Persona( string nombres,string apellidos,string iD,string direccion,string ciudad,string telefono, string idRegion);
    Persona();
    void setNombres(string nombres);
    string getNombres();
    void setApellidos(string apellidos);
    string getApellidos();
    void setiD(string iD);
    string getiD();
    void setDireccion(string direccion);
    string getDireccion();
    void setCiudad(string ciudad);
    string getCiudad();
    void setTelefono(string telefono);
    string getTelefono();
	void setIdRegion(string idRegion);
	string getIdRegion();
    void print();
};

#include "Persona.hxx"
#endif
