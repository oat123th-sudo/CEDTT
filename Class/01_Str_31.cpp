#include <bits/stdc++.h>
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    std::string a,b,c;
    std::cin>>a>>b>>c;
    int sum=0;
    for(int i=0;i<c.size();i++){sum=sum*10+9;}
    for(int i=0;i<b.size();i++){sum=sum*10;}
    long long ra=stoll(a),rb=stoll(b),rc=stoll(c),up;
    up=rb*pow(10,c.size())+rc-rb;
    long long g=gcd(up,sum);
    up /=g;
    sum /=g;
    up +=ra*sum;
    std::cout<<up<<" / "<<sum;
}