#include <bits/stdc++.h>
using namespace std;


int characterReplacement_BF(string s, int k) {
    int maxLen=0;

    for(int i=0; i<s.length(); i++) {
        // frequency count for characters in the current window
        int hash[26]={0}, maxFreq=0;

        for(int j=i; j<s.length(); j++) {
            hash[s[j]-'A']++; // increment frequency for this character
            maxFreq = max(maxFreq, hash[s[j]-'A']); // highest frequency in current window
            int conv = (j-i+1) - maxFreq; // replacements needed for current window
            if(conv <= k)
                maxLen = max(maxLen, j-i+1);
            else
                break; // further extension only increases replacements
        }
    }
    return maxLen;
}

int characterReplacement_Better(string s, int k) {
    int hash[26]={0}, maxFreq=0, maxLen=0;

    int l=0,r=0;
    while(r<s.length()) {
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq, hash[s[r]-'A']);
        if(r-l+1 - (maxFreq) > k) {
            hash[s[l]-'A']--;
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

int main() {
    string s = "BAABAABBBAAA";
    int k=2;

    cout << "longest character(BF): " << characterReplacement_BF(s,k) << endl;
    cout << "longest character(Better): " << characterReplacement_Better(s,k) << endl;
}