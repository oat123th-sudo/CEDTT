#include <bits/stdc++.h>
int rp(char a){
    if(a=='R')return 1;
    if(a=='Y')return 2;
    if(a=='G')return 3;
    if(a=='N')return 4;
    if(a=='B')return 5;
    if(a=='P')return 6;
    if(a=='K')return 7;
}
int po(std::string a){
    int p=0,cnt=0;
    if(a[0]=='Y'&&a.size()==1){return -1;}
    for(int i=0;i<a.size();i+=2){
        if(cnt==6)return -1;
        if(cnt==0&&i==a.size()-1&&a[i]=='R'){
            p+=rp(a[i]);
            return p;
        }
        if(cnt==0&&a[i]=='R'&&a[i+2]!='R'){
            p+=rp(a[i]);
            i+=2;
            p+=rp(a[i]);
            
        }
        else if(cnt==0&&a[i]=='Y'){
            cnt++;
            p+=rp(a[i]);
        }
        else if(cnt==1&&a[i]=='G'){
            cnt++;
            p+=rp(a[i]);
        }
        else if(cnt==2&&a[i]=='N'){
            cnt++;
            p+=rp(a[i]);
        }
        else if(cnt==3&&a[i]=='B'){
            cnt++;
            p+=rp(a[i]);
        }
        else if(cnt==4&&a[i]=='P'){
            cnt++;
            p+=rp(a[i]);
        }
        else if(cnt==5&&a[i]=='K'){
            cnt++;
            p+=rp(a[i]);
        }
        else{return -1;}
    }
    return p;
}
int main(){
    int n;
    std::cin>>n;
    std::string a;
    std::vector<int> rub;
    for(int i=0;i<=n;i++){
        getline(std::cin,a);
        rub.push_back(po(a));
    }
    for(int i=1;i<rub.size();i++){
        if(rub[i]==-1){std::cout<<"WRONG_INPUT\n";}
        else{std::cout<<rub[i]<<"\n";}
    }
}