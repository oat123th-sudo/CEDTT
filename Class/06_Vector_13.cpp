#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
    vector<string> word;
    string w="";
    for(int i=0;i<line.size();i++){
        if(line[i]!=delimiter){
            w=w+line[i];
        }
        else{
            if(w!=""){
                word.push_back(w);
            }
            w="";
        }
    }
    if(w!=""){
        word.push_back(w);
    }
    return word;
}
int main() {
 string line;
 getline(cin, line);
 string delim;
 getline(cin, delim);
 for (string e : split(line, delim[0])) {
 cout << '(' << e << ')';
 }
}
