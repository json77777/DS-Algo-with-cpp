#include<bits/stdc++.h>
using namespace std;

bool cmp(const vector<int>&p, const vector<int>&q) {
    return p[0] < q[0];
}

vector<vector<int>> insert(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> ans;
    int n = intervals.size();

    if (n == 0) return ans;

    int mini = intervals[0][0];
    int maxi = intervals[0][1];

    for (int i = 1; i < n; i++) {

        // overlap
        if (intervals[i][0] <= maxi) {
            maxi = max(maxi, intervals[i][1]);
        }
        // no overlap
        else {
            ans.push_back({mini, maxi});
            mini = intervals[i][0];
            maxi = intervals[i][1];
        }
    }

    ans.push_back({mini, maxi});

    return ans;
}

int main() {

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = insert(intervals);

    cout << "Result: ";
    for (auto &v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

}