#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool hasCycle(vector<vector<int>> & adj, int src) {
    queue<pair<int,int>> q;
    vector<bool> vis(adj.size(), false) ;
    q.push({src,-1});
    vis[src] = true;

    while(!q.empty()) {
        auto node = q.front().first;
        auto parent = q.front().second;
        q.pop();

        for(auto ng:adj[node]) {
            if(!vis[ng]) {
                vis[ng]=true;
                q.push({ng, node});
            }
            else if(ng != parent) return true;
        }
    }

    return false;
}

bool detectCycle(vector<vector<int>> adj) {

    for(int i=1; i<adj.size(); i++) {
        if(hasCycle(adj,i)) {
            return true;
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