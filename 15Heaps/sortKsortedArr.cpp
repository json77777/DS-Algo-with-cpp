#include<bits/stdc++.h>
using namespace std;

// Sort a k-sorted array using a min-heap.
// In a k-sorted array every element is at most k positions away
// from its sorted position.
// Time Complexity: O(n log k)
// Space Complexity: O(k)
void sort_K_sorted_BF(vector<int>&nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minh;
    int i=0, j=k+1;
    // minheap for first k+1;
    while(k>=0) {
        minh.push(nums[i]);
        k--;
        i++;
    }

    while(i<nums.size()) {
        nums[i-j] = minh.top();
        minh.push(nums[i]);
        i++;
        minh.pop();
    }
    // push the remaining elms
    while(minh.size()) {
        nums[i-j] = minh.top();
        i++;
        minh.pop();
    }
}

int main() {
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sort_K_sorted_BF(nums,k);
    for(auto i:nums) {
        cout << i << " ";
    } cout << endl;
}