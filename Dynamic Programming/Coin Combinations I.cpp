#include <iostream>
#include <vector> 
#include <algorithm>

int main(){
    int n, x; 
    std::cin >> n >> x; 

    std::vector<int> coins(n);\

    for(int i = 0; i < n; i++)
        std::cin >> coins[i];
    
    std::sort(coins.begin(), coins.end()); 


    std::vector<int> dp(x+1+coins[n-1], 0); //plus max valued coin
    dp[0] = 1;
    for(int i = 0 ; i <=x; i++){
        if(!dp[i] && i)  
            continue; 
        else 
            for(auto c : coins){
                dp[i+c]+=dp[i];
                dp[i+c]%=1000000007;
            }

    }

    std::cout << "\n" << dp[x];
}