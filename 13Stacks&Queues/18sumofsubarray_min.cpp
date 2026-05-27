#include <bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> PSEE(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int>& nums) {
    long long MOD = 1e9 + 7;
    int n = nums.size();
    vector<int> nse = NSE(nums);
    vector<int> pse = PSEE(nums);

    long long contribution = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        contribution = (contribution + (long long)nums[i] % MOD * left % MOD * right) % MOD;
    }

    return (int)contribution;
}

int main() {
    vector<int> nums = {11, 81, 94, 43, 3};
    cout << "Sum of minimums of all subarrays: " << sumSubarrayMins(nums) << endl;
}