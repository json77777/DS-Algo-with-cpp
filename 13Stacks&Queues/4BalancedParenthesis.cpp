#include <bits/stdc++.h>
using namespace std;

bool balancedParenthesis(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);

        else {
            if(st.empty()) return false;
            if(s[i] == ')' && st.top() == '(') st.pop();
            else if(s[i] == '}' && st.top() == '{') st.pop();
            else if(s[i] == ']' && st.top() == '[') st.pop();
            else return false;
        }
    }

    return st.empty();
}

int main() {
    stack<int> st;
    string s = "()[{}()]";
    cout << balancedParenthesis(s);
}