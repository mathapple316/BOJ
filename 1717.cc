#include <iostream>
#include <string>
#include <array>
#include <cmath>

#define MAX 1000000 + 1
#define CMD_UNION 0
#define CMD_CHECK 1

// x 노드의 루트 노드를 찾는 함수
int Find(std::array<int, MAX>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = Find(parent, parent[x]);
}

void Union(std::array<int, MAX>& parent, int x, int y) {
    int root_x = Find(parent, x);
    int root_y = Find(parent, y);

    if (root_x == root_y) {
        return; 
    }

    int smaller = std::min(root_x, root_y);
    int larger = std::max(root_x, root_y);

    parent[larger] = smaller;
    return;
}

void Check(std::array<int, MAX>& parent, int x, int y) {
    int root_x = Find(parent, x);
    int root_y = Find(parent, y);

    if (root_x == root_y) {
        std::cout << "YES\n";
        return;
    }

    std::cout << "NO\n";
    return;
}

int main(void) {
    std::cin.tie(0);
	std::cin.sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);

    int n,m;
    std::cin >> n >> m;
    std::array<int, MAX> parent;

    // 초기화
    for (int i=0; i<n+1; i++) {
        parent[i] = i;
    }

    int cmd, a, b;
    for (int i=0; i<m; i++) {
        std::cin >> cmd >> a >> b;
        
        if (cmd == CMD_UNION) {
            Union(parent,a,b);
            continue;
        }

        if (cmd == CMD_CHECK) {
            Check(parent,a,b);
            continue;
        }

    }

    return 0;
}
