#include <algorithm>
#include <iostream> 

int solve(std::string n){
    char current = '\0'; 
    long long max = 0, currCnt = 0; 
    
    for(int i = 0; i < n.length(); i++){
        if(n[i] != current){
            current = n[i];
            max = std::max(max, currCnt);
            currCnt = 1;
        }
        else currCnt++; 
    }
    
    return std::max(max, currCnt); 
}

int main()
{
    std::string n; 
    std::cin >> n; 
    std::cout << solve(n);
}
