#include <bits/stdc++.h>
using namespace std;

// tc -> O(min(logn1,logn2))
double Kth_2sortedArr_OPTIMAL(vector<int> nums1, vector<int> nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2) return Kth_2sortedArr_OPTIMAL(nums2, nums1, k);

    int low = max(0, k-n2), high = min(k,n1);
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = k - mid1; // divide them in k | n-k

        int l1 = (mid1 == 0) ? INT_MIN :  nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];

        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if(l2 > r1) {
            low = mid1 + 1;
        } else high = mid1 - 1;
    }

    return 0;
}


int main() {
    vector<int> nums1 = {1,3,4,7,10,12}, nums2 = {2,3,6,15};
    int k = 5;
    cout << "Kth in 2sorted array (Optimal): " << Kth_2sortedArr_OPTIMAL(nums1,nums2, k) << endl;
}