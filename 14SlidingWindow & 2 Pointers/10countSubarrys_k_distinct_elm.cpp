#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int subarraysWithLessThanEqualKDistinct(vector<int>& nums, int k) {
    int l=0, r=0, count=0;
    unordered_map<int,int> mp; // elm,count
    while(r < nums.size()) {
        mp[nums[r]]++;
        while(mp.size() > k) {
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysWithLessThanEqualKDistinct(nums,k)-subarraysWithLessThanEqualKDistinct(nums,k-1);
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<int> nums = {1,2,1,2,3};
    int k=2;

    cout << "subarray count with k distinct elms: " << subarraysWithKDistinct(nums, k) << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}