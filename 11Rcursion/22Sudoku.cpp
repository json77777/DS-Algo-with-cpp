#include <bits/stdc++.h>
using namespace std;

bool isSafeCheck(vector<vector<char>> &board, int i, int j, int num) {
    // row
    for(int k = 0; k<board[0].size(); k++) {
        if(board[i][k]-'0' == num ) return false;
    }

    // col
    for(int k=0; k<board.size(); k++) {
        if(board[k][j]-'0' == num) return false;
    }

    // sub 3x3
    int stI = (i/3)*3;
    int endI = stI + 3;
    int stJ = (j/3)*3;
    int endJ = stJ+3;
    for(int k=stI; k<endI; k++) {
        for(int l=stJ; l<endJ; l++) {
            if(board[k][l]-'0' == num) return false;
        }
    }
    
    return true;

}

bool solveSudoku(vector<vector<char>> &board) {

    for(int i=0; i<9 ; i++) {
        for(int j=0; j<9; j++) {
            if(board[i][j] == '.') {
                for(int k = 1; k<=9; k++) {
                    if(isSafeCheck(board, i, j, k)) {
                        board[i][j] = k+'0';
                        if(solveSudoku(board)) return true;
                        // backtracking
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    for(auto i:board) {
        for(auto j : i) {
            cout << j << " ";
        }cout << endl;
    }cout << endl;

    solveSudoku(board);

    for(auto i:board) {
        for(auto j : i) {
            cout << j << " ";
        }cout << endl;
    }
}