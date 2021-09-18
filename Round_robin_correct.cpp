//round robin
#include <iostream>
using namespace std;

int main()
{
int n,gt,i,quantum;
float avg_tat=0,avg_wt=0;
cout<<"enter no. of proccess: ";
cin>>n;
int pro[n],At[n],Bt[n],Btemp[n],wt[n],Tat[n];
wt[0]=0;
cout<<"enter time quantum for proccess :";
cin>>quantum;
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
int gtq[gt],m=-1,s=0,rq[gt];
i=0;
while(i<gt)
{
	int k;
	cout<<"process in ready queue :";
		if(i==0)
		{
		for(k=0;k<n;k++)
		{
			if(At[k]==i && Btemp[k]!=0)
			{
				m++;
				rq[m]=k;
			}
		}
		}
		
	for(int j=s;j<=m;j++){
		cout<<rq[j]<<" ";
	    } 
	cout<<endl;
	
	if(m==-1 || m<s)
	{
		gtq[i]=-1;
		i++;
		for(k=0;k<n;k++)
			{
			if(At[k]==i && Btemp[k]!=0)
			{m++;
			rq[m]=k;}
			}
	}
	else{int ut=0;
			while(ut<quantum && Btemp[rq[s]]!=0)
			{
			 Btemp[rq[s]]=Btemp[rq[s]]-1;
      		 gtq[i]=rq[s];
	   		 i++;
			 
			 if(ut<quantum)
			 {
			 for(k=0;k<n;k++)
				{
					if(At[k]==i && Btemp[k]!=0)
						{
							m++;
							rq[m]=k;}
						}
				}
				ut++;
			}
	        if (Btemp[rq[s]]!=0)
        	{
	        	m++;
	         	rq[m]=rq[s];
	        	s++;
	        }
	        else
        	{	s++;
	        }	
	     }
	
	int count=0;
    for(k=0;k<n;k++)
	{
	    if(Btemp[k]==0)
			{
				count++;
			}
	}
	
	if(count==n)
	{for (int it=i;it<gt;it++)
	 {gtq[it]=-1;}
	    break;}

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
