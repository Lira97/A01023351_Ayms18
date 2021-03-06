#include <iostream>
#include <vector>
#include <string>

using namespace std;

class IVisitor;

class videojuego{
public: 
	int serie;
	float precio;
	string nombre; 
	string compania;
	string consola; 

	videojuego()=default; 

	void Concepcion(){
		cout << "Concepción" << endl;
	}

	void Diseno(){
		cout << "Diseño" << endl;
	}

	void Planificacion(){
		cout << "Planificación" << endl; 
	}

	void Produccion(){
		cout << "Producción" << endl;
	}

	void PuebasAcpt(){
		cout << "Puebas de aceptación" << endl;
	}
	void setPrice(float p){
		precio = p; 
	}
	void accept(IVisitor* visitor, float a);
};

class Estrategia : public videojuego {
protected: 
	Estrategia() = default;
public:
	void accept(IVisitor* visitor, float a);
};

class Aventura : public videojuego{
protected: 
	Aventura() = default;
public: 
	void accept(IVisitor* visitor, float a);
};

class Aprendizaje :public videojuego{
protected: 
	Aprendizaje() = default;
public:
	void accept(IVisitor* visitor, float a);
};

class Lucha : public Estrategia{
public:
	Lucha(){
		nombre = "Mortal kombat";
		compania = "GamesAES";
		consola = "PlayStation";
	}
};

class Arcade : public Estrategia{
public: 
	Arcade(){
		nombre = "Metal Slug";
		compania = "CG";
		consola = "PlayStation";
	}
};

class Plataforma : public Aventura{
public:
	Plataforma(){
		nombre = "bandiccot";
		compania = "PlayStation";
		consola = "PlayStation 3";   
	}
};

class Grafica : public Aventura{
public: 
	Grafica(){
		nombre = "Mario galaxy";
		compania = "Nintendo";
		consola = "WII";
	}
};

class Idiomas : public Aprendizaje{
public: 
	Idiomas(){
		nombre = "laberitnos";
		compania = "smartgames";
		consola = "PlayStation";
	}
};

class Musica : public Aprendizaje{
public:
	Musica(){
		nombre = "rock band";
		compania = "Music";
		consola = "PlayStation";
	}
};
template<class T>
class Iterator;

class IVisitor{
public: 
	virtual void visit(Estrategia, float a)=0;
	virtual void visit(Aventura, float a)=0;
	virtual void visit(Aprendizaje, float a)=0;
};

class Aumento : public IVisitor{
public:
	void visit (Estrategia s, float a)
	{
		float b = a/10;
		s.precio = s.precio * (1 + b);
	}
	void visit (Aventura s, float a){
		float b = a/10;
		s.precio = s.precio * (1 + b);
	}
	void visit (Aprendizaje s, float a){
		float b = a/10;
		s.precio = s.precio * (1 + b);
	}
};

class Descuento : public IVisitor{
public:
	void visit (Estrategia s, float a)
	{
		float b = a/10;
		s.precio = s.precio - s.precio * 1 + b;
	}
	void visit (Aventura s, float a){
		float b = a/10;
		s.precio = s.precio - s.precio * 1 + b;
	}
	void visit (Aprendizaje s, float a){
		float b = a/10;
		s.precio = s.precio - s.precio * 1 + b;
	}
};

template<class T>
class Collection{
public: 
	T* array; 
	int max; 
	int cont;

	friend class Iterator<T>; 

	Collection(){
		max = 10;
		cont = 0; 
		array = new T[max]; 
	}

	void add(T game){
		if (cont <= max){
			game->serie = cont;
			array[cont++] = game;

		}
		else{
			cout << "YA NOTIENES ESPACIO " << endl;
		}
	}

	T at (int position){
		if (0 > position){
			cout << " no valido" << endl;
			throw "out of range"; 
		}
	}

	int getNumElements(){
		return cont;
	}

	void imprimirColl(){
		for (int i = 0; i < cont; i++){
			cout << "Nombre = " << array[i]->nombre <<
			 ", " << "Compañia = " << array[i]->compania << 
			 ",  " << "Consola = " << array[i]->consola <<
			 ",  " << "Precio = " << array[i]->precio <<
			 ",  " << "No. Serie = " << array[i]->serie << endl;
		}
	}

