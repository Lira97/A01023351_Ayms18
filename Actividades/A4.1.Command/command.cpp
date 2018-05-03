#include <iostream>

using namespace std;

class Command {
public:
	virtual void execute() = 0;
};

class Receiver {
public:
	void Funcion1() {
		cout << "funcion1";
	}
	void Funcion2() {
		cout << "funcion2";
	}
};

class Caller {
public:
	void setCommand(Command *com) {
		my_cmd = com;
	}
	void executeAction() {
		my_cmd->execute();
	}
private:
	Command *my_cmd;
};

class ConcreteCommand1 : public Command {
public:
	ConcreteCommand1(Receiver *rev) : r(rev) { }
	void execute() {
		r -> Funcion1();
	}
private:
	Receiver *r;
};

class ConcreteCommand2 : public Command {
public:
	ConcreteCommand2(Receiver *rev) : r(rev) { }
	void execute() {
		r -> Funcion2();
	}
private:
	Receiver *r;
};

// Invoker
int main() {
	Receiver *r = new Receiver;
	
	ConcreteCommand1 *c1 = new ConcreteCommand1(r);
	ConcreteCommand2 *c2 = new ConcreteCommand2(r);
	
	Caller *c = new Caller;
	
	c->setCommand(c1);
	c->executeAction();
	c->setCommand(c2);
	c->executeAction();
	
	return 1;
}