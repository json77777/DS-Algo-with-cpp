#include <bits/stdc++.h>
using namespace std;

vector<int> arr(26,0);

bool CheckAnagrams(string s1, string s2) {
    if(s1.length()!=s2.length()) return false;

    for(int i=0; i<s1.length(); i++) {
        arr[s1[i]-'A']++;
    }

    for(int i=0; i<s2.length(); i++) {
        arr[s2[i]-'A']--;
    }

    // if all elements are 0 then true
    for(int i:arr) {
        if(i) return false;
    }
     return true;
}

int main() {
    string Str1 = "INTEGER";
    string Str2 = "TEGERNI";

    // Check if the strings are anagrams and output the result
    if (CheckAnagrams(Str1, Str2))
        cout << "True" << endl;  // Output "True" if they are anagrams
    else
        cout << "False" << endl;  // Output "False" if they aren't anagrams

    return 0;
}