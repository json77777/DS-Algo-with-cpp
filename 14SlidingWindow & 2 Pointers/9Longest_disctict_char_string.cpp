#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;

int longestString_K_Atmost(string s, int k) {
    int l=0,r=0,maxLen=0;
    unordered_map<int,int> mp; // elm,freq

    while(r<s.length()) {
        mp[s[r]]++; // update freq
        // remove until size <= k
        while(mp.size() > k) {
            mp[s[l]]--; // freq reduc
            if(mp[s[l]] == 0) mp.erase(s[l]); // if freq==0 remove from map
            l++;
        }
        maxLen = max(maxLen, r-l+1) ;
        r++;
    }
    return maxLen;
}

int main() {

    auto st = high_resolution_clock::now();
    
    string s = "aababbcaacc";
    int k=2;
    
    cout << "longest substring with k at most distinct char: " << longestString_K_Atmost(s,k) << endl;
    auto end = high_resolution_clock::now();
    cout << "Time taken: " << duration_cast<milliseconds>(end - st).count() << " ms\n";
}