	void buscarColln(string n){
		for(int i = 0; i < cont; i++){
			if (n == array[i]->nombre){
				cout << "No. Serie: " << array[i]->serie << endl;
				cout << "Nombre: "<< array[i]->nombre << endl;
				cout << "Compañia: " << array[i]->compania << endl;
				cout << "Consola: " << array[i]->consola << endl;
				cout << "Precio: " << array[i]->precio << endl;
			}
			else{
				cout << "El juego buscado no se encuentra en el inventario" << endl;
			}
		}
	}

	void buscarColli(int n){
		for(int i = 0; i < cont; i++){
			if (n == array[i]->serie){
				cout << "No. Serie: " << array[i]->serie << endl;
				cout << "Nombre: "<< array[i]->nombre << endl;
				cout << "Compañia: " << array[i]->compania << endl;
				cout << "Consola: " << array[i]->consola << endl;
				cout << "Precio: " << array[i]->precio << endl;
			}
			else{
				cout << "El juego buscado no se encuentra en el inventario" << endl;
			}
		}
	}

	void borrarCollN(string n){
		for(int i = 0; i < cont; i++){
			if (n == array[i]->nombre){
				array[i] = NULL;
				cont--;
			}
		}
	}

	void borrarCollI(int n){
		for(int i = 0; i < cont; i++){
			if (n == array[i]->serie){
				array[i] = NULL;
				cont--;
			}
		}
	}

	void accept(IVisitor* visitor, float a){
		for(int i = 0; i < cont; i++){
			array[i]->accept(visitor, a);
		}
	}

	void ModPrice(string s, float a){
		if (s == "aumentar"){
			Aumento* aumento = new Aumento();
			accept(aumento, a);
		}else{
			Descuento* descuento = new Descuento();
			accept(descuento, a);
		}
	}

	Iterator<T>* getIterator();
};

template<class T>
class Iterator{
protected:
	Collection<T> collection;
	int cont = 0;
public:
	Iterator(const Collection<T>& collection) : collection(collection){}


	virtual T next(){
		T a  = collection.at(cont);
		cont++;
		return a; 
	}
	virtual bool hasNext(){
		if (cont < collection.cont){
			return true; 
		}else{
			return false; 
		}
	}
};

template<class T>

Iterator<T>* Collection<T>:: getIterator(){
	return new Iterator<T>(*this);
} 


class Inventario{
protected: 
	int i = 1;
	int t = 0; 
public: 
	Inventario(){}
	Collection<videojuego*> inv; 
	Iterator<videojuego*> *it; 

	void crearjuego(){
		Inventario* inventario = new Inventario(); 
	}
	void agregarJuego (videojuego* v){
		it = inv.getIterator();
		inv.add(v);
		i++;
	}

	int getElements(){
		return inv.getNumElements();
	}

	void imprimir(){
		inv.imprimirColl();
	}

	void buscarN(string n){
		inv.buscarColln(n);
	}

	void buscarI(int n){
		inv.buscarColli(n);
	}

	void borrarN(string n){
		inv.borrarCollN(n);
	}

	void borrarI(int n){
		inv.borrarCollI(n);
	}

	void ModTPrice(string s, float a){
		inv.ModPrice(s,a);
	}

   
};

class Command
{
public:
	virtual void execute() = 0;
};
 
class Accion 
{
public:
	void undo() {
		cout << "undo" << endl;
	}
	void redo() {
		cout << "redo" << endl;
	}
}; 

class undoCommand : public Command 
{
public:
	undoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->redo();
	}
private:
	Accion *mAction;
};
 
class redoCommand : public Command 
{
public:
		redoCommand(Accion *Accion) : mAction(Accion) {}
	void execute(){
		mAction->undo();
	}
private:
	Accion *mAction;
};

class RemoteControl 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	} 
private:
	Command *mCmd;
};


Inventario* uno = new Inventario();

void Estrategia::accept(IVisitor* visitor, float a){
	visitor->visit(*this, a);
}
void Aventura::accept(IVisitor* visitor, float a){
	visitor->visit(*this, a);
}
void Aprendizaje::accept(IVisitor* visitor, float a){
	visitor->visit(*this, a);
}

