#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

string PrefixToInfix(string ip) {
    stack<string> st;

    for(int i=ip.length()-1; i>=0; i--) {
        // add operands
        if(!isOperator(ip[i])) st.push(string(1, ip[i]));

        // operators
        else {
            if(!st.empty()) {
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                first = "(" + first + string(1,ip[i]) + second + ")";
                st.push(first);
            }
        }
    }

    
    return st.top();
}

int main() {
    string ip = "*+PQ-MN";
    cout << "postfix to infix: " << PrefixToInfix(ip) << endl;
}