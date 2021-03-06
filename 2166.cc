#include <iostream>                                                                                                   
#include <string>                                                                
#include <array>                                                                 
#include <cmath>                                                                 
#include <vector>                                                                
                                                                                 
struct coord{                                                                    
    long long x;                                                                 
    long long y;                                                                 
};                                                                               
                                                                                 
int main(void) {                                                                 
    int n;                                                                       
    std::cin >> n;                                                               
    std::vector<coord> coords;                                                   
    coords.reserve(n);                                                           
                                                                                 
    for (int i=0; i<n; i++) {                                                    
        int p,q;                                                                 
        std::cin >> p >> q;                                                      
        coords.push_back({p,q});                                                 
    }                                                                            
    coords.push_back(coords[0]);                                                 
                                                                                 
    long long sum = 0;                                                           
                                                                                 
    // n+1?????? ?????? ???????????? 0 - n                                               
    for (int i=0; i<n; i++) {                                                    
        // overflow ??? ????????? ??? ????????? coord????????? long long?????? ??????????????????   
        sum += coords[i].x * coords[i+1].y - coords[i].y*coords[i+1].x;          
        //std::cout << "SUM : " << sum << "\n";                                  
    }                                                                            
                                                                                 
    double res = std::abs(sum)/2.0;                                              
                                                                                 
    printf("%.1lf", res);                                                        
                                                                                 
    return 0;                                                                    
} 
