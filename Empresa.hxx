#ifndef __EMPRESA_HXX__
#define __EMPRESA_HXX__

#include "Empresa.h"
using namespace std;

		Empresa::Empresa(string nombre){
			this->nombre = nombre;
			this->directorio=list<Persona>();
			this->oficinas=Graph<Oficina,double>();
			this->x=0;
			cout<<"Se creo correctamente la empresa"<<endl;
		}
		string Empresa::getNombre(){
			return this->nombre;
		}
		list<Persona> Empresa::getDirectorio(){
			return this->directorio;
		}
		Graph<Oficina,double> Empresa::getOficinas(){
			return this->oficinas;
		}
		void Empresa::setNombre(string nombre){
			this->nombre = nombre;
		}
		void Empresa::setDirectorio(list<Persona> directorio){
			this->directorio=directorio;
		}
		void Empresa::setOficinas(Graph<Oficina,double> oficinas){
			this->oficinas=oficinas;
		}

		int Empresa::cargarPersonas(string archivo){
			ifstream fs(archivo);
			string nom;
			string ape;
			string id;
			string dir;
			string ciu;
			string tel;
			string idR;
			if(fs.is_open())
			{
				string linea;
				int pActual;
				getline(fs, linea);
				while(!fs.eof())
				{
					getline(fs, nom, ',');
					getline(fs, ape, ',');
					getline(fs, id, ',');
					getline(fs, dir, ',');
					getline(fs, ciu, ',');
					getline(fs, tel,',');
					getline(fs, idR);
					pActual = this->registrarPersona(nom,ape,id, dir,ciu,tel,idR);
					if(pActual == 1)
					{
						cout<<"Registado correctamente "<<nom<<" "<<ape<<endl;
					}else
					{
						cout<<"No fue registado correctamente "<<nom<<" "<<ape<<endl;;
					}
				}
				return 1;
			}else
			{
				return 0;
			}
		}

		int Empresa::cargarPaquete(string archivo){
			ifstream file(archivo);
			int estado;
			string linea;
			double peso;
			string cedulaR, cedulaD, pesoS;
			string tipoContenido,nombreOficina,direccionOficina,ciudadOficina,nombreRegion, numGuia;
			getline(file, linea);
			if(file.is_open())
			{
				while(!file.eof())
				{
					getline(file, cedulaR, ',');
					getline(file, cedulaD, ',');
					getline(file, pesoS, ',');
					peso = stod(pesoS);
					getline(file, tipoContenido, ',');
					getline(file, numGuia);
					if(this->existenciaPersona(cedulaR) && this->existenciaPersona(cedulaD))
					{
						estado = this->registrarPaquete(peso,tipoContenido,numGuia,cedulaR,cedulaD);
						if(estado==0)
						{
							cout<<"El paquete ya existe"<<endl;
						}else
						{
							cout<<"El paquete fue registado correctamente"<<endl;
						}
					}
					else
					{
						cout<<"\nUna de las dos personas no se encuentra registrada"<<endl;
					}

				}
				return 1;
		}else
		{
			return 0;
		}
}

		bool Empresa::existenciaPersona(string id){
			for(auto i=directorio.begin();i!=directorio.end();i++){
				if((*i).getiD()==id){
					return true;
				}
      			}
			return false;
		}

		bool Empresa::existenciaPaquete(string id){
			list<Oficina *> ofi = oficinas.toList();
			for(auto i = ofi.begin(); i != ofi.end(); i++)
			{
				if((*i)->existenciaPaquete(id)){
					return 1;
				}
			}
			return 0;
		}

		int Empresa::registrarPersona( string nombres,string apellidos,string iD,string direccion,string ciudad,string telefono,string idR){
			if(this->existenciaPersona(iD)){
				return 0;
			}else{
				Persona p= Persona(nombres,apellidos,iD,direccion,ciudad,telefono,idR);
				directorio.push_back(p);
				return 1;
			}
		}

		int Empresa::registrarPaquete(double peso,string tipoContenido,string numGuia,string cedulaR,string cedulaD){
			if(this->existenciaPaquete(numGuia)){
				return 0;
			}else{
				Persona r,d;
				r=this->buscarPersona(cedulaR);
				d=this->buscarPersona(cedulaD);
				Paquete P= Paquete(peso,tipoContenido, numGuia,r,d);
				Oficina *o=this->buscarOficinaRegion(r.getIdRegion());
				if(o==NULL){
					return 0;
				}
				o->agregarPaquete(P);
				return 1;
			}
		}
		Oficina* Empresa::buscarOficinaRegion(string idRegion)
		{
			list<Oficina*> ofi  = oficinas.toList();
			for(auto i = ofi.begin(); i != ofi.end();i++)
			{
				if((*i)->existenciaRegion(idRegion)){
					return (*i);
				}
			}
			return NULL;
		}

		Persona Empresa::buscarPersona(string id){
			for(auto i=directorio.begin();i!=directorio.end();i++){
				if((*i).getiD().compare(id)==0){
					return *i;
				}
			}
			Persona p=Persona();
			return p;
		}

		Oficina *Empresa::buscarOficina(string id){
			 list<Oficina*> o = oficinas.toList();
			for(auto i=o.begin();i!=o.end();i++){
				if((*i)->getId()==id){
					return (*i);
				}
			}
			return NULL;
		}
		
		void Empresa::conteoPaquetes(){
			int r=0;
			list<Oficina*> L=oficinas.toList();
			for(auto i = L.begin(); i != L.end(); i++){
				cout<<"La cantidad de paquetes  en la oficina "<<(*i)->getNombre()<<" es de: "<<(*i)->getPaquetes().size()<<endl;
		}
			
		}
