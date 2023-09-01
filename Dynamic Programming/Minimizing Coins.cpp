#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 10000001; // via constraint

int main(){ 
    int n, x;
    std::cin >> n >> x; 

    std::vector<int> coins(n); 
    std::vector<std::vector<int>> mat(n, std::vector<int>(x+1, 0)); 

    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    for(int i = 0, currCoin, r1, r2; i < n; i++){
        currCoin = coins[i];    //current coin we are working with
        r1 = i; 
        r2 = i-1; 
        for(int j = 1, c1, c2, val1, val2; j <= x; j++){
            c1 = j - currCoin;
            c2 = j; 

            if(r1 < 0 || c1 < 0) val1 = MAX; 
            else val1 = 1 + mat[r1][c1];

            if(r2 < 0 || c2 < 0) val2 = MAX; 
            else val2 = mat[r2][c2];

            mat[i][j] = std::min(val1, val2);
        }
    }
    std::cout << (mat[n-1][x] == MAX? -1 : mat[n-1][x]);  

}