#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.length()!=goal.length()) return false;
    string S = s+s;

    if(S.find(goal) != string::npos) return true;
    else return false;
}

int main() {

    string s = "rotation";
    string goal = "tionrota";
    cout << (rotateString(s, goal) ? "true" : "false") << endl;

    return 0;
}