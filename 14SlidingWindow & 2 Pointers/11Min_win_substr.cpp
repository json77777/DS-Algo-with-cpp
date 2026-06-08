#include<bits/stdc++.h>
using namespace std;

string minWindow_BF(string s, string t) {
    int minLen = INT_MAX;
    int stInd = -1;

    for(int i = 0; i < s.size(); i++) {
        unordered_map<char, int> mp;

        for(char c : t)
            mp[c]++;

        int count = 0;

        for(int j = i; j < s.size(); j++) {
            if(mp[s[j]] > 0)
                count++;

            mp[s[j]]--;

            if(count == t.size()) {
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    stInd = i;
                }
                break;
            }
        }
    }

    return stInd == -1 ? "" : s.substr(stInd, minLen);
}

int main() {
    string s="ADOBECODEBANC";
    string t = "ABC";

    cout << "min window substring(BF): " << minWindow_BF(s,t) << endl;

}