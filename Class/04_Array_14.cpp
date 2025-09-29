#include <bits/stdc++.h>
int x,y;
double a[30][30];
void input(){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            std::cin>>a[i][j];
        }
    }
}
void p9(int xx,int yy){
    double sum=0;
    for(int i=xx-1;i<=xx+1;i++){
        for(int j=yy-1;j<=yy+1;j++){
            sum+=a[i][j];
        }
    }
    std::cout<<round(sum*100/9.0)/100.0<<" ";
}
int main(){
    std::cin>>x>>y;
    input();
    for(int i=1;i<x-1;i++){
        for(int j=1;j<y-1;j++){
            p9(i,j);
        }
        std::cout<<"\n";
    }
}