#include<iostream> 
#include<vector> 
#include<list>
int solve(int emp, std::vector<std::list<int>> &man, std::vector<int> &subs){
  int ret = 0; 
  for(auto it = man[emp].begin(); it != man[emp].end(); it++){
    ret+=solve(*it, man, subs); 
  }
  subs[emp] = ret; 
  return ret+1;
}

int main(){
  int n;
  std::cin >> n ;
  std::vector<std::list<int>> man(n+1); 
  std::vector<int> subs(n+1);
  for(int i = 2, temp; i < n+1; i++){
    std::cin >> temp;
    man[temp].push_back(i);
  }
  solve(1, man, subs);

  for(int i = 1; i < n+1; i++)
    std::cout << subs[i] << " ";
  std::cout << std::endl;
}
