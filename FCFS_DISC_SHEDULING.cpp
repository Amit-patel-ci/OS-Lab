#include<bits/stdc++.h>
using namespace std;
int main(){

    int i,j,k,n,m,sum=0,h;
    cout<<"Enter the size of disk"<<endl;
    cin>>m;
    cout<<"Enter number of requests"<<endl;
    cin>>n;
    cout<<"Enter the requests"<<endl;


    vector <int> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"invalid position "<<a[i]<<endl;
            return 0;
        }
    }
    cout<<"Enter the head position"<<endl;
    cin>>h;
    
    int temp=h;
    cout<<temp;
    for(i=0;i<n;i++){
        cout<<" -> "<<a[i]<<' ';
        
        sum+=abs(a[i]-temp);
        temp=a[i];
    }
    cout<<endl;
    cout<<"Total head movements = "<< sum<<endl;
    return 0;
}
