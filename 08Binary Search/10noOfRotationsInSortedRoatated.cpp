#include <bits/stdc++.h>
using namespace std;

int rotate_nums(vector<int>nums) {
    int low=0, high=nums.size()-1, ans = INT_MAX,idx=-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(nums[low] <= nums[mid]) {
            if(nums[low] < ans) {
                ans=nums[low];
                idx=low;
            }
            low=mid+1;
        }
        else {
            if(nums[mid] < ans) {
                ans=nums[mid];
                idx=mid;
            }
            high=mid-1;
        }
    }
    return idx;
} 

int main() {
    vector<int> nums = {4,5,6,7,0,1,2,3};
    cout << "arr is rotated " << rotate_nums(nums);
}