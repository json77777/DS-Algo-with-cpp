#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& s) {
    sort(s.begin(), s.end());

    string first = s[0], last = s[s.size()-1];
    string ans = "";
    int c = 0;

    for(int i=0; i<min(first.length(), last.length()); i++) {
        if(first[i] == last[i]) c++;
        else {
            return ans += first.substr(0,i);
        }
    }
    return first;
}

int main() {

    vector<string> input = {"interview", "internet", "internal", "interval"};

    // Get the result
    string result = longestCommonPrefix(input);

    // Print the result
    cout << "Longest Common Prefix: " << result << endl; 

    return 0;
}
