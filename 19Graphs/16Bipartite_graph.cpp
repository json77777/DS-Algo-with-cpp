#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>&col, vector<vector<int>>& graph, int st) {
    for(auto ng:graph[st]) {
        if(col[ng] == -1) {
            col[ng] = (col[st] == 1) ? 0 : 1; // choose color
            if(!dfs(col,graph, ng)) return false; // bail out only on conflict
        }
        else if(col[st] == col[ng]) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size(), -1); // will color with only 0 and 1
    
    // if(expected color != actual color)

    for(int i=0; i<graph.size(); i++) {
        if(colors[i]==-1) {
            colors[i]=0; // st with 0
            if(!dfs(colors, graph, i)) return false; // check every component
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    
    cout << "is bipartite graph: " << isBipartite(graph) << endl;
}