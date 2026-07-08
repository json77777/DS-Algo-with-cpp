#include <bits/stdc++.h>
using namespace std;
/*
Mechanically:

Compute in-degree for every node.
Push all in-degree-0 nodes into a queue.
Pop a node, add it to the result, decrement the in-degree of its neighbors.
Any neighbor that hits in-degree 0 gets pushed into the queue.
Repeat until the queue is empty.
*/
vector<int> kahns_Algo(int V, vector<vector<int>> &adj) {
    vector<int> in(V);
    // maintain indegree
    for(int i=0; i<V; i++) {
        for(auto ng:adj[i]) {
            in[ng]++;
        }
    }
    
    queue<int> q;
    // push queue to indegree 0
    for (int i = 0; i < V; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    
    
    vector<int> ans;
    while (!q.empty()) {

        auto top = q.front();
        q.pop();
        ans.push_back(top);

        // remove indegree and push to queu if in->0;
        for(auto i:adj[top]) {
            in[i]--;
            if(in[i] == 0) q.push(i);
        }

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

    vector<int> res = kahns_Algo(n,adj);

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