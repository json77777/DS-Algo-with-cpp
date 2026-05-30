#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    // stack stores {price, span} pairs
    stack<pair<int,int>> st;

    StockSpanner() {}

    int next(int price) {
        int span = 1;  // at minimum, spans itself

        // Pop all prices smaller or equal to current
        // and absorb their spans
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // absorb their span
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main() {
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    
    /* Creating an instance of Solution class */
    StockSpanner sol;

    /* Call next for each price and collect spans */
    vector<int> ans;
    ans.reserve(n);
    for (int price : arr) {
        ans.push_back(sol.next(price));
    }

    cout << "The span of stock prices is: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}