#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size()-1;

    while(r < matrix.size() && c >= 0) {
        if(matrix[r][c] == target) return true;

        else if(matrix[r][c] < target) r++;
        else c--;
    }
    return false;
}


int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    bool found = searchMatrix(matrix, 8);

    cout << (found ? "true\n" : "false\n");

    return 0;
}