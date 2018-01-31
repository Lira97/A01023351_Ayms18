#include <iostream>
using namespace std;
typedef int (*f)(int,int);

int suma (int a , int b)
	{
		return a+b;
	}
int duplica (int a )
	{
		return a*2;
	}
int resta (int a , int b)
	{
		return a-b;
	}

f getOperacion(char operacion)
	{
		
		if (operacion == 'r')return resta;
		else return suma;
	}

int (*getf(char s))(int a,int b)
	{
		if (s == 'r')return resta;
			else return suma;
	}
int operacion (int a ,int b ,int (*f)(int,int))
	{
		return f(a,b);
	}
	
template <class T,class Function >
	T doTemplateFunction(T a,T b,Function f)
	{
		return f(a,b);
	} 

template <class Function >
Function getTemplateOperation(char s)
	{
		if (s == 'r')return resta;
		else return suma;
	} 

int main() 
	{
		cout << operacion(2,2,suma)<<endl;
		cout << operacion(4,2,resta)<< endl;
		cout << getOperacion('s')(2,2)<< endl;
		cout << getf('s')(2,2)<< endl;
		
		cout << doTemplateFunction(2,2,resta)<< endl;
		cout << getTemplateOperation<int(*)(int,int)>('s')(2,2)<< endl;
		
	}