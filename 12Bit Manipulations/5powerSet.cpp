#include <bits/stdc++.h>
using namespace std;

bool checkSetBit(int i, int j) {
    if (i & (1 << j)) return true;
    else return false;
}

void powerSet(vector<int>&nums, vector<vector<int>>& ans) { 
    // DETERMINE NO. OF SETS
    int subsets = 1 << nums.size();

    for(int i=0; i<subsets; i++) {
        vector<int> temp;
        for(int j=0; j<nums.size(); j++) {
            // if jth bit of i is set take it
            if(checkSetBit(i,j)) {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    powerSet(nums,ans);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}