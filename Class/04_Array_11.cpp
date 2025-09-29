#include <bits/stdc++.h>

int main(){
    int cnt=10;
    bool b[10];
    for(int i=0;i<10;i++){
        b[i]=1;
    }
    std::string num;
    getline(std::cin,num);
    for(int i=0;i<num.size();i++){
        if(num[i]>='0'&&num[i]<='9'&&b[num[i]-'0']==1){
            b[num[i]-'0']=0;
            cnt--;
        }
    }
    if(cnt==0){std::cout<<"None";return 0;}
    else{
        for(int i=0;i<10;i++){
            if(b[i]==1){std::cout<<i;cnt--;if(cnt!=0){std::cout<<",";}}
        }
    }
}