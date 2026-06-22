#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool cmp(const vector<int> &p, const vector<int> &q) {
    // sort acc to profit
    return p[2] > q[2];
}

pair<int,int> JobSequence(vector<vector<int>> &Job) {

    int maxDeadLine = -1;
    for(auto i: Job) {
        maxDeadLine = max(maxDeadLine, i[1]);
    }

    sort(Job.begin(), Job.end(), cmp);

    int count=0;
    int profit = 0;

    // days
    vector<int> slot(maxDeadLine + 1, -1);

    for(int i=0; i<Job.size(); i++) {
        if(count == maxDeadLine) break;
        
        // place at correct position

        int j = Job[i][1];
        while(j > 0) {
            if(slot[j] == -1) {
                slot[j] = Job[i][0];
                profit+=Job[i][2];
                count++;
                break; // ensures no more slot is used to place the same job
            }
            j--;
        }
    }
    

    return {count,profit};
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<vector<int>> Job = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    pair<int,int> ans = JobSequence(Job);
    cout << "no. of jobs: " << ans.first << " max profit: " << ans.second << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}
