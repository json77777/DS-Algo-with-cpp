#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {

    vector<vector<int>> ans;
    int n = intervals.size();
    int i = 0;

    // Add all intervals completely before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}


int main() {

    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = insert(intervals, newInterval);

    cout << "Result: ";
    for (auto &v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

}