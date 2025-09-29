#include <bits/stdc++.h>

int main(){
    int ar[2],m1=INT_MIN,m2=INT_MIN,mi1=INT_MAX,mi2=INT_MAX,i=1;
    while(i++){
        std::cin>>ar[0];
        if(ar[0]==-998){
            std::cout<<mi1<<" "<<m2;
            return 0;
        }
        if(ar[0]==-999){
            std::cout<<mi2<<" "<<m1;
            return 0;
        }
        std::cin>>ar[1];
        //std::cout<<i<<"\n";
        if(i%2==0){
            if(ar[0]>m1){
                m1=ar[0];
            }
            if(ar[0]<mi1){
                mi1=ar[0];
            }
            if(ar[1]>m2){
                m2=ar[1];
            }
            if(ar[1]<mi2){
                mi2=ar[1];
            }
        }
        else{
            if(ar[1]>m1){
                m1=ar[1];
            }
            if(ar[1]<mi1){
                mi1=ar[1];
            }
            if(ar[0]>m2){
                m2=ar[0];
            }
            if(ar[0]<mi2){
                mi2=ar[0];
            }
        }
    }
}