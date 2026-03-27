#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    int c=0;
    string ans = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            c++;
            if(c>1) ans+='(';
        } else if(s[i]==')') {
            c--;
            if(c>0) ans+=')'; 
        }
    }
    return ans;
}

int main() {
    string s = "(()())(())";  

    // Get result
    string ans = removeOuterParentheses(s);

    // Print result
    cout << "The result is: " << ans << endl;

}