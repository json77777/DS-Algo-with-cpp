#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// do topo sort
// By the time you reach a specific node, you have already calculated and locked in the shortest possible distance for every single node that points to it

void dfs(int st, vector<vector<pair<int,int>>>&adj, stack<int>&sp, vector<bool>&vis) {
    vis[st] = true;
    for(auto ng:adj[st]) {
        if(!vis[ng.first]){
            dfs(ng.first, adj,sp,vis);
        }
    }

    sp.push(st);
}
 
vector<int> shortestDistance(int V, vector<vector<pair<int,int>>>&adj, int src) {
    vector<bool> vis(V+1,false);
    stack<int> sp;

    for(int i=1; i<V; i++) {
        if(!vis[i]) {
            dfs(i,adj,sp,vis);
        }
    }

    vector<int> dis(V+1,INT_MAX);
    dis[src] = 0;

    //Relax the edges after topological sorting
    while (!sp.empty()) {
        int top = sp.top();
        sp.pop();

        if (dis[top] != INT_MAX) {   // reachable
            for (auto ng : adj[top]) {
                int v = ng.first;
                int wt = ng.second;

                if (dis[top] + wt < dis[v]) {
                    dis[v] = dis[top] + wt;
                }
            }
        }
    }

    return dis;
}

int main() {
    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v,x});
    }

    vector<int> ans = shortestDistance(n,adj,1);
    for(int i=1; i<ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
/*
6 8
1 2 2
1 4 1
2 3 3
4 2 2
4 5 4
5 3 1
5 6 2
3 6 5
*/