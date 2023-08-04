#include <iostream>

int main(){ 
    long long n, temp;
    std::cin >> n; 

    temp = n;

    if(n == 2 || n == 3) {
        std::cout << "NO SOLUTION";
        return 0;
    }

    n--;

    while(n > 0) {
        std::cout << n << " "; 
        n-=2;
    }
    

    while(temp > 0){
        std::cout << temp << " "; 
        temp-=2; 
    }



}