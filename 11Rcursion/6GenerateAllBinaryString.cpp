#include<bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string>&ans) {
    if(curr.length()==n) {
        ans.push_back(curr);
        cout << curr << endl;
        return;
    }

    // store 0
    generate(n,curr+"0", ans);

    // store 1
    if(curr.empty() || curr.back()!='1') {
        generate(n,curr+"1",ans);
    }
}


int main() {
    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}