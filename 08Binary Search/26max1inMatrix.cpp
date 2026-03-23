#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> & nums, int k) {
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] >= k) high = mid - 1;
        else low = mid + 1;
    }
    return low ;
}

int rowWithMax1s(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    // gives nos. of 1 -> ( c - lowerbound of 0 )

    int ans = -1;
    int ansInd = -1;
    for(int i=0; i<r; i++) {
        int oneCount = c - lowerBound(matrix[i], 1);
        if(oneCount > ans) {
            ans = oneCount;
            ansInd = i;
        }
    }
    return ansInd;
}

int main() {
    vector<vector<int>> matrix = {{0, 0, 0, 0, 1},
 {0, 0, 1, 1, 1},
 {0, 1, 1, 1, 1}};

    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix) << '\n';
}