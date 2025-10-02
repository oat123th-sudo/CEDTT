#include <bits/stdc++.h>
using mi=std::map<std::string,long long int>;
using md=std::map<std::string,double>;
using v=std::vector<std::pair<std::string,double>>;
using vaa=std::vector<std::pair<std::pair<std::string,long long int>,double>>;
using va=std::pair<std::pair<std::string,long long int>,double>;
using vh=std::pair<std::string,double>;
v h;
mi mp;
md mpd;

bool cmp(const vh &a,const vh &b){
    return a.second>b.second;
}
bool cmpp(const va &a,const va &b){
    return a.first.second>b.first.second;
}
void ss(){
    vaa vec;
    for(auto e=mpd.begin();e!=mpd.end();e++){
        va p={{e->first,mp[e->first]},floor(e->second)};
        vec.push_back(p);
    }
    std::sort(vec.begin(),vec.end(),cmpp);
    for(int i=0;i<vec.size();i++){
        if(vec[i].second==0){continue;}
        std::cout<<vec[i].first.first<<" "<<vec[i].second<<" "<<vec[i].first.second<<'\n';
    }
}
int main(){
    double sum;
    std::string name;
    while(std::cin>>name){
        if(name=="END"){
            sum=sum/100;
            //std::cout<<"sum = "<<sum<<'\n';
            for(auto e=mp.begin();e!=mp.end();e++){
                mpd[e->first]=round(e->second*10000/sum)/10000;
                /*if(e->first=="EE"){
                    std::cout<<e->second<<'\n';
                    }*/
            }
            //std::cout<<mpd["EE"]<<'\n';
            break;
        }
        long long int x;
        std::cin>>x;
        sum+=x;
        mp[name]+=x;
    }
    sum=0;
    for(auto e=mpd.begin();e!=mpd.end();e++){
        //std::cout<<e->first<<" "<<e->second<<'\n';
        sum+=e->second-floor(e->second);
        h.push_back({e->first,e->second-floor(e->second)});
    }
    //std::cout<<'\n';
    sort(h.begin(),h.end(),cmp);
    for(int i=0;i<h.size();i++){
        //std::cout<<h[i].first<<" "<<h[i].second<<" + "<<sum<<" ";
        if(h[i].second+sum>=1){
            double x=1-h[i].second;
            sum-=x;
            h[i].second=1;
            //std::cout<<x<<" ";
        }
        sum-=h[i].second;
        //std::cout<<h[i].second<<'\n';    
    }
    for(int i=0;i<h.size();i++){
        std::string nn=h[i].first;
        if(h[i].second==1.0){
            mpd[nn]+=1;
            //std::cout<<nn<<'\n';
        }
        //std::cout<<h[i].first<<" "<<h[i].second<<'\n';
    }
    /*for(int i=0;i<h.size();i++){
        std::cout<<h[i].first<<" "<<h[i].second<<" ";
        if(h[i].second==1){std::cout<<"true";}
        std::cout<<'\n';
    }*/
    /*for(auto e=mpd.begin();e!=mpd.end();e++){
        std::cout<<e->first<<" "<<floor(e->second)<<'\n';
    }*/
    ss();
}