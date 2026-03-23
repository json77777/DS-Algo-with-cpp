#include<bits/stdc++.h>
using namespace std;

bool searchMatrix_Optimised(vector<vector<int>>& matrix, int target) {
    int low = 0, high = matrix.size() * matrix[0].size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        int i = mid/matrix[0].size();
        int j = mid%matrix[0].size();

        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] > target) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}


int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

    if (searchMatrix_Optimised(matrix, 8)) 
        cout << "true\n";
    else 
        cout << "false\n";

    return 0;
}