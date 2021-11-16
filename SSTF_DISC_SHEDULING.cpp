#include<bits/stdc++.h>
using namespace std;
int main(){

    int i,j,k,n,m,TotalHeadMoment=0,initial,count=0;
    cout<<"Enter the size of disk"<<endl;
    cin>>m;
    cout<<"Enter number of requests"<<endl;
    cin>>n;
    cout<<"Enter the requests"<<endl;

    vector <int> RQ(n);
    for(i=0;i<n;i++){
        cin>>RQ[i];
    }
    for(i=0;i<n;i++){
        if(RQ[i]>m){
            cout<<"invalid position "<<RQ[i]<<endl;
            return 0;
        }
    }
    cout<<"Enter the head position"<<endl;
    cin>>initial;
    
     while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }   
        }
        TotalHeadMoment=TotalHeadMoment+min;
        initial=RQ[index];
        
        RQ[index]=1000;
        count++;
    }
    cout<<endl;
    cout<<"Total head movements = "<<TotalHeadMoment<<endl;
    return 0;
}

