#include <vector> 
#include <iostream> 

long long solve(std::vector<long long> v){
    long long i = 0, j = 1, ret = 0; 
    while(j < (long long)v.size()){
        if(v[j] < v[i]) {
            ret+=v[i]-v[j];
            v[j] = v[i];
        }
        i++;
        j++;
    }
    return ret;
}

int main()
{
    long long  n; 
    std::cin >> n; 
    std::vector<long long> v(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    
    std::cout << solve(v);

}
