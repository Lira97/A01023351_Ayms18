#include <iostream>
using namespace std;
class Clock
{
	private:
		static Clock* intance;  
		~Clock(){}
		Clock(){}
	public:
		static Clock* deleteIntance()
		{
			if (intance != NULL)
			{
				 delete intance; 
				intance = NULL;	
			}
			return intance;	
 
		}
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
			char datetime[30];
			time_t current_time = time(NULL);
			ctime(&current_time);
			strcpy(datetime, ctime(&current_time));
			cout << "Hora actual: " << datetime;
		}
	

};
Clock* Clock::intance=0;
int main()
{
	Clock* instance1 =Clock::getInstance();
	instance1->getTime();
	instance1->deleteIntance();
	return 0;
}


