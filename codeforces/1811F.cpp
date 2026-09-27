// codeforces 1811F
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Neighbor {
    int cnt = 0;
    vector<int> neighbors{};
};

bool isKLeaf(const unordered_map<int, Neighbor>& adj, vector<bool> &visited, int center_node, int k) {
    int prev = center_node, curr = -1;
    for (int v: adj.at(center_node).neighbors) {
        if (adj.at(v).cnt == 2) {
            curr = v;
            break;
        }
    }

    int len = 1; // 이미 center_node는 방문처리 됐기 때문
    while (curr != -1 && not visited[curr]) {
        len++;
        visited[curr] = true;
        if (adj.at(curr).cnt != 2)
            return false;

        int next = -1;
        for (int v: adj.at(curr).neighbors) {
            if (v != prev)
                next = v;
        }
        prev = curr;
        curr = next;
    }
    return len == k;
}

bool isCenterNode(const unordered_map<int, Neighbor> &adj, int u) {
    int center_node_cnt = 2, leaf_node_cnt = 2;
    for (int v: adj.at(u).neighbors) {
        switch (adj.at(v).cnt) {
            case 2:
                if (leaf_node_cnt-- == 0) return false;
                break;
            case 4:
                if (center_node_cnt-- == 0) return false;
                break;
            default:
                return false;
        }
    }
    return adj.at(u).cnt == 4;
}

bool isKFlower() {
    int n, m, u, v, center_node = -1;
    unordered_map<int, Neighbor> adj;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].neighbors.push_back(v);
        adj[u].cnt++;
        adj[v].neighbors.push_back(u);
        adj[v].cnt++;

        if (adj[u].cnt == 4)
            center_node = u;
        else if (adj[v].cnt == 4)
            center_node = v;
    }

    int k = sqrt(n);
    int k2 = k * k;
    if (k < 3 || n != k2 || m != k2 + k || center_node == -1) 
        return false;

    // decide to any direction
    int prev = center_node, curr = -1;
    for (int v: adj[prev].neighbors) {
        if (adj[v].cnt == 4)
            curr = v;
    }

    vector<bool> visited(n + 1);
    int len = 0;
    while (curr != -1 && not visited[curr]) {
        len++;
        visited[curr] = true;
        if (not isCenterNode(adj, curr) || not isKLeaf(adj, visited, curr, k))
            return false;

        int next = -1;
        for (int n: adj[curr].neighbors) {
            if (n != prev && adj[n].cnt == 4) {
                next = n;
                break;
            }
        }
        prev = curr;
        curr = next;
    }

    return len == k;
}

int main() {
    int t;
    cin >> t;
    while(t--)
        if (isKFlower())
            cout << "YES\n";
        else
            cout << "NO\n";
}