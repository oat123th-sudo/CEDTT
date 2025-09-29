#include <bits/stdc++.h>

int main(){
    std::string word;
    int cnt=0,wc=0;
    std::cin>>word;
    for(int i=0;i<word.size();i++){
        if(word[i]>='A'&&word[i]<='Z'&&i!=0){
            cnt=0;
            std::cout<<", ";
            wc++;
        }
        else if(word[i]>='0'&&word[i]<=char('9')){
            //std::cout<<bool(word[i]>='0')<<bool(word[i]<='9')<<bool(cnt==0)<<'\n';
            //std::cout<<"\""<<word[i]<<"\"";
            if(cnt==0&&i!=0&&wc!=0){
                std::cout<<", ";
                cnt++;
            }
        }
        else{
            /*if(word[i]>='0'&&word[i]<=char('9')){
                std::cout<<"1\""<<word[i]<<"\"1";
            }*/
           if(cnt!=0){
            std::cout<<", ";
           }
            cnt=0;
            wc++;
        }
        std::cout<<word[i];
    }
}