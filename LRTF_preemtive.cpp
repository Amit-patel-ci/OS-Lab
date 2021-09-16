//LRTF preemtive
#include <iostream>
using namespace std;

int max(int Btemp[],int Pk[],int n)
{
	int i=0,max_i=Pk[0],max_v=Btemp[Pk[0]];
	for(i=1;i<=n;i++)
	{
		if(max_v<Btemp[Pk[i]])
		{
			max_v=Btemp[Pk[i]];
			max_i=Pk[i];
		}
	}
	return max_i;
}
int main()
{
int n,gt,i;
float avg_tat=0,avg_wt=0;
cout<<"enter no. of proccess: ";
cin>>n;
int pro[n],At[n],Bt[n],Btemp[n],wt[n],Tat[n];
wt[0]=0;
for(i =0;i<n;i++)
{
pro[i]=i;
cout<<"enter arival , brust time of process "<<i<<endl;
cin>>At[i]>>Bt[i];
Btemp[i]=Bt[i];
}

gt=0;
for(i =1;i<=n;i++)
{ 
   if(At[i-1]>gt)
   {
   	gt=At[i-1]+Bt[i-1];
   }
   else
   {
	gt=gt+Bt[i-1];
	}
}

cout<<endl<<"gt : "<<gt<<endl;
int gtq[gt];
i=0;
while(i<gt)
{
	int m=-1,k,Pk[n];
	cout<<"process at every unit :";
		for(k=0;k<n;k++)
		{
			if(At[k]<=i && Btemp[k]!=0)
			{
				m++;
				Pk[m]=k;
			}
		}
		
	for(int j=0;j<=m;j++){
		cout<<Pk[j]<<" ";
	}cout<<endl;
	
	if(m==-1)
	{
		gtq[i]=-1;
		i++;
	}
	else if(m==0)
	{
		Btemp[Pk[0]]=Btemp[Pk[0]]-1;
		gtq[i]=Pk[0];
		i++;
	}
	else{
       int max_i= max(Btemp,Pk,m);
      Btemp[max_i]=Btemp[max_i]-1;
      gtq[i]=max_i;
	  i++;
	}
}

cout<<"gentt chart : ";
for(i =0;i<gt;i++)
{
cout<<gtq[i]<<" ";
}

for(i=0;i<n;i++)
{int temp;
	for(int j=0;j<gt;j++)
	{
		if(gtq[j]==i)
		{
			temp=j;
		}
	}
	Tat[i]=(temp+1)-At[i];
	wt[i]=Tat[i]-Bt[i];
}

cout<<endl<<"pro ,Tat , Wt :"<<endl;

for(int i =0;i<n;i++)
{cout<<pro[i]<<" , "<<Tat[i]<<" , "<<wt[i]<<endl;
avg_tat=Tat[i]+avg_tat;
avg_wt=wt[i]+avg_wt;
}
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
cout<<"avg_tat : "<<avg_tat<<endl;
cout<<"avg_wt : "<<avg_wt<<endl;
return 0;
}
