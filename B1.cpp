#include<iostream>
using namespace std;
void first_fit();
void best_fit();
void worst_fit();
int main()
{
	int c;
	cout<<"Mapping of processes with memory partitions."<<endl;
	cout<<"Enter the algorithm number:"<<endl;
	cout<<"1. First fit"<<endl<<"2. Best fit"<<endl<<"3. Worst fit"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			first_fit();
			break;
		case 2:
			best_fit();
			break;
		case 3:
			worst_fit();
			break;
		default:
			printf("No such option available.....!!!!")			
	}
}
