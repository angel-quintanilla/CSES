#include <iostream> 
#include <vector>
#include <queue> 
#include <list> 
#include <algorithm>

const long long  INF = 200000000000000000;





int main(){ 
    long long  n,m, q; 
    std::cin >> n >> m >> q; 
    std::vector<std::vector<long long>> mat(n+1, std::vector<long long>(n+1, INF)); 

    for(int i = 0, a, b, c; i < m; i++){
        std::cin >> a >> b >> c; 
        mat[a][b] = std::min((long long)c, mat[a][b]);
        mat[b][a] = std::min((long long)c, mat[b][a]); 

    }
    for(int i = 1; i <=n; i++){
        mat[i][i] = 0; 
    }

    for(int k = 1; k <= n; k++)
        for(int j = 1; j <=n; j++)
            for(int i = 1; i <=n; i++)
                mat[i][j] = std::min(mat[i][j], mat[i][k]+mat[k][j]);
    

    for(int i = 0, a , b; i < q; i++){
        std::cin >> a >> b;
        std::cout << (mat[a][b] == INF? -1: mat[a][b]) << "\n";
    }
    
}