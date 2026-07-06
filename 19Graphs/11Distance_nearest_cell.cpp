#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();
    vector<vector<int>> dis(r, vector<int>(c, 0));
    vector<vector<int>> vis(r, vector<int>(c, 0));
    queue<vector<int>> q;

    // store the st points
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(mat[i][j] == 1) {
                vis[i][j] = 1;
                q.push({i,j,0});
            }
        }
    }


    // apply bfs
    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        // distance
        dis[top[0]][top[1]] = top[2];

        // now travel
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++) {
            int nr = top[0] + dr[i];
            int nc = top[1] + dc[i];

            if(nr >= 0 && nr < r && nc >= 0 && nc < c  && !vis[nr][nc]) {
                q.push({nr,nc,top[2]+1});
                vis[nr][nc] = 1;
            }
        }
    }


    return dis;
}

int main() {
    vector<vector<int>> pre = {{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    vector<vector<int>> ans = updateMatrix(pre);

    cout << "distance matrix(nearest 1): " << endl;
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }

    
}