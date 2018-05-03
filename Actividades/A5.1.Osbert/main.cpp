#include <iostream>
#include "galeria.h"

int main() 
{
	Galeria galeria;
	Cliente cliente("Enrique Lira ", "Dir");
	Cuadro cuadro1("Dali", "Reloj", 1023222);
	Cuadro cuadro2("Diego rivera", "rios", 323230);
	galeria.vender(cuadro1, cliente, 120, 1980);
	galeria.vender(cuadro2, cliente, 80, 1995);
	
	string main_input;
	
	do {
		cout << "1 Oferta\n2 Imprimir ventas\n0 Salir\n";
		getline (cin, main_input);
		if(main_input == "1") 
		{
			string nombre, Pintor;
			
			cout << "Nombre del cuadro: ";
			getline (cin, nombre);
			cout << "Pintor del cuadro: ";
			
			getline (cin, Pintor);
			float precio = galeria.getOferta(Cuadro(Pintor, nombre, 0));
			if(precio == -1)
			{
				cout << "No se encontró ningún cuadro similar.\n";
				continue;
			}
			cout << "Precio: " << precio << "\n¿Comprar por ese precio?\n[s] Si\n[n] No\n";
			string purchase_answer;
			getline (cin, purchase_answer);
			if(purchase_answer == "s") 
			{
				string nombre_comprador, direccion_comprador;
				cout << "Nombre del Clinete: ";
				getline (cin, nombre_comprador);
				cout << "Dirección domicilio: ";
				getline (cin, direccion_comprador);
				galeria.vender(Cuadro(Pintor, nombre, precio),Cliente(nombre_comprador, direccion_comprador), precio);
			}
		} 
		else if(main_input == "2") 
		{
			galeria.imprimirVentas();
		}	
	} 
	while(main_input != "0");
	return 1;
}