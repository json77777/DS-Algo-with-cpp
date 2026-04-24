#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int i, int j) {
    bool row=false, col=false, lDiag=false, rDiag=false;

    for(int k=0; k<board[0].size(); k++)
        if(board[i][k] == 'Q') row = true;
    for(int k=0; k<board.size(); k++)
        if(board[k][j] == 'Q') col = true;
    for(int k=i-1, l=j-1; k>=0 && l>=0; k--, l--)
        if(board[k][l] == 'Q') lDiag = true;
    for(int k=i-1, l=j+1; k>=0 && l<board[0].size(); k--, l++)
        if(board[k][l] == 'Q') rDiag = true;

    return !(row || col || lDiag || rDiag);
}

void nQueen(vector<vector<char>>& board, int row, vector<vector<vector<char>>>& result) {
    if(row == board.size()) {
        result.push_back(board);  // store solution
        return;
    }
    for(int j = 0; j < board[0].size(); j++) {
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            nQueen(board, row+1, result);
            board[row][j] = '.';
        }
    }
}

int main() {
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<vector<char>>> result;

    nQueen(board, 0, result);

    for(auto i:result) {
        for(auto j:i) {
            for(auto k:j) {
                cout << k ;
            }cout << endl;
        } cout << endl << endl;
    }
}