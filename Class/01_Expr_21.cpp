#include <iostream>
using namespace std;
int main() {
 int h1,m1,s1, h2,m2,s2;
 cin >> h1 >> m1 >> s1;
 cin >> h2 >> m2 >> s2;
 int t1 = h1*60*60 + m1*60 + s1;
 int t2 = h2*60*60 + m2*60 + s2;
 if(t2<t1){
    t2=(t2+(3600*24)); // Adjust for next day if t2 is less than t1
 }
 int s=t2-t1;
 cout<<s/3600<<":"<<s%3600/60<<":"<<s%3600%60;
}