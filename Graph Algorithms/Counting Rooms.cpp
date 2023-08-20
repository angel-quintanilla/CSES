#include <iostream> 
#include <vector>

void dfs(int n , int m, int i, int j, char ** p) {
    if(i < 0 || i >=n || j < 0 || j >= m || p[i][j] != '.') return; 
    p[i][j] = '#';
    dfs(n,m,i-1, j, p);
    dfs(n,m,i+1, j, p);
    dfs(n,m,i, j-1, p);
    dfs(n,m,i, j+1, p);

    return; 
}

int solve(int n ,int m, char ** p) {
    int ret = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(p[i][j] == '.'){
                ret++; 
                dfs(n,m, i, j, p);
            }
        }
    }
    return ret; 
}



int main(){

    int n,m; 
    std::cin >> n >> m; 
    char ** p; 
    p = new char* [n];
    for(int i = 0; i < n; i++){
        p[i] = new char [m];
    }

    for(int i = 0; i < n ; i++){
       for(int j = 0; j < m ; j++){
            std::cin >> p[i][j];
       } 
    }

    std::cout << solve(n, m, p);

}