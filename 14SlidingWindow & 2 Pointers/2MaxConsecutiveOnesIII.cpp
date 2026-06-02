#include<bits/stdc++.h>
using namespace std;

int max1sBF(vector<int> nums, int k) {
    // generate the longest subarrs with k 0s
    int len = 0;
    for(int i=0; i<nums.size(); i++) {
        int c=0;
        for(int j=i; j<nums.size(); j++) {
            if(nums[j] == 0) c++;
            if(c > k) break;
            len = max(len,j-i+1);
        }
    }
    return len;
}

int longestOnes(vector<int>& nums, int k) { // TC -> O(2n) worst
    int maxLen = 0;
    int zeroes = 0;
    int l = 0, r=0;
    while (r<nums.size()) {
        if (nums[r] == 0) {
            zeroes++;
        }
        while (zeroes > k) {
            if (nums[l] == 0) {
                zeroes--;
            }
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int longestOnes_Optimal(vector<int>& nums, int k) {
    int maxLen = 0;
    int zeroes = 0;
    int l = 0, r=0;
    while (r<nums.size()) {
        if(nums[r] == 0) zeroes++;
        if(zeroes > k) {
            if(nums[l]==0) zeroes--;
            l++;
        }
        if(zeroes <= k) maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

int main() {
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout << "max 1s with k flips (BF): " << max1sBF(nums, k) << endl;
    cout << "max 1s with k flips (optimized): " << longestOnes(nums, k) << endl;
}