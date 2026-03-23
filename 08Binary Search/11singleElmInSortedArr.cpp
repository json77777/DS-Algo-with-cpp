#include <bits/stdc++.h>
using namespace std;

int search_Single_Elm(vector<int> nums) {
    int low = 1, high=nums.size()-2, ans=-1;

    // edge cases
    if(nums.size()==1) return nums[0];
    if(nums[0] != nums[low]) return nums[0];
    if(nums[high+1] != nums[high]) return nums[high+1];

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

        // even,odd
        if(mid%2 == 0) {
            // element in left half
            if(nums[mid] == nums[mid+1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 
        // odd, even
        else {
            // element in right half
            if(nums[mid] == nums[mid+1]) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
    }
    // if no such thing present
    return -1;
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,4,5,5,6,6};
    cout << "Single element: " << search_Single_Elm(nums);
}