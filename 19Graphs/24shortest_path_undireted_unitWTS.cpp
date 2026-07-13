#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// do simplr bfs traversal
// and compute distance on the go

 
vector<int> shortestDistance_unitWts(int V, vector<vector<int>>&adj, int src) {
    vector<int> dis(V+1,INT_MAX);
    dis[src] = 0;
    queue<pair<int,int>> q;  // node, distance
    q.push({src,0});

    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        int node = top.first;
        int distance = top.second;

        for(auto ng:adj[node]) {
            if(distance+1 < dis[ng]) { // since unit distance
                dis[ng] = distance+1;
                q.push({ng, distance+1});
            }
        }
    }

    return dis;
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

    vector<int> ans = shortestDistance_unitWts(n,adj,0);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
/*
6 7
0 1
0 2
1 3
2 3
2 4
3 5
4 5
*/