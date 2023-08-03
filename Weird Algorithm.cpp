#include <iostream> 

void solve(long long n){
    std::cout << n << " ";
    if(n==1) return; 
    n % 2 ? solve(n*3+1) : solve(n/2);
}

int main()
{
    int n; 
    std::cin >> n; 
    solve(n);
}
