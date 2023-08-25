#include <iostream> 
#include <cmath> 
void hanoi(int n, int start, int end){
    if(n <= 0 ) return;
    hanoi(n-1, start, 6-start-end);
    std::cout << start << " " << end << "\n";
    hanoi(n-1, 6-start-end, end); 
}
int main(){
    int n; 
    std::cin >> n; 
    std::cout << pow(2, n)-1 << "\n";
    hanoi(n, 1, 3);
}