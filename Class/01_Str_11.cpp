#include <bits/stdc++.h>
int main() {
    std::vector<char> s;
    int sum = 0;
    for(int i=0;i<12;i++){
        char c;
        std::cin >> c;
        sum+= (13-i)*(c - '0');
        s.push_back(c);
        if(i==0||i==4||i==9||i==11){
            s.push_back('-');
        }
    }
    s.push_back((11-sum%11)%10 + '0');
    for(char c:s){
        std::cout << c;
    }
}