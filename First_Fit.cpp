#include<iostream>
using namespace std;
int main()
{
	int blocks,process,blocksize[blocks],processize[process],allocation[process];
	cout<<"enter no. of process :";
	cin>>process;
	cout<<"enter process size "<<endl;
	for(int i=0;i<process;i++)
	{allocation[i]=-1;
	cout<<"enter size of process "<<i<<" : ";
	cin>>processize[i];
	}
	
	cout<<endl<<"enter no. of blocks :";
	cin>>blocks;
	cout<<"enter block size "<<endl;
	for(int i=0;i<blocks;i++)
	{cout<<"enter size of blocks "<<i<<" : ";
	cin>>blocksize[i];
	}
	
	for(int i=0;i<process;i++)
	{for(int j=0;j<blocks;j++)
		{
			if(blocksize[j]>=processize[i])
			{
				blocksize[j]=blocksize[j]-processize[i];
				allocation[i]=j;
				break;
			}
		}	
	}
	cout<<endl;
	for(int i=0;i<process;i++)
	{
		if(allocation[i]!=-1)
		{cout<<"process "<<i<<" is stored at "<<allocation[i]<<" block"<<endl;
		}
		else
		{cout<<"process "<<i<<" is not allocated "<<endl;
		}
	}
		
}
