#include <bits/stdc++.h>

int main(){
    double n,cnt=0;
    std::cin>>n;
    for(int i=1;i<=3;i++){
        if(n>=1000){
            for(int j=1;j<=3;j++){
                if(n<99){n=n/10.0;break;}
                n=round(n/10.0);
          }
          cnt++;
        }
    }
    std::cout<<n;
    if(cnt==1){std::cout<<"K";}
    else if(cnt==2){std::cout<<"M";}
    else if(cnt==3){std::cout<<"B";}
}