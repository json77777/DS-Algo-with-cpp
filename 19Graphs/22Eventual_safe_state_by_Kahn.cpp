#include<bits/stdc++.h>
using namespace std;

// reverse the edges
// do kahn's algo
// return the ordering in ascending order

vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj) {
    vector<int> adjRev[V];
    vector<int> in(V);

    for(int i=1; i<V; i++) {
        for(auto it:adj[i]) {
            adjRev[it].push_back(i);
            in[i]++;
        }
    }

    // do kahn's algo
    queue<int> q;
    // push queue to indegree 0
    for (int i = 1; i < V; i++) {
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
        for(auto i:adjRev[top]) {
            in[i]--;
            if(in[i] == 0) q.push(i);
        }

    }
    sort(ans.begin(),ans.end());
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