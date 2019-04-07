#include<iostream>
using namespace std;

void first_fit(int mem[],int mp,int pro[],int p)
{
	int count[10],rem[10];
	for(int k = 0; k < 10; k++)
	{
		count[k] = 0;
		rem[k] = -1;
	}
	for(int i = 0; i < p; i++)
	{
		for(int j = 0; j < mp; j++)
			if(count[j] == 0 && mem[j] >= pro[i])
			{
				rem[j] = i;
				count[j] = 1;
				break;
			}
	}
	cout<<endl<<"Process\t\tMemory partition";
	for(int i = 0; i < mp; i++)
	{
		cout<<endl<<mem[i]<<"\t";
		if(count[i] == 1)
			cout<<"\t"<<pro[rem[i]];		
		else
			cout<<"\tCan't map";
	}
}
void best_fit(int mem[],int mp,int pro[],int p)
{
	int rem[10]; 
    for (int i=0; i<p; i++) 
    { 
        int count = -1; 
        for (int j=0; j<mp; j++) 
        { 
            if (mem[j] >= pro[i]) 
            { 
                if (count == -1) 
                    count = j; 
                else if (mem[count] > mem[j]) 
                    count = j; 
            } 
        } 
  
        if (count != -1) 
        { 
            rem[i] = count;  
            mem[count] =mem[count]-pro[i]; 
        } 
    } 
  
    cout << "\n\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < p; i++) 
    { 
        cout <<"\t" << pro[i]<< "\t\t"; 
        if (rem[i] != -1) 
            cout << rem[i]+1 ; 
        else
            cout << "Can't map."; 
        cout << endl; 
    } 
}
int main()
{
	int c;
	int mem[]={100,500,200,300,600};
	int pro[]={212,417,112,426};
	int mp=sizeof(mem)/sizeof(mem[0]);
	int p=sizeof(pro)/sizeof(pro[0]);
		cout<<"\t\t~~~~~~~~~~~~~~~~~~~~~ Mapping of processes with memory partitions ~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	for(int i=0;i<mp;i++)
	{
		cout<<"Size of Memory partition "<<i+1<<" is "<<mem[i]<<endl;
	}
	for(int i=0;i<p;i++)
	{
		cout<<"Size of process "<<i+1<<" is "<<pro[i]<<endl;
	}
	cout<<"Enter the algorithm number:"<<endl;
	cout<<"1. First fit"<<endl<<"2. Best fit"<<endl<<"3. Worst fit"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			first_fit(mem,mp,pro,p);
			break;
		case 2:
			best_fit(mem,mp,pro,p);
			break;
		/*case 3:
			worst_fit(mem,mp,pro,p);
			break;*/
		default:
			printf("No such option available.....!!!!");			
	}
}
