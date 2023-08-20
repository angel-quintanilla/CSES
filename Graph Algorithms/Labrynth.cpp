#include <iostream> 
#include <queue>
#include <stack>


void solve(int n , int m, int Ax, int Ay, int Bx, int By, char ** p) {

    p[Bx][By] = '.'; //don't need ;

    std::queue<std::pair<int,int>> q; 

    q.push({Ax, Ay});

    while(q.size() != 0) {
        auto t = q.front();
        q.pop();  
        int x = t.first, y = t.second; 

        if(x == Bx && y == By){
            
            //traceback
            std::stack<char> stk;
            int path = 0; 
            while(x != Ax || y != Ay){
                path++; 
                stk.push(p[x][y]);
                switch(p[x][y]){
                    case 'U': 
                        x++; 
                        break;
                    case 'D': 
                        x--; 
                        break;
                    case 'L':
                        y++; 
                        break;
                    case 'R':
                        y--;
                        break;
                }
            }

            int i = 0;
            std::string result(path, '\0');

            while(stk.size()!= 0){
                result[i++] = stk.top();
                stk.pop(); 
            }

            std::cout << "YES\n" << path << "\n"+result; 
            return; 
        }


        if(x-1 >= 0 && p[x-1][y] == '.') {
            q.push({x-1, y});
            p[x-1][y] = 'U';
        }
        if(x+1 < n && p[x+1][y] == '.') {
            q.push({x+1, y});
            p[x+1][y] = 'D';
        }
        if(y-1 >= 0 && p[x][y-1] == '.') { 
            q.push({x, y-1});
            p[x][y-1] = 'L';

        }
        if(y+1 < m && p[x][y+1] == '.') {
            q.push({x, y+1});
            p[x][y+1] = 'R';
        }
    }

    std::cout << "NO"; 
}


int main(){
    int n, m; 
    char ** p;
    std::cin >> n >> m; 

    int Ax, Ay, Bx, By; 

    p = new char* [n];
    for(int i = 0; i < n; i++){
        p[i] = new char[m];
        for(int j = 0; j < m; j++){
            std::cin >> p[i][j];
            if(p[i][j] == 'A'){
                Ax = i; 
                Ay = j;
            }
            if(p[i][j] == 'B'){
                Bx = i; 
                By = j;
            }
        }
    }

    solve(n,m, Ax, Ay, Bx, By, p);

}