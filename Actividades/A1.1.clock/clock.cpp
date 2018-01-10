#include <iostream>
using namespace std;
class Clock
{
	private:
		static Clock* intance; 
		Clock()
		{
					
		}
	public:
		
		static Clock* getInstance()
		{
			if (intance == 0)
			{
				intance = new Clock;	
			}
			return intance;			
		}
		void getTime()
		{
			cout<<"son las 8"<< endl;
		}
	

};
Clock* Clock::intance=0;
int main()
{
	Clock* instance1 =Clock::getInstance();
	instance1->getTime();
	Clock* instance2 =Clock::getInstance();
	instance1->getTime();
	cout<<instance1<< endl;
	cout<<instance2<< endl;
	//Clock::getInstance();
	return 0;
}


