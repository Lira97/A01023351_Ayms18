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

template<class Padre ,class SubClase>
class ClonMobile : public Padre{
	public:
		Padre* clone()
			{ 
				return new SubClase(dynamic_cast<SubClase&>(*this)); 
			}
		
			
};

class Tablet : public ClonMobile<Mobiles,Tablet>
{
public:
	Tablet(){};
	string T;
	Tablet(string m,string n,string a ,string b,string T):T(T)
	{
		marca = &m;
		Nserie =&n;	
		a=a;
		b=b;
		T=T;
	}
	
	Tablet(const Tablet& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		T=p.T;
	}
	
};

class Smartphone : public ClonMobile<Mobiles,Smartphone>
{
public:
	Smartphone(){};
	string phone;
	Smartphone(string m,string n,string a ,string b,string phone):phone(phone)
	{
		marca = &m;
		Nserie =&n;	
		a = a;
		b = b;
		phone=phone;
	}
	
	Smartphone(const Smartphone& p)
	{
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		phone=p.phone;
	}	
};
class Smartwatch : public ClonMobile<Mobiles,Smartwatch>
{
public:
	Smartwatch(){};
	string watch;
	Smartwatch(string m,string n,string a ,string b,string watch):watch(watch)
	{
		marca = &m;
		Nserie =&n;	
		a = a;
		b = b;
		watch=watch;
	}
	
	Smartwatch(const Smartwatch& p){
		marca = new string (*(p.marca));
		Nserie = new string (*(p.Nserie));
		a=p.a;
		b=p.b;
		watch=p.watch;
	}
	
};

int main()
{
	Tablet* c1 = new Tablet("Apple","Apple","Apple","Apple","Apple");
	c1->encender();
	
	c1->marca = new string("Apple");
	c1->Nserie = new string("41NDUSJ78");
	c1->a = "5.2 In";
	c1->b = "af";
	c1->T = "das";
	
	cout << *c1->marca << endl;
	cout << *c1->Nserie << endl;
	cout << (c1->a) << endl;
	cout << (c1->b) << endl;
	cout << (c1->T) << endl;
}