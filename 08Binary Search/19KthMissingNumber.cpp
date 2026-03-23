#include <bits/stdc++.h>
using namespace std;

int kthMissing(vector<int> nums, int k) {
    int low = 0, high = nums.size()-1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        int missing = nums[mid] - (mid + 1);
        if( missing <= k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high+1+k;

}

int main() {
    vector<int> nums = {4,7,9,10};
    int k = 1;

    cout << "Kth Missing Number for k=" << k << " is: " << kthMissing(nums, k) << endl;
    
}