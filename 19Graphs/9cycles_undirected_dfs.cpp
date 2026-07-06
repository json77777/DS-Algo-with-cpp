#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool hasCycle(vector<vector<int>> & adj, int src, vector<bool> &vis, vector<int> &parent) {
    
    for(auto ng:adj[src]) {
        if(!vis[ng]) {
            vis[ng] = true;
            parent[ng] = src;
            if(hasCycle(adj,ng, vis, parent)) return true;
        }
        else if(ng != parent[src]) return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>> adj) {
    
    vector<bool> visited(adj.size(), false);
    vector<int> parent(adj.size(),-1);

    for(int i=1; i<adj.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            parent[i] = -1;
            if(hasCycle(adj,i, visited, parent)) {
                return true;
            }       
        }
    }

    return false;
}

int main() {
    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }

    cout << "cycle present ? " << detectCycle(adj) << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}