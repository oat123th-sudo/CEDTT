#include <bits/stdc++.h>
std::map<int,int> qq;
int main(){
    std::string com;
    int n;
    std::cin>>n;
    bool ccom=0;
    int start,i=0,ltime,tic,to,cnt=0;
    double st=0;
    while(n--){
        std::cin>>com;
        if(com=="reset"&&ccom==0){
            ccom=1;
            std::cin>>start;
            tic=start;
        }
        else if(com=="new"){
            std::cin>>ltime;
            std::cout<<">> ticket "<<tic<<'\n';
            qq[tic]+=ltime;
            tic++;
        }
        else if(com=="next"){
            std::cout<<">> call "<<start<<'\n';
            start++;
        }
        else if(com=="order"){
            std::cin>>to;
            std::cout<<">> qtime "<<start-1<<" "<<to-qq[start-1]<<'\n';
            st+=double(to-qq[start-1]);
            cnt++;
        }
        else{
            if(com=="avg_qtime"){
                std::cout<<">> avg_qtime "<<(st*100)/100.0/double(cnt)<<'\n';
            }
        }
    }
}