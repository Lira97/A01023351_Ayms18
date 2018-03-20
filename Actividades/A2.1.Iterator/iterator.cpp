 #include <iostream>
using namespace std;

class IntCollection;

class Iterator
{
protected:
	IntCollection* collection;
	int cont;
public:
	virtual int next()=0;
	virtual bool hasnext()=0;
};

class IntCollection
{
	public:
		virtual void add(int element)=0;
		virtual int at(int position)=0;
		virtual Iterator* getIterator()=0;
		virtual int getNumElements()=0;
		
};
class IntArray;
class ArrayIterator : public Iterator
{
	public:
		ArrayIterator(IntArray* intArray)
		{
			collection = (IntCollection*)intArray;
			cont=0;
		}
		int next()
		{
			return collection->at(cont++);
		}
		bool hasnext()
		{
			if(cont >=  collection->getNumElements())
			{
				return false;
			}
			return true;
		}
};
class IntArray : public IntCollection
{	
	protected:
	int* array;
	int size;
	int numElems;
	public:
		
		IntArray()
		{
			size =10;
			array =new int[10];
			numElems = 0;
		}
		void add(int element)
		{
			if(numElems >= size)
			{
				cout<<"sin espacio"<<endl;
				return;
			}
			array[numElems++]=element;
		}
		int at(int position)
		{
			if (size<=position<0)
			{
				cout<<"indice no valido"<<endl;
				throw "out_of_range";
			}
			return array[position];
		}
		Iterator* getIterator()
		{
			return new ArrayIterator(this);
		}
		int getNumElements()
		{
			return numElems;
		}
};

int main() 
{
	IntCollection* c = new IntArray;
	c->add(6);	
	c->add(8);	
	c->add(1);	
	c->add(2);	
	c->add(5);
	
	Iterator* i = c->getIterator();
	while(i->hasnext())
	{
		cout<< i->next()<<" ";
	}
		
}
