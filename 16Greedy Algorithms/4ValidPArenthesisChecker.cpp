#include<bits/stdc++.h>
using namespace std;

// tc -> 3powern, Sc -> O(n)
bool parenthesisCheck_BF(string s, int i, int c) {
    if(c < 0) return false; // didn't have any opening brack
    if(i==s.length()) {
        return c==0;
    }

    if(s[i] == '(') return parenthesisCheck_BF(s, i+1, c+1);
    if(s[i] == ')') return parenthesisCheck_BF(s, i+1, c-1);
    else return parenthesisCheck_BF(s, i+1, c+1) || parenthesisCheck_BF(s, i+1, c-1) || parenthesisCheck_BF(s, i+1, c);
}

// tc -> O(n), sc -> O(1)
bool parenthesisCheck_Optimal(string s) {
    int l=0,r=0;
    for(auto i:s) {
        if(i=='(') {
            l++,r++;
        }
        else if(i == '*') {
            if(l > 0) l--;
            r++;
        }
        else if(i == ')') {
            if(l > 0) l--;
            r--;
        }
        if (r < 0) return false;   
    }
    return l==0;
}


int main() {
    string s = "(*))";
    int i=0, c=0;
    cout << "valid parenthesis: " << parenthesisCheck_BF(s, i, c) << endl;
    cout << "valid parenthesis: " << parenthesisCheck_Optimal(s) << endl;
}