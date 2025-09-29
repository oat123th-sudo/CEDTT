#include <iostream>
#include <iomanip>
// I can't think way better than this. Please help.

double arr[100000], func[100000];
int n;
int main(){
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        func[i] = arr[i];
        for(int j = i-1; j >= 0; j--){
            func[i] = arr[j] + 1/func[i];
        }
        std::cout << std::setprecision(10) << func[i] << '\n';
    }
}
