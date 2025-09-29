#include <bits/stdc++.h>

int main(){
    double cx,cy,rc,re,x,y;
    std::cin >> cx >> cy >> rc >> re >> x >> y;
    double dis=sqrt((cx-x)*(cx-x) + (cy-y)*(cy-y));
    double dtr=rc-re;
    double a=dtr/dis;
    int rx=std::round(a*(x-cx)+cx),ry=std::round(a*(y-cy)+cy);
    std::cout << rx << " " << ry << std::endl;
}