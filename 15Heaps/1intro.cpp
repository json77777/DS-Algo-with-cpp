#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;


class Heap {
    public:
    int *arr;
    int size;
    int capacity=100;

    Heap() {
        size = 0;
        arr = new int[capacity];
    }

    // will be performig minHeap

    int parent(int i) {
        return (i-1)/2;
    }
    
    int lChild(int i) {
        return (2*i+1);
    }
    
    int rChild(int i) {
        return (2*i+2);
    }

    // insert 
    void insert(int val) {
        if(size == capacity) {
            cout << "Overflow" << endl;
            return;
        }
        arr[size] = val;
        int k=size;
        size++;
        
        while(k > 0 && arr[parent(k)] > arr[k]) {
            swap(arr[k], arr[parent(k)]);
            k=parent(k);
        }
    }

    // heapify
    void heapifyDown(int i) {
        int smallest = i;
        int l = lChild(i);
        int r = rChild(i);

        if(l < size && arr[l] < arr[smallest]) smallest = l;
        if(r < size && arr[r] < arr[smallest]) smallest = r;

        if(smallest != i) {
            swap(arr[smallest], arr[i]);
            heapifyDown(smallest);
        }
    }

    int getMin() {
        if(size == 0) {
            cout << "no element present: " << endl;
            return -1;
        }
        return arr[0];
    }

    // removes the min element
    void extractMin() {
        if(size == 0) {
            cout << "no element present: " << endl;
            return ;
        }
        // swap the last elm with the first
        swap(arr[size-1], arr[0]);
        // reduce size
        size--;
        // heapify from top
        heapifyDown(0);
    }

    void decreaseKey(int i, int v) {
        arr[i] = v;

        while(i > 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    //delete from heap
    void deleteFromHeap(int i) {
        decreaseKey(i,INT_MIN);
        extractMin();
    }


    // display
    void display() {
        if(size == 0) {
            cout << "pls insert element" << endl;
            return;
        }
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }
};


int main() {
    auto start = high_resolution_clock::now();
    
    Heap h;

    // insert
    h.insert(10); h.insert(5); h.insert(3);
    h.insert(8);  h.insert(1);
    h.display();  // 1 5 3 8 10

    // getMin + extractMin
    cout << "Min: " << h.getMin() << endl;  // 1
    h.extractMin();
    h.display();  // 3 5 10 8

    // decreaseKey
    h.decreaseKey(3, 2);
    h.display();  // 2 should be near root

    // deleteFromHeap
    h.deleteFromHeap(1);
    h.display();

    // sorted order — validates everything
    Heap h2;
    h2.insert(20); h2.insert(15); h2.insert(30);
    h2.insert(5);  h2.insert(10);
    while(h2.size > 0) {
        cout << h2.getMin() << " ";  // expected: 5 10 15 20 30
        h2.extractMin();
    }
    cout << endl;

    
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
}