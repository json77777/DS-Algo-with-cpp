#include<bits/stdc++.h>
using namespace std;

// push vertices to stack after completing the dfs

void dfs(int st, vector<vector<int>>&adj, vector<bool>&vis, stack<int>&sp) {
    vis[st] = true;
    for(auto ng:adj[st]) {
        if(!vis[ng]) {
            dfs(ng,adj,vis,sp);
        }
    }

    sp.push(st); // while returning push into stack
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
    vector<bool> vis(V);
    stack<int> sp; // to store the 

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i,adj,vis,sp);
        }
    }

    vector<int>ans;

    while(!sp.empty()) {
        ans.push_back(sp.top());
        sp.pop();
    }
    return ans;
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

    vector<int> res = topoSort(n, adj);

    // Print the result
    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;;
}

/*
6 6
5 0
5 2
2 3
3 1
4 0
4 1

*/