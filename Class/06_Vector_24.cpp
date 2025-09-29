#include <bits/stdc++.h>
using map_str_dou=std::map<std::string,double>;
map_str_dou de;
map_str_dou pr;
using pa=std::pair<std::string,double>;
using vec=std::vector<pa>;

void sr(map_str_dou ma){
    if(ma.size()==0){
        std::cout<<"No Sales";
    }
    vec v(ma.begin(),ma.end());
    std::sort(v.begin(),v.end(),[](auto &a,auto &b){
        return a.second>b.second;
    });
    int cnt=0;
    for(auto e=v.begin();e!=v.end()&&cnt<3;cnt++,e++){
        std::cout<<e->first<<" "<<e->second<<'\n';
    }    
    return;
}
int main(){
    std::string name="";
    double price;
    while(name!="END"){
        std::cin>>name;
        if(name!="END"){
            std::cin>>price;
            de[name]=price;
        }
    }
    std::cin.ignore();
    getline(std::cin,name);
    std::stringstream x(name);
    std::string h;
    //std::cout<<name<<'\n';
    while(x>>h){
        if(de.find(h)!=de.end()){
            pr[h]+=de[h];
        }
    }
    sr(pr);
    
}