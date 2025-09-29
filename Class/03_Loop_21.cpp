#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool isbig(char a){
    if(a >= 'A' && a <= 'Z'){
        return 1;
    }
    else return 0;

}
bool issmall(char a){
    if(a >= 'a' && a <= 'z'){
        return 1;
    }
    else return 0;
}
bool numnum(char a){
    if(a >= '0' && a <= '9'){
        return 1;
    }
    else return 0;
}
bool nono(char a){
    if((!(isbig(a))) && !(issmall(a)) && !(numnum(a))){
        return 1;
    }
    else return 0;
}
int main() {
    string password[100];
    string answer[100];
    int count = 0 ;
    bool strong =  false;
    bool weak = false;
    bool big = 0;
    bool small = 0;
    bool extra = 0;
    bool num = 0;
    while(cin >> password[count]){
        for(int i = 0  ; i < password[count].length() ; i++){
            if(big && small && extra && num){
                break;
            }
            else{
                if(isbig(password[count][i]))big = true;
                else if(issmall(password[count][i]))small = true;
                else if(numnum(password[count][i]))num = true;
                else if(nono(password[count][i]))extra = true;
            }
        }
        if((password[count].length() >= 12) && big && small && extra && num){
                strong = true;
            }
        else if((password[count].length() >= 8) && big && small && num) {
            weak = true;
        }
        if(strong)answer[count] =  ">> strong";
        else if(weak)answer[count] = ">> weak";
        else answer[count] = ">> invalid";
        big = 0 ,small = 0,num = 0,extra = 0,strong = 0 , weak = 0;
        count ++;
    }
    for(int i = 0 ; i < count ;i++){
        cout << answer[i] << endl;
    }
}
