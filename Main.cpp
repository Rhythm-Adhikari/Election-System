#include "election.h"
#include <string>

int main(int argc, char**argv)
{
	if(argc<3)
	{
		cout<<"Please Provide Proper argument!!"<<endl;
		return -2;
	}
	else if((argv[1][0]-48)>=1 && (argv[1][0]-48)<=10 && (argv[2][0]-48)>=1 && (argv[2][0]-48)<=10)
	{
	election O(argv[1][0]-48,argv[2][0]-48,"election");
    O.startElection();
    }
    else
    {
    	cout<<"wrong input number"<<endl;
    	return -1;
    }




return 0;

}

