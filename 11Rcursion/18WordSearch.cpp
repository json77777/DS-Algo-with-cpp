#include <bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>> &board, string s) {
    
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