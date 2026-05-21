#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> nums){
    stack<int> st;
    vector<int> ans(nums.size(),0);
    for(int i = nums.size()-1; i>=0; i--) {
        if(st.empty()) {
            ans[i] = -1;
        }
        else if(st.top() < nums[i]) {
            ans[i] = st.top();
        }
        // pop out until st.top < nums[i]
        else {
            while(!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top(); 
        }
        // push the curr element
        st.push(nums[i]);
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 8,5,2,25};
    vector<int> ans = nextSmaller(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}