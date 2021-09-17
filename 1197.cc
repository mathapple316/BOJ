#include <iostream>                                                                                                   
#include <algorithm>                                                             
#include <string>                                                                
#include <array>                                                                 
#include <cmath>                                                                 
#include <vector>                                                                
                                                                                 
#define MAX_NODE (10000)                                                         
using namespace std;                                                             
std::array<size_t, MAX_NODE + 1> parent;                                         
                                                                                 
struct w_edge {                                                                  
    int start;                                                                   
    int end;                                                                     
    int w;                                                                       
};                                                                               
                                                                                 
int Find(int x) {                                                                
    if (parent[x] == x) {                                                        
        return x;                                                                
    }                                                                            
                                                                                 
    return parent[x] = Find(parent[x]);                                          
}                                                                                
                                                                                 
void Union(int x, int y) {                                                       
    if (Find(x) == Find(y)) {                                                    
        return;                                                                  
    }                                                                            
                                                                                 
    parent[Find(x)] = Find(y);                                                   
}                                                                                
                                                                                 
int main(void) {                                                                 
    int v_num, e_num;                                                            
    cin >> v_num >> e_num;                                                       
    vector<w_edge> edges;                                                        
    edges.reserve(e_num);                                                        
                                                                                 
    for (int i=0; i<e_num; i++) {                                                
        int start, end, w;                                                       
        cin >> start >> end >> w;                                                
        edges.push_back({start, end, w});                                        
    }                                                                            
                                                                                 
    auto compare = [](w_edge& e1, w_edge& e2) {                                  
        return (e1.w < e2.w);                                                    
    };                                                                           
                                                                                 
    // edge들을 weight 순으로 정렬                                               
    sort(edges.begin(), edges.end(), compare);                                   
                                                                                 
    // kruskal algorithm을 사용                                                  
    vector<w_edge> mst;                                                          
                                                                                 
    for (int i=1; i<v_num+1; i++) {                                              
        parent[i] = i;                                                           
    }                                                                            
                                                                                 
    for (auto& edge : edges) {                                                   
        if (Find(edge.start) == Find(edge.end)) {                                
            continue;                                                            
        }                                                                        
                                                                                 
        Union(edge.start, edge.end);                                             
        mst.push_back(edge);                                                     
    }                                                                            
                                                                                 
    int sum = 0;                                                                 
    for (auto& edge : mst) {                                                     
        sum += edge.w;                                                           
    }                                                                            
                                                                                 
    std::cout << sum;                                                            
    return 0;                                                                    
}  
