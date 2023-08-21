#include <list>
#include <vector>
#include <iostream>

std::vector<bool> * visited; 

void dfs(std::vector<std::list<int>> & adjList, int i){
    if((*visited)[i]) return; 
    
    (*visited)[i] = true;
    for(auto it = adjList[i].begin(); it != adjList[i].end(); it++){
        
        dfs(adjList, *it); 
    }
}

int main(){
    int n , m, v, e; 
    std::cin >> n >> m; 

    std::vector<std::list<int>> adjList(n+1);
    
    for(int i = 1; i <= m; i++){
        std::cin >> v >> e; 
        adjList[v].push_back(e);
        adjList[e].push_back(v);
    }

    std::list<int> connectedCities; 
    visited = new std::vector<bool> (n,false);

    for(int i = 1; i <= n; i++){
        if(!((*visited)[i])){
            connectedCities.push_back(i);
            dfs(adjList, i);
        }
    }

    std::cout << connectedCities.size()-1 << "\n"; 
    for(auto it = connectedCities.begin(); it != connectedCities.end(); it++){
        auto next = ++it;
        --it; 
        if(next != connectedCities.end()){
            std::cout << *it << " " << *next << "\n";
        }
    }

}
