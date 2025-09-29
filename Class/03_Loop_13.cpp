#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,ser,check1,check2;
    getline(cin,ser);
    getline(cin,s);
    int i,count = 0,j,nub = 0;
    for(i=0;i<s.length();i++){
        nub = 0;
        if(i!=0){
            check1 = s[i-1];
        }
        else {
            check1 = " ";
        }
        if(i!=s.length()-ser.length()){
            check2 = s[i+ser.length()];
        }
        else check2 = " ";
        for(j=0;j<ser.length();j++){
            if(s[i] == ser[j]){
                i++;
                nub += 1;
            }
            else break;
        }
        if(nub == ser.length()){
            if(check1=="("||check1==")"  ||check1==","  ||check1=="."  ||check1=="'"  ||check1==" "  ||check1=="\"") {
                if(check2 =="(" || check2==")"  ||check2=="," || check2=="." || check2=="'" || check2==" " || check2=="\""){
                    count+=1;
                    //cout<<"find at : "<<i - ser.length()<<endl;
                }

            }

        }
    }
    cout<<count;
}