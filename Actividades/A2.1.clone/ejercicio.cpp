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
	Mobiles(string marca, string Nserie):marca(new string(marca)), Nserie(new string(Nserie)){}
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
	Tablet(string marca, string Nserie): Mobiles(marca, Nserie){}
	Mobiles* clone()
	{ 
		return new Tablet(*this);
	}
};

class Smartphone : public Mobiles
{
public:
	Smartphone(string marca, string Nserie): Mobiles(marca, Nserie){}
	Mobiles* clone()
	{ 
		return new Smartphone(*this);
	}
};
class Smartwatch : public Mobiles
{
public:
	Smartwatch(string marca, string Nserie): Mobiles(marca, Nserie){}
	Mobiles* clone()
	{ 
		return new Smartwatch(*this);
	}
};
int main()
{
	Tablet* c1 = new Tablet("ffr","353");
}
