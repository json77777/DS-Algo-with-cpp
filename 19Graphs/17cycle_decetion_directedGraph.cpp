#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &pathVis, int st) {
    
    for(auto ng:graph[st]) {
        if(!vis[ng] && !pathVis[ng]) {
            vis[ng] = true;
            pathVis[ng] = true;
            if(dfs(graph, vis,pathVis,ng)) return true;
        }
        else if(vis[ng] && pathVis[ng]) return true;
    }

    pathVis[st] = false;

    return false;
}

bool isCycle(vector<vector<int>>& graph) {
    vector<bool> vis(graph.size(), false);
    vector<bool> pathVis(graph.size(), false);

    for(int i=1; i<graph.size(); i++) {
        if(!vis[i] && !pathVis[i]) {
            vis[i] = true;
            pathVis[i] = true;
            if(dfs(graph, vis, pathVis, i)) return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "is cycle: " << isCycle(adj) << endl;
}

/*
5 7
1 2
1 3
2 4
3 4
3 5
4 5
5 3

*/