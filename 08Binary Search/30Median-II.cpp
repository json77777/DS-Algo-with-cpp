#include<bits/stdc++.h>
using namespace std;

int countLessEqual(vector<int>& nums, int element) {
    int low = 0,high = nums.size()-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(nums[mid] <= element) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int findMedian(vector<vector<int>>& matrix) {
    int low = INT_MAX, high = INT_MIN;

    // set low
    for(int i=0; i<matrix.size(); i++) {
        low = min(low, matrix[i][0]);
    }

    // set high
    for(int i=0; i<matrix.size(); i++) {
        high = max(high, matrix[i][matrix[0].size()-1]);
    }

    while(low <= high) {
        int mid = low + (high - low)/2;

        int count = 0;
        for (int i = 0; i < matrix.size(); i++) {
            count += countLessEqual(matrix[i], mid);
        }

        if(count > matrix.size()*matrix[0].size()/2) {
            // possible lowest ans
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
    
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " << findMedian(matrix) << endl;
    return 0;
}
