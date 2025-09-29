#include <bits/stdc++.h>

int main(){
    int cnt=0;
    std::string a,b;
    getline(std::cin,a);
    getline(std::cin,b);
    if(a.size()==b.size()){
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]){cnt++;}
        }
    }
    else{std::cout<<"Incomplete answer";return 0;}
    std::cout<<cnt;
}