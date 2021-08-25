#include <iostream>
using namespace std;

int booblesort(int pro[],int Bt[], int At[],int n)
{
	int i,j,temp_pro,temp_Bt,temp_At;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(Bt[j]>Bt[j+1])
			{
				temp_At=At[j];
				At[j]=At[j+1];
				At[j+1]=temp_At;
				
				temp_pro=pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=temp_pro;
				
				temp_Bt=Bt[j];
				Bt[j]=Bt[j+1];
				Bt[j+1]=temp_Bt;
			}
		}
	}
}
int main()
{
int n,avg_tat=0,avg_wt=0,gt;
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
booblesort(pro,Bt,At,n);

gt=At[0];
for(int i =1;i<n;i++)
{gt=gt+Bt[i-1];
	if (gt>At[i])
	{ 
	wt[i]=gt-At[i];
	}
	else{
	wt[i]=0;
	gt=At[i];
	}
}
cout<<endl<<"gt : "<<gt<<endl;
for(int i =0;i<n;i++)
{
Tat[i]=Bt[i]+wt[i];
}
cout<<"pro   ,Tat   , Wt :"<<endl;
for(int i =0;i<n;i++)
{cout<<pro[i]<<"    , "<<Tat[i]<<"    , "<<wt[i]<<endl;
avg_tat=Tat[i]+avg_tat;
avg_wt=wt[i]+avg_wt;
}
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
cout<<"avg_tat : "<<avg_tat<<endl;
cout<<"avg_wt : "<<avg_wt<<endl;
return 0;
}
