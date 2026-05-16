#include <bits/stdc++.h>
using namespace std;

class Qimt {
    public:
    int size=5;
    int currSize=0;
    int start=-1,end=-1;
    int arr[5];

    void push(int x) {
        // check size
        if(currSize < size) {
            if(start == -1 && end == -1) {
                start++,end++;
            }
            else {
                end=(end+1)%size;
            }
            arr[end] = x;
            currSize++;
        }
    }

    int pop() {
        int el;
        // check size
        if(currSize == 1) {
            el = arr[start];
            start=end=-1;
        }
        else {
            el = arr[start];
            start = (start+1)%size;
        }
        currSize--;
        return el;
    }


    int top() {
        if(start == -1 && end == -1) {
            return INT_MIN;
        }
        return arr[start];
    }
};

int main() {
    Qimt* a = new Qimt();
    cout << a->currSize << endl;
    cout << a->size << endl;
    cout << a->start << endl;
    cout << a->end << endl;
    cout << a->top() << endl;
    cout << endl;
    a->push(7);
    a->push(72);
    a->push(73);
    a->push(17);
    cout << a->currSize << endl;
    cout << a->size << endl;
    cout << a->start << endl;
    cout << a->end << endl;
    cout << a->top() << endl;

    cout << "popped element: " << a->pop() << endl;
    cout << a->start << endl;
    cout << a->end << endl;

    a->push(107);
    cout << a->start << endl;
    cout << a->end << endl;

    
    a->push(1087);
    cout << "pushed element: 1087" << endl; 
    cout << a->start << endl;
    cout << a->end << endl;
    cout << a->currSize << endl;

}