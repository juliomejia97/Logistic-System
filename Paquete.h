#ifndef __PAQUETE_H__
#define __PAQUETE_H__

#include "Persona.h"
#include <string>
using namespace std;
class Paquete{
	public:
		Paquete(double peso,string tipo,string id, Persona remitente, Persona destinatario);
		Paquete();
		double getPeso();
		string getTipo();
		string getId();
		Persona getRemitente();
		Persona getDestinatario();

		void setPeso(double peso);
		void setTipo(string tipo);
		void setId(char * id);
		void setRemitente(Persona remitente);
		void setDestinatario(Persona destinatario);
		void print();
	private:
		double peso;
		string tipo;
		string id;
		Persona remitente;
		Persona destinatario;

};

#include "Paquete.hxx"
#endif
