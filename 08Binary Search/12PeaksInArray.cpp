#include <bits/stdc++.h>
using namespace std;

int search_Peak_Elm(vector<int> nums) {
    int low = 1, high=nums.size()-2, ans=-1;

    // edge cases
    if(nums.size()==1) return nums[0];
    if(nums[0] > nums[low]) return nums[0];
    if(nums[high+1] > nums[high]) return nums[high+1];

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return nums[mid];

        // left slop
        if(nums[mid] > nums[mid-1]) {
            low = mid+1;
        }
        else if(nums[mid] > nums[mid+1]) {
            high = mid - 1;
        }
        // go to any peak
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << "Peak element: " << search_Peak_Elm(nums);
}