#include <bits/stdc++.h>
long long int Fac(int a){
    long long int sum=1;
    a++;
    while(a--){
        if(a!=0){
            sum*=a;
        }
    }
    return sum;
}
int main(){
    std::cout<<(M_PI-Fac(10)/pow(8,8)+pow(log(9.7),7/sqrt(71)-sin(40*M_PI/180)))/pow(1.2,cbrt(2.3));

}