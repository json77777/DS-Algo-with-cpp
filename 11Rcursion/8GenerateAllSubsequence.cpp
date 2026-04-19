#include <bits/stdc++.h>
using namespace std;

void generate_subsequnce(string s, string curr, vector<string> &ans, int i) {
    if(curr.length()==s.length() || curr.back() == ' ') {
        ans.push_back(curr);
        return;
    }

    // insert first
    generate_subsequnce(s,curr+s[i],ans,i);
}   

int main() {
    string s = "abc";
    string curr = "";
    vector<string> ans;
    generate_subsequnce(s,curr,ans, 0);
}