#include <bits/stdc++.h>
using namespace std;

double Median_BF(vector<int> nums1, vector<int> nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> ans;

    int i=0, j=0;
    while(i < n1 && j < n2) {
        if(nums1[i] <= nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
        }
        else {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while(i < n1) {
       ans.push_back(nums1[i]);
        i++; 
    }

    while(j < n2) {
       ans.push_back(nums2[j]);
        j++; 
    }

    if(ans.size()%2 == 1) return ans[ans.size()/2];
    else return (double)(ans[ans.size()/2] + ans[ans.size()/2 - 1])/2.0;
}


double Median_BETTER(vector<int> nums1, vector<int> nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n=n1+n2;
    int ind1 = n/2;
    int ind2 = ind1 - 1;
    int c=0;
    double el1 = -1, el2 = -1;

    // 
    int i=0, j=0;
    while(i < n1 && j < n2) {
        if(nums1[i] <= nums2[j]) {
            if(c == ind1) el1 = nums1[i];
            if(c == ind2) el2 = nums1[i];
            i++;
            c++;
        }
        else {
            if(c == ind1) el1 = nums2[j];
            if(c == ind2) el2 = nums2[j];
            j++;
            c++;
        }
    }

    while(i < n1) {
        if(c == ind1) el1 = nums1[i];
        if(c == ind2) el2 = nums1[i];
        i++;
        c++;
    }

    while(j < n2) {
        if(c == ind1) el1 = nums2[j];
        if(c == ind2) el2 = nums2[j];
        j++;
        c++;
    }

    if(n%2 == 1) return el1;
    else return (double)(el1 + el2) / 2.0;
}

// tc -> O(min(logn1,logn2))
double Median_OPTIMAL(vector<int> nums1, vector<int> nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2) return Median_OPTIMAL(nums2, nums1);

    int low = 0, high = n1;
    while(low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = (n1 + n2 + 1) / 2 - mid1;

        int l1 = (mid1 == 0) ? INT_MIN :  nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];

        int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

        if(l1 <= r2 && l2 <= r1) {
            if((n1 + n2) % 2 == 1) {
                return max(l1, l2);
            } else {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        } else if(l2 > r1) {
            low = mid1 + 1;
        } else high = mid1 - 1;
    }

    return 0;
}


int main() {
    vector<int> nums1 = {1,3,4,7,10,12}, nums2 = {2,3,6,15};

    cout << "Median (BF): " << Median_BF(nums1,nums2) << endl;
    cout << "Median (Better): " << Median_BETTER(nums1,nums2) << endl;
    cout << "Median (Optimal): " << Median_OPTIMAL(nums1,nums2) << endl;
}