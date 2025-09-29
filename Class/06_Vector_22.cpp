#include <bits/stdc++.h>
std::vector<std::pair<int,std::pair<int,int>>> num;
int main(){
    int n,cnti=0,cnt=0,mx=0,mxcnt=1;
    std::vector<int> ne;
    while(std::cin>>n){
        ne.push_back(n);
        cnti++;
    }
    cnt=1;
    for(int i=1;i<ne.size();i++){
       if(ne[i]==ne[i-1]){
        cnt++;
       }
       else{
        num.push_back({ne[i-1],{i-cnt,i}});
        mxcnt=std::max<int>(mxcnt,cnt);
        cnt=1;
       }
       if(i==ne.size()-1){
        num.push_back({ne[i],{i-cnt+1,i+1}});
        mxcnt=std::max<int>(mxcnt,cnt);
       }
    }
    sort(num.begin(),num.end());
    for(auto e=num.begin();e!=num.end();e++){
        if(e->second.second-e->second.first==mxcnt){
           std::cout<<e->first<<" --> x[ "<<e->second.first<<" : "<<e->second.second<<" ]"<<'\n';
        }
    }
}