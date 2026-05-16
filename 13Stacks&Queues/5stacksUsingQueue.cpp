#include<bits/stdc++.h>
using namespace std;

class st_Q {
    public:
    queue<int> q;
    int currSize=0;
    
    void push(int x){ 
        int n = q.size();
        q.push(x);
        for(int i=0; i<n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(!q.size()) {
            cout << " under flow" << endl;
            return INT_MIN;
        }
        else {
            int el = q.front();
            q.pop();
            return el;
        }
    }

    int peek() {
        if(q.empty()) {
            cout << " No elements" << endl;
            return INT_MIN;
        }
        return q.front();
    }
};

int main() {
    st_Q * a = new st_Q();
    a->push(5);
    a->push(2);
    a->push(4);
    cout << a->pop() << endl;
}