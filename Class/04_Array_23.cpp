#include <bits/stdc++.h>
int n,sum=0;
int sr(std::string a[],std::string t){
    for(int i=0;i<n;i++){
        if(a[i]==t){
            return i;
        }
    }
}
int main(){
    std::cin>>n;
    std::string c[n];
    int mo[n];
    std::cin.ignore();
    for(int i=0;i<n;i++){
        std::cin>>c[i]>>mo[i];
    }
    std::string line;
    std::cin.ignore();
    getline(std::cin,line);
    char o[2],ne[2]={line[4],line[5]};
    for(int i=4;i<line.size();i+=7){
        std::string t="";
        o[0]=ne[0];o[1]=ne[1];
        ne[0]=line[i];ne[1]=line[i+1];
        //std::cout<<line[i]<<line[i+1]<<" ";
        t+=ne[0];t+=ne[1];
        //std::cout<<t<<" ";
        if(ne[0]!=o[0]&&ne[1]!=o[1]){sum+=mo[sr(c,t)];}
        else{continue;}
    }
    std::cout<<sum;
}