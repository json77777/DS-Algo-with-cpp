#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

string PostFixToPrefix(string ip) {
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
                first = string(1,ip[i]) + first + second ;
                st.push(first);
            }
        }
    }


    return st.top();
}

int main() {
    string ip = "AB-DE+F*/";
    cout << "postfix to prefix: " << PostFixToPrefix(ip) << endl;
}