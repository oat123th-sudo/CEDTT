#include <bits/stdc++.h>
using namespace std;
int main(){
    string q; cin>>q;
    if(q.size()!=2||q[0]<'0'||q[0]>'9'||q[1]<'0'||q[1]>'9') {cout<<"Error"; return 0;}
    int n = stoi(q);
    if(n==1||n==2||(n>=20&&n<=40)||n==51||n==53||n==55||n==58)cout<<"OK";
    else cout<<"Error";
}