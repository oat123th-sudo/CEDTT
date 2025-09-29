#include <bits/stdc++.h>
int cntw[40];

int main(){
    std::string word;
    getline(std::cin,word);
    for(int i=0;i<word.size();i++){
        char a=tolower(word[i]);
        if(a>='a'&&a<='z'){
            cntw[a-'a']++;
        }
    }
    for(int i=0;i<40;i++){
        if(cntw[i]>0){
            std::cout<<char('a'+i)<<" -> "<<cntw[i]<<"\n";
        }
    }
}