#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Observer
{
	public:
    	virtual void publica(string anuncio) = 0;
};

class Mvs : public Observer
{
	private:
		string noticiero;
	public:	
		Mvs(string n){ noticiero = n; }
    	void publica(string anuncio)
		{
    		cout << "- Noticieros " << noticiero << ": " << anuncio << endl;
    	}       
};

class Televisa : public Observer
{
	private:
		string noticiero;

	public:
		Televisa(string n){ noticiero = n; }
    	void publica(string anuncio)
		{
    		cout << "- Noticieros " << noticiero << ": " << anuncio << endl;
    	}          
};

class Azteca : public Observer
{
	private:
		string noticiero;

	public:
		Azteca(string n){ noticiero = n; }
    	void publica(string anuncio)
		{
    		cout << "- Noticieros " << noticiero << ": " << anuncio << endl;
    	}
};

class Subject{
   vector<Observer*> list;

public:
	Subject() {};
    void Attach(Observer* observer)
	{
    	list.push_back(observer);
    }
    
	void Detach(Observer* observer)
	{
		for(int i = 0; list.size()>i; i++)
		{
			if (list[i] == observer)
			{
        	list.erase (list.begin()+i);
			break;
			}
		 }
	}
		
    void notifyAll(string anuncio)
	{
    	for(int i = 0; list.size()>i; i++)
		{
        	list[i]->publica(anuncio);
        }
    }
};

class Trump : public Subject
{
	public:
		Trump(){};
	    void Anuncia(string anuncio)
		{
	    	notifyAll(anuncio);
	    }
};

class Anaya : public Subject
{
	public:
		Anaya(){};
	    void Anuncia(string anuncio)
		{
	    	notifyAll(anuncio);
	    }
};

class Meade : public Subject
{
	public:
		Meade(){};
	    void Anuncia(string anuncio)
		{
	    	notifyAll(anuncio);
	    }
};
class Zabala : public Subject
{
	public:
		Zabala(){};
	    void Anuncia(string anuncio)
		{
	    	notifyAll(anuncio);
	    }
};
class AMLO : public Subject
{
	public:
		AMLO(){};
	    void Anuncia(string anuncio)
		{
	    	notifyAll(anuncio);
	    }
};

int main(){
	// Observers
	Mvs* mvs = new Mvs("MVS");
	Televisa* televisa = new Televisa("Televisa");
	Azteca* azteca = new Azteca("Azteca");
	

	// Subjects
	Trump* trump = new Trump();
	Anaya* anaya = new Anaya();
	Meade* meade = new Meade();
	Zabala* zabala = new Zabala();
	AMLO* amlo = new AMLO();


	// Relación pres-televisoras
	trump->Attach(mvs);
	trump->Attach(televisa);
	trump->Attach(azteca);
	
	meade->Attach(mvs);
	meade->Attach(televisa);
	meade->Attach(azteca);
	
	zabala->Attach(mvs);
	zabala->Attach(televisa);
	zabala->Attach(azteca);
		
	anaya->Attach(televisa);
	anaya->Attach(azteca);
	anaya->Attach(mvs);
	
	amlo->Attach(mvs);
	amlo->Attach(televisa);
	amlo->Attach(azteca);

	// Notificaciones - Actualizaciones
	cout << endl << "DONALD TRUMP" << endl;
	trump->notifyAll("We need to build the Wall.");

	cout << endl << "ANAYA" << endl;
	anaya->notifyAll("Esas son puras metiras");

	cout << endl << "MEADE" << endl;
	meade->notifyAll("Esa noshe yo no andaba ahi");
	cout << endl;
	
	cout << endl << "Zabala" << endl;
	zabala->notifyAll("Debes de estar confundida ");
	cout << endl;
	
	cout << endl << "AMLO" << endl;
	amlo->notifyAll("O era un tipo igualito a mi ");
	cout << endl;
	
	amlo->Detach(azteca);
	
	
	return 0;
}
