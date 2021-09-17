#include <iostream>                                                                                                   
#include <algorithm>                                                             
#include <string>                                                                
#include <array>                                                                 
#include <cmath>                                                                 
#include <vector>                                                                
                                                                                 
#define MAX (100000)                                                             
                                                                                 
using namespace std;                                                             
                                                                                 
                                                                                 
int main(void) {                                                                 
    int n;                                                                       
    cin >> n;                                                                    
                                                                                 
    int x,y;                                                                     
    std::array<int, MAX + 1> x_proj = {0,};                                      
    std::array<int, MAX + 1> y_proj= {0,};                                       
                                                                                 
    std::fill(x_proj.begin(), x_proj.end(), 0);                                  
    std::fill(y_proj.begin(), y_proj.end(), 0);                                  
                                                                                 
    std::vector<std::pair<int, int>> pts;                                        
                                                                                 
    for (int i=0; i<n; i++) {                                                    
        cin >> x >> y;                                                           
        x_proj[x]++;                                                             
        y_proj[y]++;                                                             
        pts.push_back(std::make_pair(x,y));                                      
    }                                                                            
                                                                                 
    long long result = 0;                                                        
                                                                                 
    for (auto& pt : pts) {                                                       
        result += ((long long)x_proj[pt.first]-1) * ((long long)y_proj[pt.second]-1);
    }                                                                            
                                                                                 
    cout << result;                                                              
                                                                                 
    return 0;                                                                    
}   
