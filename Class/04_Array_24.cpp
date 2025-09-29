#include <bits/stdc++.h>
using namespace std;

void flip(int size,int ar[],int n,int t){
    int temp[size];
    if(n!=0){
        for(int i=0;i<size;i++) temp[i]=ar[i];
        for(int i=0;i<=n;i++){
            ar[i]=temp[n-i];
        }
        for(int i=0;i<size;i++) cout<<ar[i]<<" ";
        cout<<'\n';
    }
    for(int i=0;i<size;i++) temp[i]=ar[i];
    for(int i=0;i<t;i++){
        ar[i]=temp[t-(i+1)];
        //cout<<"this"<<temp[size-(i+1)]<<" ";
    }
    for(int i=0;i<size;i++) cout<<ar[i]<<" ";
    cout<<'\n';
}

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    //flip(n,ar,2);
    for(int i=0;i<n;i++) cout<<ar[i]<<" ";
    cout<<'\n';
    int mx=INT_MAX,use;
    for(int i=n;i>0;i--){
        int now=-1;
        for(int j=0;j<n;j++){
            if(ar[j]<mx and ar[j]>now){
                now=ar[j];
                use=j;
            } 
        }
        mx=now;
        if(use!=i-1) flip(n,ar,use,i);

    }
}
