#include <algorithm> 
#include <vector> 
#include <iostream> 

int main()
{
    int n, weight; 
    std::cin >> n >> weight; 
    
    std::vector<int> kids(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> kids[i];
    }
    
    std::sort(kids.begin(), kids.end());
    
    int gondolas = 0; 
    int i = 0, j = n-1; 

    while(i <= j) {
        gondolas++;
        if(i == j) {
            break;
        }
        if(kids[j] + kids[i] <= weight){
            j--;
            i++; 
        }
        else {
            j--;
        }
    }
    
    std::cout << gondolas; 
    
    
}
