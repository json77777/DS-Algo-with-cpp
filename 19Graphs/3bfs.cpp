#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void BFS(vector<vector<int>> &adj, queue<int> &q, vector<int> &ans, vector<bool> &visited) {
    if(q.empty()) return;
    auto top = q.front(); q.pop();
    ans.push_back(top);
    for(auto neigh : adj[top]) {
        if(!visited[neigh]) {
            // mark visited
            visited[neigh] = true;
            q.push(neigh);
        }
    }
    BFS(adj,q,ans,visited);
}

vector<int> bfs(vector<vector<int>> &adj) {
    vector<int> ans;
    vector<bool> visited(adj.size(),false);

    queue<int> q;
    q.push(1);
    for(int i=1; i<visited.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            BFS(adj,q,ans,visited);
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

    vector<int> ans = bfs(adj);
    for(auto it:ans) {
        cout << it << " ";
    } cout << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}