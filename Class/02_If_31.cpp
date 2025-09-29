#include <bits/stdc++.h>

int main(){
    int a,b,c,a2,b2,c2,t=0,t2=0,sum=0,sum2=0;
    std::cin>>a>>b>>c>>a2>>b2>>c2;
    c-=543;
    c2-=543;
    if(c%4==0&&(c%100!=0||c%400==0)){
        t=1;
    }
    if(c2%4==0&&(c2%100!=0||c2%400==0)){
        t2=1;
    }
    while(b--){
        if(b==1){sum+=31;}
        if(b==2){
            if(t==0)sum+=28;
            else{sum+=29;}
        }
        if(b==3){sum+=31;}
        if(b==4){sum+=30;}
        if(b==5){sum+=31;}
        if(b==6){sum+=30;}
        if(b==7){sum+=31;}
        if(b==8){sum+=31;}
        if(b==9){sum+=30;}
        if(b==10){sum+=31;}
        if(b==11){sum+=30;}
        if(b==12){sum+=31;}
    }
    while(b2--){
        if(b2==1){sum2+=31;}
        if(b2==2){
            if(t2==0)sum2+=28;
            else{sum2+=29;}
        }
        if(b2==3){sum2+=31;}
        if(b2==4){sum2+=30;}
        if(b2==5){sum2+=31;}
        if(b2==6){sum2+=30;}
        if(b2==7){sum2+=31;}
        if(b2==8){sum2+=31;}
        if(b2==9){sum2+=30;}
        if(b2==10){sum2+=31;}
        if(b2==11){sum2+=30;}
        if(b2==12){sum2+=31;}
    }
    if(t==1){sum=366-sum;}
    else{sum=365-sum;}
    c2--;
    double sd=sum+sum2+((c2-c)*365.0)+a2-a;
    double bb=round(sin((2*M_PI*sd)/23)*100.0)/100.0,i=round(sin((2*M_PI*sd)/28)*100.0)/100.0,e=round(sin((2*M_PI*sd)/33)*100.0)/100.0;
    std::cout<<sd<<" "<<bb<<" "<<i<<" "<<e;
}