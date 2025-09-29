#include <bits/stdc++.h>
long long int cntt(long long int wo){
    long long int sum=1,k=9,cnt=1;
    if(k>=wo){
            sum+=wo*cnt;
            return sum;
    }
    while(wo>k){
        wo-=k;
        sum+=k*cnt;
        k*=10;
        cnt++;
        if(k>=wo){
            sum+=wo*cnt;
            return sum;
        }
    }
}
int main(){
    long long int a,b;
    std::cin>>a>>b;
    std::cout<<cntt(b)-cntt(--a);

} 