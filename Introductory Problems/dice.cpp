#include <iostream>
 
int main()
{
    long long n ;
    std::cin >> n ;
    
    long long * dp = new long long[n+7];
    for(long long i = 0; i < n+7; i++)
        dp[i] = 0;
    dp[0] = 1; 
    
    for(long long i = 0; i <= n; i++){
        for(long long j = 1; j <= 6; j++){
            dp[i+j]+=dp[i]; 
            dp[i+j]%=1000000007;
        }
    }
    
    std::cout << dp[n];
    
    delete [] dp; 
    return 0;
}