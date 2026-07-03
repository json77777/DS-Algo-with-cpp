#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void DFS(vector<vector<int>>& adj, vector<bool>&visited, int i) {
    visited[i] = 1;
    
    for(auto ng:adj[i]) {
        if(!visited[ng]) {
            DFS(adj,visited,ng);
        }    
    }
}

// in-> [[1,1,0],[1,1,0],[0,0,1]]
int findCircleNum(vector<vector<int>>& isConnected) {
    // create adjacency list
    int n=isConnected.size();
    vector<vector<int>> adj(isConnected.size());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    
    int c=0;
    vector<bool> visited(isConnected.size());
    for(int i=0; i<isConnected.size(); i++) {
        if(!visited[i]) {
            c++;
            DFS(adj,visited,i);
        }
    }
    return c;
    
}

int main() {
    auto start = high_resolution_clock::now();


    vector<vector<int>> edges = {{1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1}};

    cout << "no of provinces: " << findCircleNum(edges) << endl;

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