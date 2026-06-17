#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;

int kthSmallest(int k) {
    if(minHeap.size() < k) return INT_MIN;
    while(k>1) {
        minHeap.pop();
        k--;
    }
    return minHeap.top();
}

int main() {

    minHeap.push(8);
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(9);

    int k=2;

    cout << "kth largest: " << kthSmallest(k) << endl;
    
}