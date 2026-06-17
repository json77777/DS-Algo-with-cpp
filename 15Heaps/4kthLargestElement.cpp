#include<bits/stdc++.h>
using namespace std;


 // BF
void heapifyDown(vector<int>&nums, int i) {
    int smallest = i;
    int l =  2*i+1;
    int r =  2*i+2 ;

    if(l == -1 && r == -1) {
        return;
    }
    if(l < nums.size() && nums[smallest] > nums[l]) smallest = l;
    if(r < nums.size() && nums[smallest] > nums[r]) smallest = r;
    if(smallest != i) {
        swap(nums[smallest],nums[i]);
        heapifyDown(nums,smallest);
    }
}

// O(nlog k)
int kthLargest(vector<int> &nums, int k) {
    // insert first k elms
    vector<int> heap(nums.begin(), nums.begin()+k);
    // insert first k
    
    // heapify down
    for(int j=0; j<k/2-1; j++) {
        heapifyDown(heap,j);
    }
    
    // for remainig elms
    int i=k;
    while(i < nums.size() && nums[i] > heap[0]) {
        swap(heap[0], nums[i]); // swap if top < nums[i]
        heapifyDown(heap,0); // heapify
        i++;
    }

    return heap[0];
    
}


// Optimal

int partition(vector<int>&nums, int l, int r) {
    int randInd = l + rand() % (r-l+1); // random no. between [l,r]
    swap(nums[randInd], nums[l]);
    int pivot = nums[l];
    int i = l+1;
    for(int j = l + 1; j <= r; j++) {
        if(nums[j] > pivot) {      // larger → left side
            swap(nums[i], nums[j]);
            i++;
        }
    }

    // place pivot in correct position
    swap(nums[l], nums[i-1]);
    return i-1;   // pivot's final index
}

int kthLargest_Optimal(vector<int>&nums, int l, int r, int k) {
    int pivotIdx = partition(nums, l, r);

    if(pivotIdx == k-1) return nums[pivotIdx];  // found!
    else if(pivotIdx > k-1) return kthLargest_Optimal(nums, l, pivotIdx-1, k);  // go left
    else  return kthLargest_Optimal(nums, pivotIdx+1, r, k);
    
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k=2;

    cout << "kth largest: " << kthLargest_Optimal(nums, 0,nums.size()-1, k) << endl;
    
}