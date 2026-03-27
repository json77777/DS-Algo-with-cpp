#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int i = s.length()-1;
    string ans = "";
    while(i>=0) {
        // ignore spaces
        while(i >= 0 && s[i] == ' ') {
            i--;
        }
        if(i < 0) break;

        // mark the end 
        int end = i;
        while(i>=0 && s[i] != ' ') {
            i--;
        }

        if(ans.empty()) {
            ans += s.substr(i+1, end - i);
        }

        else ans += " " + s.substr(i+1, end - i); 
    }
    return ans;
}

int main() {
    string s = " amazing coding skills ";
    cout << reverseWords(s) << endl;
}
