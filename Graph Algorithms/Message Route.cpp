#include <iostream> 
#include <vector> 
#include <list>
#include <queue> 
#include <stack>

void solve(std::vector<std::list<int>> & adjList, std::vector<int>& prevList, int n){
    prevList[1] = 1; // cycles to itself lol 
    std::queue<int> q; 
    q.push(1);

    while(q.size()!=0){
        auto x = q.front(); 
        q.pop();

        //we have found the goal 
        if(x == n) {
            std::string res; 
            int curr = n; 
            std::stack<int> stk;
            
            while(curr != 1){
                stk.push(curr);
                curr = prevList[curr];
            };
            stk.push(1);

            std::cout << stk.size() << "\n";

            int temp = 0 ;
            
            while(stk.size()!= 0){
                temp = stk.top();
                stk.pop();
                std::cout << temp << " ";
            }
            return; 
        }

        for(auto it = adjList[x].begin(); it != adjList[x].end(); it++){
            //if we haven't visited yet
            if(prevList[*it] == -1){
                q.push(*it); 
                prevList[*it] = x; 
            }
        }
    }
    std::cout << "IMPOSSIBLE"; 
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