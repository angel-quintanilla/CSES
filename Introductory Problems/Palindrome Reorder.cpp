#include <iostream>
#include <vector>
int main(){
    std::string s;
    std::cin >> s; 
        
    std::vector<int> letters(26, 0);
    std::vector<char> out(s.length(), 'Z');
    
    
    for(int i = 0; i < s.length(); i++){
        letters[s[i]-'A']++; 
    }
    int l = 0, r = s.length()-1, oddIndex = -1, ml = s.length()/2, mr = ml; 
    for(int i = 0, n; i < 26; i++){
        n = letters[i];
        
        //odd
        if(n%2){
            if(ml != mr){
                std::cout << "NO SOLUTION"; 
                return 0; 
            }
            n--;
            mr++; 
            out[ml--] = i+'A'; 
            while(n){
                n-=2;
                out[ml--] = i+'A';
                out[mr++] = i+'A';
            }
        }
        else{
            while(n){
                out[l++] = i+'A';
                out[r--] = i+'A';
                n-=2; 
            }
        }
    }
    
    for(auto c : out)
        std::cout << c; 
}