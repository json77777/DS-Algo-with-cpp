#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    
    // adjacency matrix 
    int n,m;
    cin >> n >> m;
    // vector<vector<int>> adj(n + 1);
    // for(int i=0; i<m; i++) {
    //     int v,u;
    //     cin >> v >> u;
    //     adj[v].push_back(u);
    // }
    
    // for(auto i:adj) {
        //     for (auto j:i) {
            //         cout << j << " ";
            //     } cout << endl;
    // }
    
    // weighted graphs
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<m; i++) {
        int x,y,z; // z-> weight
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) {
            cout << x.first << " " << x.second << ",";
        }
        cout << '\n';
    }

}