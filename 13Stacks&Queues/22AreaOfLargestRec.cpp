#include<bits/stdc++.h>
using namespace std;

int areaRec(vector<int> &heights) {
    stack<int> st; // storing indices
    int maxArea = 0;
    for(int i=0; i<heights.size(); i++) {
        if(st.empty() || heights[i] > heights[st.top()]) { // eqaulity check remains
            st.push(i);
        }
        else {
            // current element is smaller
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int top = heights[st.top()]; // take the top elm and cal area
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxArea = max(maxArea, (top * (nse - pse - 1)));
            }
            st.push(i);
        }
    }

    // for remaining elements
    while(!st.empty()) {
        int top = heights[st.top()]; 
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        int nse = heights.size();
        maxArea = max(maxArea, (top * (nse - pse - 1)));
    }

    return maxArea;
}


int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Area of largest rectangle: " << areaRec(heights) << endl;
}