#include <iostream> 
#include <vector> 
#include <list>

void solve(std::vector<std::list<int>> & adjList, std::vector<int>& prevList, int n) {
    
}
int main(){ 
    int n, m; 
    std::cin >> n >>m ; 
    std::vector<std::list<int>> adjList(n+1);
    std::vector<int> prevList(n+1, -1); 

    for(int i = 0, e, v; i < m; i++){
        std::cin >> e >> v; 
        adjList[e].push_back(v);
        adjList[v].push_back(e);
    }

    solve(adjList,prevList,n);
}