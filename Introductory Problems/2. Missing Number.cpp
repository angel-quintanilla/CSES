#include <iostream> 

int main(){
    long long n = 0, j = 0, k = 0; 
    std::cin >> n; 
    
    for(int i = 0; i < n-1; i++){
        std::cin >> j; 
        k+=j;
    }

    std::cout << (n*(n+1)/2) - k; 
}