#include <iostream>
using namespace std;

template<int n>
class Repeat : public Repeat <n-1>
{
	public:
		Repeat()
		{
			
			cout << n<<endl;
		}	
};
template<>
class Repeat <0>
{
	public:
		Repeat()
		{
			cout << "0"<<endl;
		}	
};

int main() 
{
	Repeat<100> r ;
}