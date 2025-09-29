#include <bits/stdc++.h>
int to2(std::string a,int n){
    int sum=0;
    /*for(int i=0+(4*n);i<4+(4*n);i++){
        std::cout<<a[i];
    }*/
    for(int i=0+(4*n);i<4+(4*n);i++){
        if(a[i]>='a'&&a[i]<='z'){
            /*std::cout<<"\n";
            std::cout<<i<<" "<<a[i]<<"\n";*/
            sum+=pow(2,3-(i%4));
        }
        /*else{
            std::cout<<0;
        }*/
    }
    //std::cout<<" ";
    return sum;
}
void D(std::string WO){
    for(int i=0;i<WO.size()/4;i++){
        if(to2(WO,i)<=9){std::cout<<to2(WO,i);}
        else if(to2(WO,i)==10){std::cout<<"-";}
        else{std::cout<<",";}

    }
}
void E(std::string WO,std::string to){
    std::string WOR;
    int i=0,cnt=0;
    while(cnt<to.size()*4){
        if(i==WO.size()){
            i=0;
        }
        if(WO[i]!=' '){WOR+=WO[i];}
        if(((WO[i]<='z'&&WO[i]>='a')||(WO[i]<='Z'&&WO[i]>='A'))){
            cnt++;
        }
        i++;
    }
    for(int j=0;j<to.size();j++){
        int o=j*4;
        if(to[j]=='0'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){

                }
                else{
                    o++;
                }
            }
        }
        if(to[j]=='1'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==3){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='2'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='3'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
                if(k%4==3){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='4'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==1){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='5'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==1){WOR[k]=tolower(WOR[k]);}
                if(k%4==3){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='6'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==1){WOR[k]=tolower(WOR[k]);}
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='7'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==1){WOR[k]=tolower(WOR[k]);}
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
                if(k%4==3){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='8'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==0){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='9'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==0){WOR[k]=tolower(WOR[k]);}
                if(k%4==3){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]=='-'){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==0){WOR[k]=tolower(WOR[k]);}
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
            }
        }
        if(to[j]==','){
            for(int k=o;k<o+4;k++){
                WOR[k]=toupper(WOR[k]);
                if(WOR[k]>='A'&&WOR[k]<='Z'){
        
                }
                else{
                    o++;
                }
                if(k%4==0){WOR[k]=tolower(WOR[k]);}
                if(k%4==2){WOR[k]=tolower(WOR[k]);}
                if(k%4==3){WOR[k]=tolower(WOR[k]);} 
            }
        }
    }
    std::cout<<WOR;
}
std::string pl(std::string R,int n){
    std::string K="";
    for(int i=n;i<R.size();i++){
        if(R[i]!=' '){
            K+=R[i];
        }
    }
    //std::cout<<K;
    return K;
}
int main(){
    std::string WORD,R;
    std::cin.ignore(0);
    getline(std::cin,WORD);
    std::cin.ignore(0);
    while(getline(std::cin,R)){
        std::cin.ignore(0);
        std::string RU=pl(R,2);
        if(R[0]=='D'){D(RU);
            std::cout<<'\n';
        }
        if(R[0]=='E'){E(WORD,RU);
            std::cout<<'\n';
        }
    }
}