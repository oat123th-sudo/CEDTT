#include <bits/stdc++.h>

int main(){
    int n,min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN;
    std::cin>>n;
    int i=1;
    while(i<=n){
        int x,y;
        std::cin>>x>>y;
        if(i%2==1){
            min1=std::min(min1,x);
            min2=std::min(min2,y);
            max1=std::max(max1,x);
            max2=std::max(max2,y);
        }
        else{
            min1=std::min(min1,y);
            min2=std::min(min2,x);
            max1=std::max(max1,y);
            max2=std::max(max2,x);
        }
        i++;
    }
    std::string a;
    std::cin>>a;
    if(a[1]=='i'){
        std::cout<<min1<<" "<<max2;
    }
    else{
        std::cout<<min2<<" "<<max1;
    }
}
