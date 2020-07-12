
#ifndef __OFICINA_HXX__
#define __OFICINA_HXX__

#include "Oficina.h"
using namespace std;


		Oficina::Oficina(string iD,string nombre,string direccion,string ciudad){
			this->iD=iD;
			this->ciudad=ciudad;
			this->nombre=nombre;
			this->direccion=direccion;
			this->regionesR;
		}
		Oficina::Oficina(){
		}
		void Oficina::setId(string pId){
			this->iD=pId;
		}
		string Oficina::getId(){
			return this->iD;
		}
		void Oficina::setNombre(string pNombre){
			this->nombre=pNombre;
		}
		string Oficina::getNombre(){
			return this->nombre;
		}
		void Oficina::setDireccion(string pDireccion){
			this->direccion=pDireccion;
		}
		string Oficina::getDireccion(){
			return this->direccion;
		}
		void Oficina::setCiudad(string pCiudad){
			this->ciudad=pCiudad;
		}
		string Oficina::getCiudad(){
			return this->ciudad;
		}
		void Oficina::setRegiones(list<Region> pRegiones){
			this->regionesR=pRegiones;
		}
		list<Region> Oficina::getRegiones(){
			return this->regionesR;
		}
		bool Oficina::existenciaRegion(string iD_R){
			for(auto i=regionesR.begin();i!=regionesR.end();i++){
				if(iD_R == i->getiD()){
					return true;
				}
			}
			return false;
		}
		void Oficina::agregarPaquete(Paquete p){
		this->paquetes.push_back(p);
		}

		Region *Oficina::buscarRegion(string id, string nombre){
			for(auto i=this->regionesR.begin();i!=this->regionesR.end();i++){
				if((*i).getiD() == id){
					return &(*i);
				}
			}
			return NULL;
		}
		
		int Oficina::crearRegion(string nombre, string iD){
			if(!existenciaRegion(iD)){
				Region r=*(new Region(nombre,iD));
				regionesR.push_back(r);
        			return 1;
			}
      	 return 0;
		}

		bool Oficina::existeRegion(string id){
			for(auto i=regionesR.begin();i!=regionesR.end();i++){
				if(id==(*i).getiD()){
					return true;
				}
			}
			return false;
		}

	list<Paquete> Oficina::getPaquetes()
	{
		return this->paquetes;
	}
	void Oficina::setPaquetes(list<Paquete> pPaquetes)
	{
		this->paquetes = pPaquetes;
	}
	 bool Oficina::eliminarPaquete(string guia)
	 {
	 	bool encontro = false;
		auto i = paquetes.begin();
	 	for(i; i!= paquetes.end(); i++)
		{
			if((*i).getId() == guia)
			{
				encontro = true;
				break;
			}
		}
		if(encontro)
		paquetes.erase(i);
		
		return encontro;
		
	 }
	 
	 bool Oficina::existenciaPaquete(string id){
	 	for(auto i=paquetes.begin();i!=paquetes.end();i++){
			if((*i).getId()==id){
				return true;
			}
		}
		return false;
	 }
	 void Oficina::addPaquete(Paquete p){
	 	this->paquetes.push_back(p);
	 }
#endif