#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

string PostfixToInfix(string ip) {
    stack<string> st;

    for(int i=0; i<ip.length(); i++) {
        // add operands
        if(!isOperator(ip[i])) st.push(string(1, ip[i]));

        // operators
        else {
            if(!st.empty()) {
                string second = st.top();
                st.pop();
                string first = st.top();
                st.pop();
                first = "(" + first + string(1,ip[i]) + second + ")";
                st.push(first);
            }
        }
    }


    return st.top();
}

int main() {
    string ip = "AB-DE+F*/";
    cout << "postfix to infix: " << PostfixToInfix(ip) << endl;
}