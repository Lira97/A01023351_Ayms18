/*
 -- EXAMEN 2 PARCIAL --
 - Nombre: Daniela Flores
 - ID: A01023226
 - NOTA: Usar -std=c++11
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#define SIZE 8
#define NUMBER_OBJECTS 7

using namespace std;

template <class T> 
class Iterator; 


/******** Clase Collection ********/
template <class T> 
class Collection{
	public:
		T* array;
		int size;
		int cont;

	public: 
		friend class Iterator<T>;

		Collection(){
			size = 10;
			cont = 0;
			array = new T[size];
		}

		void addElement(T value){
			if (cont <= size){
				array[cont++] = value;
				return;
			}
			else{
				cout<<cont;
				cout << "\nYa no hay espacio para agregar elementos" << endl;
			}
		}

		Iterator<T>* getIterator();

		T at(int pos){
			return array[pos];
		}
};

/******** Clase Iterator ********/
template <class T> 
class Iterator{
	protected:
		Collection<T> coll;
		int cont = 0;

	public:
		Iterator(const Collection<T>& coll) : coll(coll){}
	
		bool hasNext(){
			if (cont < coll.cont)
				return true;
			return false;
		}

		T Next(){
			return coll.at(cont++);
		}
};

template <class T> 
Iterator<T>* Collection<T>:: getIterator(){
	return new Iterator<T>(*this);
}

/******** Clase Gráfico ********/
class videojuego{
	
	public:
		int id;
		string ano;
		string nombre;
		
		videojuego() = default;

		// Métodos para el acceso a los atributos
		void Concepcion(){
			cout << "Concepcion" << endl;
		}
		void Diseno(){
			cout << "Diseno" << endl;
		}
		void Planificacion(){
			cout << "Planificacion" << endl;
		}
		void Produccion(){
			cout << "Produccion" << endl;
		}
		void Pruebas(){
			cout << "Pruebas de aceptación" << endl;
		}
		

};


/********** Estrategia **********/
class Estrategia : public videojuego{
	protected:
		Estrategia() = default;
};

class Lucha : public Estrategia{
	//friend class Galaxia;
	public:
		Lucha(){
			nombre = "Lucha";
			ano = "2000";
		}
};

class Arcade :  public Estrategia{
	
	public:
		Arcade(){
			nombre = "Arcade";
			ano = "2000";
		}
};


/********** Aventuras ***********/
class Aventura : public videojuego{
	protected:
		Aventura() = default;
};

class Plataforma : public Aventura{
	
	public:
		Plataforma(){
			nombre = "Plataforma";
			ano = "2000";
		}
};

class Grafica : public Aventura{
	
	public:
		Grafica(){
			nombre = "Grafica";
			ano = "2000";
		}
};

/************ Aprendizajes ***********/
class Aprendizaje : public videojuego{
	protected:
		Aprendizaje() = default;
};

class Idiomas : public videojuego{
	
	public:
		Idiomas(){
			nombre = "Idiomas";
			ano = "2000";
		}
};

class Musica : public videojuego{
	
	public:
		Musica(){
			nombre = "Musica";
			ano = "2000";
		}
};

class Juego{
	
	protected:
		int cont = 1;
		int t = 0;
		
		
	public:
		Juego(){}
		vector<videojuego*> videojuegos;
		Collection<videojuego*> i; 
		Iterator<videojuego*> *it; // iterator
		
		void crearJuego(){
			Juego* juego = new Juego();
			Lucha* p1 = new Lucha();
			Arcade* p2 = new Arcade();
			
			
			// Galaxia tiene Aventuraes
			Plataforma* p4 = new Plataforma();
			Grafica* p5 = new Grafica();
	
			// Galaxia tiene Aprendizajeas
			Idiomas* p6 = new Idiomas();
			Musica* p7 = new Musica(); 	
			juego->imprimir();
		}

		// Agrega el gráfico al tablero del juego
		void agregarvideojuego (videojuego* g)
		{
			it = i.getIterator();
			g->id = cont;
			// Agrego al vector
			videojuegos.push_back(g);
			// Agrego al observer
			i.addElement(g);
			cont++;
			
		}
		void imprimir ()
		{
			for( int j = 0; j < videojuegos.size(); j++ )
				cout << videojuegos[j]->nombre << videojuegos[j]->ano << endl;
		}
		void eliminar(string nombre)
		{
			for(int i = 0; videojuegos.size()>i; i++)
			{
				if ( videojuegos[i]->nombre == nombre)
				{
	        	videojuegos.erase (videojuegos.begin()+i);
				break;
				}
			 }
		}
		void total()
		{
			cout << videojuegos.size()<< endl;
		}
		void buscar(int id)
		{
			for(int i = 0; videojuegos.size()>i; i++)
			{
				if ( videojuegos[i]->id == id)
				{
	        	cout << videojuegos[i]->nombre << videojuegos[i]->ano << endl;
				break;
				}
			 }
		}


	
};

int main(){
	
	Juego* juego = new Juego();
		Lucha* p1 = new Lucha();
		Arcade* p2 = new Arcade();
		
		
		// Galaxia tiene Aventuraes
		Plataforma* p4 = new Plataforma();
		Grafica* p5 = new Grafica();
	
		// Galaxia tiene Aprendizajeas
		Idiomas* p6 = new Idiomas();
		Musica* p7 = new Musica(); 	
	juego->agregarvideojuego(p1);
	juego->agregarvideojuego(p2);
	juego->agregarvideojuego(p4);
	juego->agregarvideojuego(p5);
	juego->agregarvideojuego(p6);
	juego->agregarvideojuego(p7);
	juego->imprimir();
	cout << endl;
	juego->eliminar("Lucha");
		juego->imprimir();
		juego->total();
	juego->buscar(2);	
	return 0;
}