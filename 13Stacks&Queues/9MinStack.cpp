#include <bits/stdc++.h>
using namespace std;

class minSt {
    public:
    stack<pair<int,int>> s;

    void push(int x) {
        if(s.empty()) {
            s.push({x,x});
        }
        else {
            s.push({x, min(x,s.top().second)});
        }
    }

    int pop() {
        int el;
        if(s.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        else {
            el = s.top().first;
            s.pop();
        }
        return el;
    }

    int top() {
        if(s.empty()) {
            cout << "No element\n";
            return -1;
        }
        else {
            return s.top().first;
        }
    }

    int getMin() {
        if(s.empty()) {
            cout << "No element\n";
            return -1;
        }
        return s.top().second;
    }
};

int main() {
    
}