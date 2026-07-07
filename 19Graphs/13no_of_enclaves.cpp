#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i,
            int j) {
    for (int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
            !vis[nr][nc] && grid[nr][nc] == 1) {
            vis[nr][nc] = 1;
            dfs(grid, vis, nr, nc);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // top boundary
    for (int i = 0; i < n; i++) {
        if (!vis[0][i] && grid[0][i]) {
            vis[0][i] = 1;
            dfs(grid, vis, 0, i);
        }
    }
    // left boundary
    for (int i = 0; i < m; i++) {
        if (!vis[i][0] && grid[i][0]) {
            vis[i][0] = 1;
            dfs(grid, vis, i, 0);
        }
    }
    // bottom boundary
    for (int i = 0; i < n; i++) {
        if (!vis[m - 1][i] && grid[m - 1][i]) {
            vis[m - 1][i] = 1;
            dfs(grid, vis, m - 1, i);
        }
    }
    // right boundary
    // right boundary
    for (int i = 0; i < m; i++) {
        if (!vis[i][n - 1] && grid[i][n - 1]) {
            vis[i][n - 1] = true;
            dfs(grid, vis, i, n - 1);
        }
    }

    // count the enclaves
    int c = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                c++;
            }
        }
    }

    return c;
}


int main() {

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "no of enclaves: " << numEnclaves(grid) << endl;

  
}