#include <iostream>
#include <algorithm>
int main()
{
    int n, max, temp, ret = 0;
    std::cin >> n;
    
    while(n) { 
        temp = n;
        
        //get max digit;
        max = 0; 
        while(temp) {
            max = std::max(temp%10, max);
            temp/=10;
        }
        
        n-=max; 
        ret++; 
    }
    std::cout << ret; 
}