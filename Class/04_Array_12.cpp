#include <bits/stdc++.h>

int main(){
    int n,cnt=0;
    std::cin>>n;
    int y[n];
    for(int i=0;i<n;i++){
        std::cin>>y[i];
    }
    for(int i=0;i<n;i++){
        if(i!=0&&i!=n-1){
            if(y[i-1]<y[i]&&y[i+1]<y[i])cnt++;
        }
    }
    std::cout<<cnt;
}