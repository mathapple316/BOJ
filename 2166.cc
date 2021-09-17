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
                                                                                 
    // n+1개를 갖고 있으므로 0 - n                                               
    for (int i=0; i<n; i++) {                                                    
        // overflow 가 일어날 수 있음로 coord에서도 long long으로 선언해줘야함   
        sum += coords[i].x * coords[i+1].y - coords[i].y*coords[i+1].x;          
        //std::cout << "SUM : " << sum << "\n";                                  
    }                                                                            
                                                                                 
    double res = std::abs(sum)/2.0;                                              
                                                                                 
    printf("%.1lf", res);                                                        
                                                                                 
    return 0;                                                                    
} 
