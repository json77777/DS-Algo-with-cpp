#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int n,string curr, int l_count, int r_count, vector<string>& ans) {
    if(l_count + r_count == 2*n && l_count-r_count == 0) {
        ans.push_back(curr);
        return;
    } 

    if(l_count > n || r_count > l_count) return;
    
    // put left parenthesis
    generateParenthesis(n,curr+"(",l_count+1, r_count, ans);
    

    // put right parenthesis
    if(curr.length()!=0 && l_count - r_count > 0) {
        generateParenthesis(n,curr+")", l_count, r_count+1, ans);
    }
}

int main() {
    int n=3; // pair of parenthesis
    string curr = "";
    int l_count = 0;
    int r_count = 0;
    vector<string> ans;
    generateParenthesis(n,curr,l_count, r_count, ans);

    for (string& s : ans) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}