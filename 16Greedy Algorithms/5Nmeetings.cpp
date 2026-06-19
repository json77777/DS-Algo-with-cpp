#include<bits/stdc++.h>
using namespace std;

bool cmp(const vector<int> &p, const vector<int> &q) {
    return p[1] < q[1];
}

vector<int> maxMeetings(vector<vector<int>> &meet) {
    // sort meet with end[]
    sort(meet.begin(), meet.end(), cmp);

    vector<int> ans;

    // mark the st, end and push the (index+1). to 1 based
    int st = meet[0][0];
    int end = meet[0][1];
    ans.push_back(meet[0][2]+1);


    for(int i=1; i<meet.size(); i++) {
        if(meet[i][0] > end) {
            st = meet[i][0];
            end = meet[i][1];
            ans.push_back(meet[i][2]+1);
        }
    }
    
    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    vector<vector<int>> meet;
    for(int i=0; i<start.size(); i++) {
        meet.push_back({start[i],end[i], i});
    }

    vector<int> res = maxMeetings(meet);

    for (int idx : res) cout << idx << " ";
}