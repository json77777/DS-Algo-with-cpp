#include<bits/stdc++.h>
using namespace std;

int max1sBF(vector<int> nums, int k) {
    // generate the longest subarrs with k 0s
    int c=k;
    int len = 0;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i; j<nums.size(); j++) {
            if(c && nums[j] == 0) c--;
            else if(!c) break;
            len = max(len,j-i+1);
        } c=k;
    }
    return len;
}

int longestOnes(vector<int>& nums, int k) {
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

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << "max 1s with k flips (BF): " << max1sBF(nums, k) << endl;
    cout << "max 1s with k flips (optimized): " << longestOnes(nums, k) << endl;
}