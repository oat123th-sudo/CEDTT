#include <bits/stdc++.h>
std::vector<char> copyctos(std::string word){
    std::vector<char> w;
    for(int i=0;i<word.size();i++){
        w.push_back(word[i]);
    }
    return w;
}
std::string copytos(std::vector<char> w){
    std::string word="";
    for(int i=0;i<w.size();i++){
        word=word+w[i];
    }
    return word;
}
int main(){
    std::string word;
    std::cin>>word;
    std::vector<std::string> w;
    word=word+'$';
    std::vector<char> c=copyctos(word);
    w.push_back(word);
    for(int i=0;i<word.size()-1;i++){
        c.push_back(c[0]);
        c.erase(c.begin());
        w.push_back(copytos(c));
    }
    sort(w.begin(),w.end());
    for(int i=0;i<w.size();i++){
        std::cout<<w[i][w[i].size()-1];
    }
}