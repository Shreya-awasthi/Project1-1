#include<iostream>
using namespace std;
int min_at(int at[],int n)
{
	int index;
	int temp = at[0];
	for(int i=0; i<n; i++) 
	{
		if(temp>at[i]) 
		{
        	temp=at[i];
        	index =i;
      	}
   	}
   return index;
}
int min_at2(int at[],int n,int ind)
{
	int smallest, secondSmallest;
   	if(at[0]<at[1])
	{
      	smallest = at[0];
      	secondSmallest = at[1];
      	index =1;
   	}
   	else 
	{
      	smallest = at[1];
      	secondSmallest = at[0];
      	index =0;
   	}
   	for(int i=0; i<n; i++) 
	{
      	if(smallest>at[i]) 
		{ 
         	secondSmallest = smallest;
         	smallest = at[i];
         	index=i;
      	}
      	else if(at[i] < secondSmallest)
		{
         	secondSmallest = at[i];
         	index=i;
      	}
  	}	
   }
   return index;
}
int main()
{
	int pro,i,at[10],bt[10];
	cout<<"Enter number of processes:\n";
	cin>>pro;
	cout<<"Enter arrival time for all processes:\n";
	for(i=0;i<pro;i++)
	{
		cin>>at[i];
	}
	for(i=0;i<pro;i++)
	{
		cout<<"Arrival time for process P"<<i<<" is: "<<at[i]<<endl;
	}
	cout<<"Enter burst time for all processes:\n";
	for(i=0;i<pro;i++)
	{
		cin>>bt[i];
	}
	for(i=0;i<pro;i++)
	{
		cout<<"Burst time for process P"<<i<<" is: "<<bt[i]<<endl;
	}
	
	
	//Round robin for 3 units 
	cout<<"After applying interruption after 3 time units for one process:\n";
	int res=min_at(at,pro);
	for(i=0;i<pro;i++)
	{
		if(i==res)
		{
			bt[i]=bt[i]-3;
			
		}
		cout<<"Burst time for process P"<<i<<" is: "<<bt[i]<<endl;
	}
	
	
	//Round robin for 6 units
	cout<<"After applying interruption after 6 time units for one process:\n";
	int res2=min_at2(at,pro,res);
	for(i=0;i<pro;i++)
	{
		if(i==res2)
		{
			bt[i]=bt[i]-6;
		}
		cout<<"Burst time for process P"<<i<<" is: "<<bt[i]<<endl;
	}
	
	
	cout<<endl<<"After 3 and 6 burst time is:\n"<<endl<<endl;
	for(int i=0;i<pro;i++)
	{
		cout<<"Burst time for process P"<<i<<" is: "<<bt[i]<<endl;
	}
}
