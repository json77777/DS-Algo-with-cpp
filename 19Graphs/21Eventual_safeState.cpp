#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, set<int>&safe) {
    pathVis[node]=true;
    vis[node]=true;

    for(auto ng:adj[node]) {
        if(pathVis[ng]) return false;
        if(!vis[ng]) {
           if(!dfs(ng,adj,vis,pathVis,safe)) return false;
        }
    }

    // remove pathVis
    pathVis[node] = false;
    // store as safe node
    safe.insert(node);
    return true;
}

vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj) {
    vector<bool> vis(V);
    vector<bool> pathVis(V);

    set<int> st;

    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            dfs(i,adj,vis,pathVis,st);
        }
    }

    vector<int> ans (st.begin(),st.end());
    return ans;
}

int main() {
    int V = 8;  // Number of nodes in the graph

    vector<vector<int>> adj = {
        {1},    // 0
        {2},    // 1
        {3},    // 2
        {1},    // 3
        {5},    // 4
        {6},    // 5
        {},     // 6
        {}      // 7
    };
    vector<int> safeNodes = eventualSafeNodes(V, adj);  // Call function to get safe nodes
    for (auto node : safeNodes) {
        cout << node << " ";  // Print the safe nodes
    }
    cout << endl;

}