#ifndef __PAQUETE_HXX__
#define __PAQUETE_HXX__

#include "Paquete.h"
using namespace std;

		Paquete::Paquete(double peso,string tipo,string id, Persona remitente, Persona destinatario){
			this->peso=peso;
			this->tipo = tipo;
			this->id = id;
			this->remitente=remitente;
			this->destinatario=destinatario;
			cout<<"paquete creado"<<endl;
		}
		Paquete::Paquete(){
		}
		double Paquete::getPeso(){
			return this->peso;
		}
		string Paquete::getTipo(){
			return this->tipo;
		}
		string Paquete::getId(){
			return this->id;
		}
		Persona Paquete::getRemitente(){
			return this->remitente;
		}
		Persona Paquete::getDestinatario(){
			return this->destinatario;
		}

		void Paquete::setPeso(double peso){
			this->peso=peso;
		}
		void Paquete::setTipo(string tipo){
			this->tipo = tipo;
		}
		void Paquete::setId(char * id){
			this->id = id;
		}
		void Paquete::setRemitente(Persona remitente){
			this->remitente=remitente;
		}
		void Paquete::setDestinatario(Persona destinatario){
			this->destinatario=destinatario;
		}
		void Paquete::print(){
			cout<<"      "<<this->id;
		}

#endif
