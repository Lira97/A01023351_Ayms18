#include <iostream>
using namespace std;

class Product
{
	public:
		virtual void Ensamble()=0;
		virtual void Hojalateria()=0;
		virtual void Pintura()=0;
		virtual void Entrega()=0;
};

class Producto1 : public Product
{
	public:
	void Ensamble()
	{
		cout<<"estoy en operacion Ensamble Prod 1"<<endl;
		
	}
	void Hojalateria()
	{
		cout<<"estoy en operacion Hojalateria Prod 1"<<endl;
			
	}
	void Pintura()
	{
		cout<<"estoy en operacion Pintura Prod 1"<<endl;
				
	}
	void Entrega ()
	{
		cout<<"estoy en operacion Entrega Prod 1"<<endl;
			
	}
};

class Creator{
		template<class Vehiculo>
		static Vehiculo* factoryMethod()
		{
			return new Vehiculo;
		}
		public:
		template<class Vehiculo>
		static Vehiculo* create()
		{
			Vehiculo* temporal;
			temporal = factoryMethod<Vehiculo>();
			temporal->Ensamble();
			temporal->Hojalateria();
			temporal->Pintura();
			temporal-> Entrega ();
			return temporal;
		}
};

int main() 
{
	Creator *p = new Creator;
	Producto1 *Dodge = p->create<Producto1>();

}