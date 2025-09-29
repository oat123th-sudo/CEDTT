#include <bits/stdc++.h>

int main(){
    int a,b,c,t=0,sum=0;
    std::cin>>a>>b>>c;
    c-=543;
    if(c%4==0&&(c%100!=0||c%400==0)){
        t=1;
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
    std::cout<<sum+a;
}