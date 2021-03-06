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
		string* T;
		Tablet(string marca, string Nserie,string a ,string b,string T): Mobiles(marca, Nserie,a,b),T(new string (T))
		{}
		Tablet(const Tablet& p)
		{
			marca = new string (*(p.marca));
			Nserie = new string (*(p.Nserie));
			a=p.a;
			b=p.b;
			T = new string (*(p.T));
		}
	Mobiles* clone()
	{ 
		return new Tablet(*this);
	}
};

class Smartphone : public Mobiles
{
public:
	string* phone;
	Smartphone(){};
	Smartphone(string marca, string Nserie,string a ,string b,string phone):Mobiles(marca, Nserie,a,b),phone(new string (phone)){}
	Smartphone(const Smartphone& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		phone = new string (*(p.phone));
	}
	Mobiles* clone()
	{ 
		return new Smartphone(*this);
	}
};
class Smartwatch : public Mobiles
{
public:
	string* watch;
	Smartwatch(){};
	Smartwatch(string marca, string Nserie,string a ,string b,string watch): Mobiles(marca, Nserie,a,b),watch(new string (watch)){}
	Smartwatch(const Smartwatch& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		watch = new string (*(p.watch));
	}
	Mobiles* clone()
	{ 
		return new Smartwatch(*this);
	}
};
int main()
{
	Tablet* c1 = new Tablet();
	c1->encender();
	c1->apagar();
	c1->reiniciar();
	c1->restaurar();
	
	c1->marca = new string("Apple");
	c1->Nserie = new string("41NDUSJ78");
	c1->a = "5.2 In";
	c1->b = "af";
	c1->T = new string("das");
	
	cout << *c1->marca << endl;
	cout << *c1->Nserie << endl;
	cout << (c1->a) << endl;
	cout << (c1->b) << endl;
	cout << *c1->T << endl<< endl;
	

	Tablet* p = dynamic_cast<Tablet*>(c1->clone()); //DownCasting 
	
	p->marca = new string("ASUS");
	p->Nserie = new string("JKF94302");

	cout << *p->marca << endl;
	cout << *p->Nserie << endl;
	cout << (p->a) << endl;
	cout << (p->b) << endl;
	cout << *c1->T << endl<< endl;
	
	Tablet* pp = dynamic_cast<Tablet*>(p->clone());
	pp->a = "9.2";
	pp->b = "polss";
	
	cout << *pp->marca << endl;
	cout << *pp->Nserie << endl;
	cout << (pp->a) << endl;
	cout << (pp->b) << endl;
	cout << *pp->T << endl;
	
	
	Smartphone* c2 = new Smartphone();
	c2->marca = new string("Apple");
	c2->Nserie = new string("41NDUSJ78");
	c2->a = "5.2 In";
	c2->b = "af";
	c2->phone = new string("das");
		
	cout << *c2->marca << endl;
	cout << *c2->Nserie << endl;
	cout << (c2->a) << endl;
	cout << (c2->b) << endl;
	cout << *c2->phone << endl<< endl;
	
	Smartwatch* c3 = new Smartwatch();
	c3->marca = new string("Apple");
	c3->Nserie = new string("41NDUSJ78");
	c3->a = "3.2 In";
	c3->b = "af";
	c3->watch = new string("das");
			
	cout << *c3->marca << endl;
	cout << *c3->Nserie << endl;
	cout << (c3->a) << endl;
	cout << (c3->b) << endl;
	cout << *c3->watch << endl<< endl;
}
