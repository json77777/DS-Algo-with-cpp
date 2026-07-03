#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void DFS(vector<vector<int>>& adj, vector<int> &ans, vector<bool>&visited, int i) {
    ans.push_back(i);
    for(auto ng:adj[i]) {
        if(!visited[ng]) {
            visited[ng]=true;
            DFS(adj,ans,visited,ng);
        }    
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    vector<int> ans;
    vector<bool> visited(adj.size(), false);
    
    for(int i=0; i<visited.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            DFS(adj,ans,visited,i);
        }
    }
    
    return ans;
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
    }

    vector<int> ans = dfs(adj);
    for(auto it:ans) {
        cout << it << " ";
    } cout << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}

/*
5 6
1 2
1 3
2 4
3 4 
3 5 
4 5
*/