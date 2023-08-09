#include <vector>
#include <iostream>
#include <algorithm>    

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k; 
    
    std::vector<int> fams(n);
    std::vector<int> apts(m);
    
    for(int i = 0; i < n; i++) { 
        std::cin >> fams[i];
    }
    for(int i = 0; i < m; i++) {
        std::cin >> apts[i];
    }
    
    std::sort(fams.begin(), fams.end());
    std::sort(apts.begin(), apts.end());
    
    int i = 0, j = 0, max = 0; 
    while(i < n && j < m){
        if(fams[i] >= apts[j]-k && fams[i] <= apts[j]+k){
            max++; 
            i++;
            j++; 
        }
        else if(fams[i] < apts[j]-k){
            i++;
        }
        else if(fams[i] > apts[j]+k){
            j++;
        }
    }
    
    std::cout << max; 
    
}
