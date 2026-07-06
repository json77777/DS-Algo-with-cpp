#include <bits/stdc++.h>
using namespace std;

bool hasCycle(vector<vector<int>> &adj, int node, vector<int> &state) {
    state[node] = 1; // mark as "in progress"
    for (auto ng : adj[node]) {
        if (state[ng] == 1) return true;        // back edge -> real cycle
        if (state[ng] == 0 && hasCycle(adj, ng, state)) return true;
        // state[ng] == 2 means already fully explored -> safe, skip
    }
    state[node] = 2; // done, safe
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (auto &p : prerequisites) {
        adj[p[1]].push_back(p[0]); // p[1] must be done before p[0]
    }

    vector<int> state(numCourses, 0); // 0=unvisited,1=visiting,2=done
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (hasCycle(adj, i, state)) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> pre = {{1,0}};
    cout << canFinish(2, pre) << endl; // valid: 0 -> 1, no cycle, expect 1 (true)

    vector<vector<int>> pre2 = {{1,0},{0,1}};
    cout << canFinish(2, pre2) << endl; // cycle: 0<->1, expect 0 (false)
}