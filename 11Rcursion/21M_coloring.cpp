#include <bits/stdc++.h>
using namespace std;

bool isSafe(int col, vector<int> &color, int node, vector<vector<bool>> &g) {
    for(int i=0; i<color.size(); i++) {
        if(g[i][node] && color[i] == col) {
            return false;
        }
    }
    return true;
}

bool M_coloring(int node, vector<vector<bool>> &g, vector<int> &color,int m) {
    if(node==g.size()) return true;

    for(int i=1; i<=m; i++) {
        if(isSafe(i,color,node,g)) {
            color[node] = i;
            if(M_coloring(node+1, g, color, m)) 
                return true;
            // backtracking
            color[node] = 0;
        }
    }
    return false;
}

int main() {

    int N = 4; // Number of nodes
    int m = 3; // Maximum number of colors
    vector<vector<int>> Edges = {{0, 1},{1, 2},{2, 3},{3, 0},{0, 2}};
    vector<vector<bool>> g(N, vector<bool> (N, false));

    for(auto i:Edges) {
        g[i[0]][i[1]] = true;
        g[i[1]][i[0]] = true;
    }
    vector<int> color(N,0);
    cout << M_coloring(0,g, color,m);
}