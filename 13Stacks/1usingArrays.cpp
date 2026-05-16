#include <bits/stdc++.h>
using namespace std;

class stImp {
    public:
    int top=-1;
    int size=10;
    int arr[10];

    void push(int x) {
        if(top >= 10) {
            cout << "Overflow" << endl;
        }
        else {
            top++;
            arr[top] = x;
        }
    }

    int pop() {
        int el;
        if(top==-1) {
            cout << "Underflow" << endl;
        }
        else {
            el=arr[top];
            top--;
        }
        return el;
    }

    int peek() {
        if(top >= 10 || top == -1) {
            cout << "Not possible" << endl;
            return -1;
        }
        else {
            return arr[top];
        }
    }
};


int main() {
    stImp* a = new stImp();

    a->push(10);
    a->push(20);
    a->push(30);
    cout << a->peek() << endl;
    cout << a->pop() << endl;
}