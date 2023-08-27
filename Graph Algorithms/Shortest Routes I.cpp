#include <iostream> 
#include <vector>
#include <queue> 
#include <list> 

const long long  INF = 200000000000000000;



void dijkstra(std::vector<long long >& res, std::vector<std::list<std::pair<long long ,long long >>>& adjList, long long  n){
    
    
    // std::priority_queue<std::pair<long long ,long long >> pq
    std::priority_queue <std::pair<long long ,long long > , std::vector<std::pair<long long ,long long >>, std::greater<std::pair<long long ,long long >> > pq; 

    pq.push({0, 1}); // starting polong long  
    res[1] = 0;

    while(pq.size()!=0){
        auto t = pq.top(); 
        long long  currentDist = t.first;
        long long  currentVertex = t.second;
        pq.pop();

        if(currentDist > res[currentVertex]) continue; 
        for(auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); it++){
            //relax 
            long long  dist = it->first; 
            long long  v = it->second; 

            if(t.first + dist < res[v]){
                res[v] = currentDist+dist;
                pq.push({currentDist+dist, v});
            }
        }
    }
} 

int main(){ 
    long long  n,m; 
    std::cin >> n >> m; 

    std::vector<std::list<std::pair<long long ,long long >>> adjList(n+1); 
    std::vector<long long > res(n+1, INF);

    for(long long  i = 0, a, b, c; i < m; i++){
        std::cin >> a >> b >> c; 
        adjList[a].push_back({c,b});
    }

    dijkstra(res, adjList, n);

    for(long long  i = 1; i <= n; i++){
        std::cout << res[i] << " ";
    }

}