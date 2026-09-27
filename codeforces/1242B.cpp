// codeforces 1242B
#include <iostream>
#include <array>
#include <queue>
#include <set>

using namespace std;

void bfs(set<int> &unvisited, const array<set<int>, 100001> &hasCost, int u) {
    queue<int> q;
    q.push(u);
    
    while (not q.empty()) {
        u = q.front();
        q.pop();
    
        for (set<int>::iterator it = unvisited.begin(); it != unvisited.end();) {
            auto cur = it++;
            int v = *cur;
            if (not hasCost[u].contains(v)) {
                unvisited.erase(cur);
                q.push(v);
            }
        }
    }
}

int main() 
{
    int n, m;
    set<int> unvisited;
    array<set<int>, 100001> hasCost{};

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        unvisited.emplace_hint(unvisited.end(), i);
    }

    while(m--) {
        int a, b;
        cin >> a >> b;
        
        hasCost[a].insert(b);
        hasCost[b].insert(a);
    }

    int g = -1;
    while (not unvisited.empty()) {
        int u = *unvisited.begin();
        unvisited.erase(u);
        g++;
        bfs(unvisited, hasCost, u);
    }

    cout << g << "\n";
    
    return 0;
}