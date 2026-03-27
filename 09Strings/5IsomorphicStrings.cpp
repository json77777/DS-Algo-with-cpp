#include <bits/stdc++.h>
using namespace std;

bool isomorphicString(string s, string t) {
    unordered_map<char,char> mp1; // for s
    unordered_map<char,char> mp2; // for t

    if(s.length() != t.length()) return false;

    for(int i=0; i<s.length(); i++)  {
        if(mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()) {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        else if(mp1.find(s[i]) != mp1.end()) {
            // instance with key is present
            if(mp1[s[i]] != t[i]) return false;
        }
        else if(mp2.find(t[i]) != mp2.end()) {
            if(mp2[t[i]] != s[i]) return false;
        }
    }
    return true;
}
  
int main() {
    
    string s = "paper";
    string t = "title";
    
    // Check if strings are isomorphic
    if (isomorphicString(s, t)) {
        cout << "Strings are isomorphic." << endl;
    } else {
        cout << "Strings are not isomorphic." << endl;
    }
    
    return 0;
}