#include <iostream> 
#include <vector> 
#include <unordered_map> 

int main(){
    int n, x; 
    std::cin >> n >> x; 

    std::vector<int> coins(n);
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }
    
    std::vector<std::unordered_map<int, bool>> dp; 

}