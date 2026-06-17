#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

bool cmp(pair<int,int> p, pair<int,int> q) {
    return ((double)p.first/p.second > (double)q.first/q.second);
}

int fractionalKnapsack(vector<pair<int,int>> &items, int wt) {
    sort(items.begin(),items.end(), cmp);
    int maxVal=0;
    for(auto i : items) {
        if(wt==0) break;
        if(i.second <= wt) {
            maxVal+=i.first;
            wt-=i.second;
        }
        else if(i.second > wt) {
            maxVal+= (i.first/i.second)*wt;
            wt = 0;
        }
    }

    return maxVal;
}

int main() {
    auto start = high_resolution_clock::now();
    
    vector<int> val = {60, 100, 120};
    vector<int> capacity = {10, 20, 30};
    int wt = 50;

    vector<pair<int,int>> items ;
    for(int i=0; i<val.size(); i++) {
        items.push_back({val[i], capacity[i]});
    }

    cout << "max total value: " << fractionalKnapsack(items, wt) << endl;
    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}