void menu2(int a);

void MenuPrincipal(){

	cout << "\nSITEMA INVETARIO " << endl;

	cout << 
	"1.- AGREGAR  \n"
	"2.- BORRAR  "
	"3.- IMPRIMIR \n"
	"4.- BUSCAR \n"
	"5.- MODIFICAR \n" << endl;

	int a;
	cin >> a;

	menu2(a);
	
}

void menu2(int a){

	switch(a){
		case 1:{
			cout << "QUE TIPO DE JUEGO DESEA AGREGAR\n"
			"A.- Estrategia\n"
			"B.- Aventura\n"
			"C.- Aprendizaje\n" << endl;
			char b; 
			cin >> b;
			switch(b){
				
				case 'A':{
					cout << "Juego que se desea agregar\n"
					"L.- Lucha\n"
					"R.- Arcade\n" << endl;
					char c;
					cin >> c;
					switch(c){
						case 'L':{
							cout << "Agregar precio" << endl;
							float p; 
							cin >> p;
							Lucha* g1 = new Lucha(); 
							g1->setPrice(p);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
						}
						case 'R':
							cout << "Agregar precio" << endl;
							float p2; 
							cin >> p2;
							Arcade* g1 = new Arcade(); 
							g1->setPrice(p2);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
					}
					break;
				}
				case 'B':{
				cout << "Juego que se desea agregar\n"
					"P.- Plataforma\n"
					"G.- Grafica\n" << endl;
					char c1;
					cin >> c1;
					switch(c1){
						case 'P':{
							cout << "Agregar precio" << endl;
							float p3; 
							cin >> p3;
							Plataforma* g1 = new Plataforma();
							g1->setPrice(p3);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
						}
						case 'G':{
							cout << "Agregar precio" << endl;
							float p4; 
							cin >> p4;
							Grafica* g1 = new Grafica();
							g1->setPrice(p4);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
						}
					}
				}
				case 'C':{
					cout << "Juego que se desea agregar\n"
					"I.- Idiomas\n"
					"M.- Musica\n" << endl;
					char c1;
					cin >> c1;
					switch(c1){
						case 'I':{
							cout << "Agregar precio" << endl;
							float p5; 
							cin >> p5;
							Idiomas* g1 = new Idiomas();
							g1->setPrice(p5);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
						}
						case 'M':{
							cout << "Agregar precio" << endl;
							float p6; 
							cin >> p6;
							Musica* g1 = new Musica();
							g1->setPrice(p6);
							uno->agregarJuego(g1);
							MenuPrincipal();
							break;
						}
					}
					break;
				}
			}
		
		case 2:
			cout << "Borrar por:\n" 
			"S.- No.serie\n"
			"O.- Nombre" << endl;
			char k;
			cin >> k;
			switch(k){
				case 'S':{
					cout << "Ingresar No. de Serie" << endl;
					int busq; 
					cin >> busq;
					uno->borrarI(busq);
					MenuPrincipal();
					break;
				}
				case 'O':{
					cout << "ingresar Nombre" << endl;
					string busqn;
					cin >> busqn;
					uno->borrarN(busqn);
					MenuPrincipal();
					break;
				}
			}
			break;
		case 3:
			cout << "Numero de elementos: "<< uno->getElements() << endl;
			uno->imprimir();
			MenuPrincipal();
			break;
			
		case 4:
			cout << "Buscar por: \n"
			"I.- No.Serie\n"
			"N.- Nombre" << endl;
			char j;
			cin >> j;
			switch(j){
				case 'I':{
					cout << "Ingresar No. de Serie" << endl;
					int busq; 
					cin >> busq;
					uno->buscarI(busq);
					MenuPrincipal();
					break;
				}
				case 'N':{
					cout << "ingresar Nombre" << endl;
					string busqn;
					cin >> busqn;
					uno->buscarN(busqn);
					MenuPrincipal();
					break;
				}
			}
			break;
		}
	}  
}

int main(){
	MenuPrincipal();
  
	return 0;
}
