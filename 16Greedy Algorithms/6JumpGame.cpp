#include<bits/stdc++.h>
using namespace std;

// to check if the end is reachable
bool canJump(vector<int>& nums) {
    int maxInd=0;
    for(int i=0; i<nums.size(); i++) {
        if(i > maxInd) return false;
        maxInd = max(maxInd, nums[i]+i);
    }
    return maxInd >= nums.size()-1;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
}