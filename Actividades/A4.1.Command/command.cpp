#include <iostream>  
#include <string>  
using namespace std;
class Persona;

class Command
{
		Persona *object;  
		void(Persona:: *method)();
	public:
		Command(Persona *obj = 0, void(Persona:: *meth)() = 0)
		{
				object = obj; 
				method = meth;
		}
		void execute()
		{
				(object-> *method)();
		}
};

class Persona
{
		string name;

		
		Command cmd; 
	public:
		Persona(string n, Command c): cmd(c)
		{
				name = n;
		}
		void talk()
		{
				
				cout << name << " is talking" << endl;
				cmd.execute(); 
		}
		void passOn()
		{
				cout << name << " is passing on" << endl;
				cmd.execute(); 
		}
		void gossip()
		{
				cout << name << " is gossiping" << endl;
				cmd.execute();
		}
		void listen()
		{
				cout << name << " is listening" << endl;
		}
};

int main()
{

	Persona wilma("Wilma", Command());
	Persona betty("Betty", Command(&wilma, &Persona::listen));
	Persona barney("Barney", Command(&betty, &Persona::gossip));
	Persona fred("Fred", Command(&barney, &Persona::passOn));
	fred.talk();
}
