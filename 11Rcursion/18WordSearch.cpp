#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &board, string s, vector<vector<bool>> &visited, int i, int m, int n) {

    if(i == s.length()) return true;

    if(m >= board.size() || m < 0 || n < 0 || n >= board[0].size()) return false;

    if(visited[m][n] || board[m][n] != s[i]) {
        return false;
    }
    visited[m][n] = true;

    // up
    bool up = solve(board, s, visited, i+1, m-1, n);
    // down
    bool down = solve(board, s, visited, i+1, m+1, n);
    // left
    bool left = solve(board, s, visited, i+1, m, n-1);
    // right
    bool right = solve(board, s, visited, i+1, m, n+1);

    // backtrack
    visited[m][n] = false;

    if(up || down || left || right) {
        return true;
    }

    return false;
}

bool exist(vector<vector<char>> &board, string s) {
    int r = board.size();
    int c = board[0].size();
    bool ans = false;

    vector<vector<bool>> visited(r, vector<bool> (c,false));

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(board[i][j] == s[0]) {
                ans = solve(board, s, visited, 0, i, j); // 1 because currect char is found
                if(ans) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << exist(board, "ABCCED") << endl; // true
    cout << boolalpha << exist(board, "SEE") << endl;    // true
    cout << boolalpha << exist(board, "ABCB") << endl;   // false
}