void Empresa::listarPersonas()
{
	for(auto i=directorio.begin();i!=directorio.end();i++){
		cout<<(*i).getiD()<<endl;
	}
}

bool Empresa::existeOficina(string id){
list<Oficina*> L=oficinas.toList();
	for(auto i=L.begin();i!=L.end();i++){
	string s=(*i)->getId();
		if(id==(*i)->getId()){
			return true;
		}
	}
	return false;
}

int Empresa::crearOficina(string id,string nombre,string direccion,string ciudad){
	if(!existeOficina(id)){
		Oficina insertar = Oficina(id,nombre, direccion,ciudad);
		oficinas.insertVertex(insertar);
		return 1;
	}
	return 0;
}



int Empresa::cargarOficina(string archivo){
	ifstream fs(archivo);
			string nom;
			string id;
			string dir;
			string ciu;
			if(fs.is_open())
			{
				string linea;
				int pActual;
				getline(fs, linea);
				while(!fs.eof())
				{
					getline(fs, id, ',');
					getline(fs, nom, ',');
					getline(fs, dir, ',');
					getline(fs, ciu);
					pActual = this->crearOficina(id,nom, dir,ciu);
					if(pActual == 1)
					{
						cout<<"Registado correctamente "<<nom<<endl;
					}else
					{
						cout<<"No fue registado correctamente "<<nom<<endl;;
					}
				}
		
				return 1;
			}else
			{
				return 0;
			}	
}
int Empresa::crearRegion(string id_O,string id,string nombre){
  	Oficina *o=buscarOficina(id_O);
	if(o!=NULL){
		return o->crearRegion(nombre,id);
	}
	return 0;
}
//____________
int Empresa::cargarRegion(string archivo){
  	ifstream fs(archivo);
			string nom;
			string id;
			string id_O;
			if(fs.is_open())
			{
				string linea;
				int pActual;
				getline(fs, linea);
				while(!fs.eof())
				{
					getline(fs, id, ',');
					getline(fs, nom, ',');
					getline(fs, id_O);
					pActual = this->crearRegion(id_O,id,nom);
					if(pActual == 1)
					{
						cout<<"Registado correctamente "<<nom<<endl;
					}else
					{
						cout<<"No fue registado correctamente "<<nom<<endl;
					}
				}
				
				return 1;
			}else
			{
				return 0;
			}	
}

void Empresa::mostrarOficinas()
{
	list<Oficina*> L=oficinas.toList();
	for(auto i=L.begin();i!=L.end();i++){
		cout<<(*i)->getNombre()<<":"<<(*i)->getId()<<endl;
	}
}

int Empresa::registrarOficina(string id,string nombre,string direccion,string ciudad){
  return this->crearOficina(id,nombre,direccion,ciudad);
}

int Empresa::registrarRegion(string id_O,string id,string nombre){
  Oficina * o=this->buscarOficina(id_O);
  if(o!=NULL){
    return o->crearRegion(nombre,id);
  }
  return 0;
}

void Empresa::repartirPaquetes(){
	list<Oficina*> L=oficinas.toList();
	list<Paquete> P;
	list<Paquete> P_;
	Paquete p;
	Oficina *o;
	string idR;
	for(auto i=L.begin();i!=L.end();i++){
		int r=0;
		int n=(*i)->getPaquetes().size();
		P=(*i)->getPaquetes();
		(*i)->setPaquetes(list<Paquete>());
		for(auto j=P.begin();j!=P.end();j++){
			idR=(*j).getDestinatario().getIdRegion();
			o=buscarOficinaRegion(idR);
			o->addPaquete((*j));
			if(o->getId()!=(*i)->getId()){
				r++;
			}
		}
		cout<<"paquetes enviados desde "<<(*i)->getNombre()<<":"<<r<<endl;
	}
}

int Empresa::cargarConexion(string archivo){
		ifstream fs(archivo);
			string id0;
			string id1;
			string sdist;
			if(fs.is_open())
			{
				string linea;
				int pActual;
				double dist;
				getline(fs, linea);
				while(!fs.eof())
				{
					getline(fs,sdist);
					getline(fs, id0, ',');
					getline(fs, id1, ',');
					getline(fs, sdist);
					if(sdist.size()<1){
						break;
					}
					pActual = this->crearConexion(id0,id1,dist);
					if(pActual == 1)
					{
						cout<<"Registado correctamente "<<id0<<"-"<<id1<<endl;
					}else
					{
						cout<<"No fue registado correctamente "<<id0<<"-"<<id1<<endl;
					}
				}
		
				return 1;
			}else
			{
				return 0;
			}	
}


int Empresa::crearConexion(string id0,string id1,double dist){
	Oficina *o0,*o1;
	long n0,n1;
	o0=buscarOficina(id0);
	o1=buscarOficina(id1);
	if(o0==NULL||o1==NULL){
		return 0;
	}
	n0=oficinas.getIndexOf(*o0);
	n1=oficinas.getIndexOf(*o1);
	oficinas.insertEdge(n0,n1,dist);
	oficinas.insertEdge(n1,n0,dist);
	return 1;
}

list<string> Empresa::camino(string id0,string id1){
	list<string> R;
	vector<vector<long>> D;
	vector<long> aux;
	Oficina *o0,*o1;
	long n0,n1,r;
	o0=buscarOficina(id0);
	o1=buscarOficina(id1);
	if(o0==NULL||o1==NULL){
		return R;
	}
	n0=oficinas.getIndexOf(*o0);
	n1=oficinas.getIndexOf(*o1);
	D=oficinas.prim(n0);
	aux=D[n1];
	for(int i=0;i<aux.size();i++){
		Oficina o=oficinas.getNode(aux[i]);
		R.push_back(o.getId());
	}
	return R;
}

#endif
