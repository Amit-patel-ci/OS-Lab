#include <iostream>
using namespace std;
int main()
{
	int n,avg_tat=0,avg_wt=0;
	cout<<"enter no. of proccess: ";
	cin>>n;
	int pro[n],At[n],Bt[n],wt[n],Tat[n];
	wt[0]=0;
	for(int i =0;i<n;i++)
	{
		pro[i]=i;
		cout<<"enter arival and brust time of process "<<i<<endl;
		cin>>At[i]>>Bt[i];
	}
	
	for(int i =1;i<n;i++)
	{
	wt[i]=Bt[i-1]+wt[i-1];
	}
	
	for(int i =0;i<n;i++)
	{
	Tat[i]=Bt[i]+wt[i];
	}
	cout<<"Tat , Wt :"<<endl;
	for(int i =0;i<n;i++)
	{cout<<Tat[i]<<" , "<<wt[i]<<endl;
	avg_tat=Tat[i]+avg_tat;
	avg_wt=wt[i]+avg_wt;
	}
	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;
	cout<<"avg_tat : "<<avg_tat<<endl;
	cout<<"avg_wt : "<<avg_wt<<endl;
	return 0;
}
