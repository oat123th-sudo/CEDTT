#include <bits/stdc++.h>
int n,cnt=0;
std::string p[55],pn[55];
void eqp(){
    for(int i=0;i<55;i++){
        pn[i]=p[i];
    }
}
void eqpn(){
    for(int i=0;i<55;i++){
        p[i]=pn[i];
    }
}
void prp(){
    for(int i=0;i<n;i++){
        std::cout<<p[i]<<" ";
    }
}
void prpn(){
    for(int i=0;i<n;i++){
        std::cout<<pn[i]<<" ";
    }
}
int main(){
    std::cin>>n;
    std::string s,x;
    std::cin.ignore();
    for(int i=0;i<n;i++){
        std::cin>>p[i];
    }
    std::cin.ignore();
    getline(std::cin,s);
    eqp();
    for(int i=0;i<s.size();i++){
        if(s[i]=='C'){
            for(int o=0;o<n/2;o++){
                pn[o]=p[o+n/2];
            }
            for(int o=n/2;o<n;o++){
                pn[o]=p[o-n/2];
            }
            eqpn();
        }
        if(s[i]=='S'){
            int cntt=0;
            for(int o=0;o<n;o++){
                //std::cout<<cntt<<" "<<p[cntt]<<" "<<p[cntt+n/2]<<"\n";
                if(o%2==1){pn[o]=p[cntt+n/2];cntt++;}
                else{pn[o]=p[cntt];}
            }
            eqpn();
        }

    }
    prpn();
}