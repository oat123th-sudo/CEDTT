#include <bits/stdc++.h>

int main(){
    std::string num;
    std::cin>>num;
    if(num[0]=='0'){
        if(num[1]=='6'||num[1]=='8'||num[1]=='9'){
            if(num.size()==10){
                std::cout<<"Mobile number";
                return 0;
            }
        }
    }
    std::cout<<"Not a mobile number";
}