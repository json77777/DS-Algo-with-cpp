#include<bits/stdc++.h>
using namespace std;

// same appraoch as prev ques

int f(vector<int>& nums, int k) { // count subarrays less than equal to k
    if (k < 0)
        return 0;
    // convert the odd to 1 and even to 0
    // problem becomes count subbarys of sum <= k
    for (auto &i : nums) {
        if (i % 2==0)
            i = 0;
        else
            i = 1;
    }
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (sum > k) {
            sum = sum - nums[l];
            l++;
        }
        count = count += (r - l + 1);
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    
    return f(nums,k) - f(nums,k-1);
}

int main() {
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    cout << "number of nice subarrays: " << numberOfSubarrays(nums,k) << endl;
}