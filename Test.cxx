#include <iostream>
#include <stdlib.h>
#include "Persona.h"
#include "Paquete.hxx"
#include "Region.hxx"
#include "Oficina.h"
#include "Empresa.hxx"

using namespace std;

void imprimirMenu()
{
  cout<<"1. Cargar Personas"<<endl;
  cout<<"2. Cargar Paquetes"<<endl;
  cout<<"3. Registrar Persona"<<endl;
  cout<<"4. Registrar Paquete"<<endl;
  cout<<"5. Conteo de Paquetes"<<endl;
  cout<<"6. Cargar Oficinas"<<endl;
  cout<<"7. Cargar Regiones"<<endl;
  cout<<"8. Registrar Oficina"<<endl;
  cout<<"9. Registrar Region"<<endl;
  cout<<"10. repartir Paquetes"<<endl;
  cout<<"11. Cargar Conexiones"<<endl;
  cout<<"12. Buscar ruta"<<endl;
  cout<<"13. salir"<<endl;
}
int main()
{
  char* nombreEmpresa = new char[15];
  cout<<"----------------------------------------------------------------------------------------------"<<endl;
  cout<<"Bienvenido, antes de iniciar ingrese el nombre de la empresa por favor. "<<endl;
  cout<<"----------------------------------------------------------------------------------------------"<<endl;
  cin.getline(nombreEmpresa, 15);
  Empresa nEmpresa = Empresa(nombreEmpresa);
  int opcion;
  int arch;
  string archivo;
  string a,b,c,d;
  string nombreArchivo;
  string nombres;
  string apellidos;
  string iD;
  string direccion;
  string ciudad;
  string telefono;
  int estado;
  double peso;
  string tipoContenido;
  string numGuia;
  string cedulaR;
  string cedulaD;
  string codigoOficina;
  string nombreOficina;
  string direccionOficina;
  string ciudadOficina;
  string nombreRegion;
  string codigoRegion;
  imprimirMenu();
  cin>>opcion;
  while(opcion != 13)
  {
    switch (opcion) {
      case 1:
	  cout<<"Ingrese el nombre del archivo: "<<endl;
      cin>>nombreArchivo;
      arch = nEmpresa.cargarPersonas(nombreArchivo);
      if(arch == 1)
      {
        cout<<"Se cargo correctamente el archivo"<<endl;
		nEmpresa.mostrarOficinas();
      }else{
        cout<<"No se cargo correctamente el archivo"<<endl;
      }
	  system("PAUSE");
	  system("cls");
	  
      break;
      case 2:
	  cout<<"Ingrese el nombre del archivo: "<<endl;
      cin>>nombreArchivo;
      arch = nEmpresa.cargarPaquete(nombreArchivo);
      if(arch == 1)
      {
        cout<<"Se cargo correctamente el archivo"<<endl;
      }else{
        cout<<"No se cargo correctamente el archivo"<<endl;
      }
	   system("PAUSE");
	  system("cls");
      break;

      case 3:
      cout<<"Ingrese el nombre de la persona"<<endl;
      cin>>nombres;
      cout<<"Ingrese los apellidos de la persona"<<endl;
      cin>>apellidos;
      cout<<"Ingrese la identificacion de la persona"<<endl;
      cin>>iD;
      cout<<"Ingrese la direccion de residencia de la persona"<<endl;
      cin>>direccion;
      cout<<"Ingrese la ciudad de residencia de la persona"<<endl;
      cin>>ciudad;
      cout<<"Ingrese el telefono de la persona"<<endl;
      cin>>telefono;
	  cout<<"Ingrede el id de la region "<<endl;
	  cin>>a;
      estado = nEmpresa.registrarPersona(nombres, apellidos, iD, direccion, ciudad, telefono,a);
      if(estado==0)
      {
        cout<<"La persona con la identificacion: "<<iD<<" ya existe"<<endl;
      }else{
        cout<<"Agregada correctamente"<<endl;
      }
	   system("PAUSE");
	  system("cls");
      break;

      case 4:
	   cout<< "peso"<<endl;
	   cin>> peso;
      cout<<"tipoContenido"<<endl;
	  cin>>tipoContenido;
      cout<<"numGuia"<<endl;
	  cin>> numGuia;
      cout<<"cedulaR"<<endl;
	  cin>> cedulaR;
      cout<<"cedulaD"<<endl;
      cin>> cedulaD;
      estado = nEmpresa.registrarPaquete(peso, tipoContenido, numGuia, cedulaR, cedulaD);
      if(estado==0)
      {
        cout<<"El paquete ya existe"<<endl;
      }else
      {
        cout<<"El paquete fue registado correctamente"<<endl;
      }
	   system("PAUSE");
	  system("cls");
      break;

      case 5:
      int total;
      nEmpresa.conteoPaquetes();
	   system("PAUSE");
	  system("cls");
      break;
		case 6:
        cout<<"ingrese el nombre del archivo: ";
        cin>>archivo;
        nEmpresa.cargarOficina(archivo);
		 system("PAUSE");
	  system("cls");
      break;
		case 7:
        cout<<"ingrese el nombre del archivo: ";
        cin>>archivo;
        nEmpresa.cargarRegion(archivo);
		 system("PAUSE");
	  system("cls");
    break;
    case 8:
        
		cout<<"ingrese el id:";
        cin>>a;
        cout<<"ingrese el nombre:";
        cin>>b;
        cout<<"ingrese la direccion:";
        cin>>c;
        cout<<"ingrese la ciudad:";
        cin>>d;
        nEmpresa.registrarOficina(a,b,c,d);
		 system("PAUSE");
	  system("cls");
      break;
      case 9:
        cout<<"ingrese el id de la oficina:";
        cin>>a;
        cout<<"ingrese el id de la region:";
        cin>>b;
        cout<<"ingrese el nombre:";
        cin>>c;
        if(nEmpresa.registrarRegion(a,b,c)==1){
          cout<<"registro exitoso"<<endl;
        }else{
          cout<<"no se pudo hacer el registro"<<endl;
        }
		 system("PAUSE");
	  system("cls");
      break;
	  case 10:
	  	nEmpresa.repartirPaquetes();
		 system("PAUSE");
	  system("cls");
      break;
	  case 11:
	  cout<<"Ingrese el nombre del archivo: "<<endl;
      cin>>nombreArchivo;
      arch = nEmpresa.cargarConexion(nombreArchivo);
      if(arch == 1)
      {
        cout<<"Se cargo correctamente el archivo"<<endl;
      }else{
        cout<<"No se cargo correctamente el archivo"<<endl;
      }
	   system("PAUSE");
	  system("cls");
	  break;
	  case 12:
	  	string id0,id1;
		list<string> ruta;
	  	nEmpresa.mostrarOficinas();
		cout<<"ingrese el codigo de la oficina de partida:";
		cin>>id0;
		cout<<"ingrese el codigo de la oficina de llegada:";
		cin>>id1;
		ruta=nEmpresa.camino(id0,id1);
		if(ruta.size()>0){
			for(auto i=ruta.begin();i!=ruta.end();i++){
				cout<<*i<<" ";
			}
			cout<<endl;
		}else{
			cout<<"no existe la rura"<<endl;
		}
		system("PAUSE");
	  system("cls");
	  break;
    }
    imprimirMenu();
    cin>>opcion;
  }
}
/**/
