#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int i,
            int j) {
    for (int k = 0; k < 4; k++) {
        int nr = i + dr[k];
        int nc = j + dc[k];

        if (nr >= 0 && nr < vis.size() && nc >= 0 && nc < vis[0].size() &&
            !vis[nr][nc] && board[nr][nc] == 'O') {
            vis[nr][nc] = true;
            dfs(board, vis, nr, nc);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();    // rows
    int n = board[0].size(); // cols

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // top boundary traversal
    for (int i = 0; i < n; i++) {
        if (!vis[0][i] && board[0][i] == 'O') {
            vis[0][i] = 1;
            dfs(board, vis, 0, i);
        }
    }
    // left boundary traversal
    for (int i = 0; i < m; i++) {
        if (!vis[i][0] && board[i][0] == 'O') {
            vis[i][0] = 1;
            dfs(board, vis, i, 0);
        }
    }
    // bottom boundary traversal
    for (int i = 0; i < n; i++) {
        if (!vis[m - 1][i] && board[m - 1][i] == 'O') {
            vis[m - 1][i] = 1;
            dfs(board, vis, m - 1, i);
        }
    }
    // right boundary traversal
    for (int i = 0; i < m; i++) {
        if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
            vis[i][n - 1] = 1;
            dfs(board, vis, i, n - 1);
        }
    }

    // convert back the ones which are not visited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && board[i][j] != 'X') {
                board[i][j] = 'X';
            }
        }
    }
}


int main() {


    vector<vector<char>> mat{
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };


    solve(mat);

    for (int i = 0; i <
         (int)mat.size(); i++) {
        for (int j = 0; j < (int)mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

}