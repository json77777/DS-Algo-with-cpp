#include <bits/stdc++.h>
using namespace std;
/*
Mechanically:

Compute in-degree for every node.
Push all in-degree-0 nodes into a queue.
Pop a node, add it to the result, decrement the in-degree of its neighbors.
Any neighbor that hits in-degree 0 gets pushed into the queue.
Repeat until the queue is empty.



after this if indegree [] has elements < V  => cycle exists.   
*/
bool detect_cycle_kahns_Algo(int V, vector<vector<int>> &adj) {
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
    return (ans.size() < V) ? true : false;
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

    cout << "cycle present? "<< detect_cycle_kahns_Algo(n,adj) << endl;

    
}

/*
4 4
0 1
1 2
2 3
3 1
*/