#include<bits/stdc++.h>
using namespace std;

int countSubstring(string &s) {
    int count = 0;
    vector<int> lastSeen = {-1,-1,-1}; // for (a,b,c)

    for(int i=0; i<s.length(); i++) {
        lastSeen[s[i]-'a']=i; // update lastSeen

        int minLastSeen = *min_element(lastSeen.begin(), lastSeen.end());

        if(minLastSeen != -1) {
            count += 1 + minLastSeen;
        }
    }
    return count;
}

int main() {
    string s = "bbacba";
    cout << "no. of substring with all (a,b,c,): " << countSubstring(s) << endl;
}