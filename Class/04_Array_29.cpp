#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n*4],cnt=0;;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ar[cnt++]=x1; //x min
        ar[cnt++]=x2; //x max
        ar[cnt++]=y1; //y min
        ar[cnt++]=y2; //y max
    }
    //for(int i=0;i<n4;i++) cout<<ar[i]<<" ";
    int ans=0;
    int kao[10000];
    int ckao=0;
    for(int i=0;i<cnt;i+=4){
        for(int j=i+4;j<cnt;j+=4){
            int nowx=min(ar[i+1],ar[j+1])-max(ar[i],ar[j]);
            int nowy=min(ar[i+3],ar[j+3])-max(ar[i+2],ar[j+2]);
            //cout<<nowx<<" "<<nowy<<'\n';
            if(nowx<0 or nowy<0) continue;
            int temp=nowx*nowy;
            if(temp>ans ){
                ckao=0;
                kao[ckao++]=i/4;
                kao[ckao++]=j/4;
                //cout<<i/4<<" "<<j/4<<'\n';
                ans=temp;
            }
            else if(temp==ans){
                kao[ckao++]=i/4;
                kao[ckao++]=j/4;
            }
        }
    }
    if(ans==0){
        cout<<"No overlaps";
        return 0;
    }
    cout<<"Max overlapping area = "<<ans<<'\n';
    for(int i=0;i<ckao;i+=2){
        cout<<"rectangles "<<kao[i]<<" and "<<kao[i+1]<<'\n';
    }
}