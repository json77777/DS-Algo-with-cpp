#include<bits/stdc++.h>
using namespace std;

// tc -> O(rows);
int maxElm(vector<vector<int>>& mat, int col) {
    int ans = INT_MIN;
    int ansRow = -1;
    for(int i=0; i<mat.size(); i++) {
        if(mat[i][col] > ans) {
            ans = mat[i][col];
            ansRow = i;
        }
    }
    return ansRow;
}

// tc -> O(rows*log(cols))
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int low = 0, high = mat[0].size()-1;
    // vector<int> ans;

    while(low <= high) {
        int midCol = low + (high - low)/2;
        int maxElm_Row = maxElm(mat, midCol); // returns the row

        // key element
        int element = mat[maxElm_Row][midCol];

        int right = (midCol == mat[0].size()-1) ? -1 : mat[maxElm_Row][midCol+1];
        int left = (midCol == 0) ? -1 : mat[maxElm_Row][midCol-1];

        // mid elemet
        if(left <= element && right <= element) return {maxElm_Row, midCol}; 

        else if(right > element) low = midCol + 1;

        else if(left > element) high = midCol - 1;

        // move anywhere -> you are in a dip
        else if(left > element && right > element) low = midCol + 1;
    }

    return {-1,-1};
}


int main() {
    // Example usage
    vector<vector<int>> mat = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };


    // Call findPeakGrid function and print the result
    vector<int> peak = findPeakGrid(mat);
    cout << "The row of peak element is " << peak[0]
        << " and column of the peak element is " << peak[1] << endl;

    return 0;
}