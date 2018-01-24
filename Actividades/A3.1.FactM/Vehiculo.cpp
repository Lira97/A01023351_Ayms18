#include <iostream>
using namespace std;

class Product
{
	public:
		virtual void operacion1()=0;
		virtual void operacion2()=0;
};

class Producto1 : public Product
{
	public:
	void operacion1()
	{
		cout<<"estoy en operacion 1 Prod 1"<<endl;
		
	}
	void operacion2()
	{
		cout<<"estoy en operacion 2 Prod 1"<<endl;
			
	}
};

class Producto2 : public Product
{
	public:
	void operacion1()
	{
		cout<<"estoy en operacion 1 Prod 2";
		
	}
	void operacion2()
	{
		cout<<"estoy en operacion 2 Prod 2";
			
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
			temporal->operacion1();
			temporal->operacion2();
			return temporal;
		}
};

int main() 
{
	Creator *p = new Creator;
	Producto1 *Dodge = p->create<Producto1>();

}