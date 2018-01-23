#include <iostream>
#include <string>
using namespace std;
class Mobiles
{
public:
	Mobiles(){};
	string *marca;
	string *Nserie;
	string a;
	string b;
	Mobiles(string marca, string Nserie,string a,string b):marca(new string(marca)), Nserie(new string(Nserie)),a(a),b(b){}
	virtual Mobiles* clone() = 0;
	void encender(){
		cout << "encender" << endl;
	}
	void apagar(){
		cout << "apagar" << endl;
	}
	void reiniciar(){
		cout << "reiniciar" << endl;
	}
	void restaurar(){
		cout << "restaurar" << endl;
	}
	
};

class Tablet : public Mobiles
{
public:
	Tablet(){};
		string T;
		Tablet(string marca, string Nserie,string a ,string b,string T): Mobiles(marca, Nserie,a,b),T(T)
		{}
		Tablet(const Tablet& p)
		{
			marca = new string (*(p.marca));
			Nserie = new string (*(p.Nserie));
			a=p.a;
			b=p.b;
			T=p.T;
		}
	Mobiles* clone()
	{ 
		return new Tablet(*this);
	}
};

class Smartphone : public Mobiles
{
public:
	string phone;
	Smartphone(string marca, string Nserie,string a ,string b,string phone):Mobiles(marca, Nserie,a,b),phone(phone){}
	Smartphone(const Smartphone& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		phone=p.phone;
	}
	Mobiles* clone()
	{ 
		return new Smartphone(*this);
	}
};
class Smartwatch : public Mobiles
{
public:
	string watch;
	Smartwatch(string marca, string Nserie,string a ,string b,string watch): Mobiles(marca, Nserie,a,b),watch(watch){}
	Smartwatch(const Smartwatch& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		watch=p.watch;
	}
	Mobiles* clone()
	{ 
		return new Smartwatch(*this);
	}
};
int main()
{
	Tablet* c1 = new Tablet("ffr","353","353","353","353");
	cout << *c1->marca << endl;
		cout << *c1->Nserie << endl;
		cout << (c1->a) << endl;
		cout << (c1->b) << endl;
		cout << (c1->T) << endl;
}
