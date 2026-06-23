#include<bits/stdc++.h>
using namespace std;

int SJF(vector<int>&jobs) {
    // sort it
    sort(jobs.begin(), jobs.end()) ;

    int timer=0, wt=0;

    for(auto i:jobs) {
        wt+=timer;
        timer+=i;
    }
    return wt/jobs.size();
}

int main() {
    vector<int> jobs = {3, 1, 4, 2, 5};
    cout << "avg waiting time: " << SJF(jobs) << endl;
}