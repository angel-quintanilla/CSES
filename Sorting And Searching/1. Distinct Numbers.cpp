#include <vector>
#include <iostream>
#include <algorithm>    

int main()
{
    int n, temp, res = 1; 
    
    std::cin >> n ;
    std::vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    
    std::sort(v.begin(), v.end()); //logn
    temp = v[0];

    for(auto x : v) {
        if(temp != x){
            res++;
            temp = x; 
        }
    }
    std::cout << res;

}
