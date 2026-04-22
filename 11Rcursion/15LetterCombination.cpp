#include <bits/stdc++.h>
using namespace std;

void generateCombination(string input, vector<string> &ans, vector<string> phoneMap, int i) {
    for(int j=i; j<input.size(); j++) {
        generateCombination()
    }
}


int main() {
    vector<string> phoneMap = {
    "", "", "abc", "def", "ghi",   
    "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string input = "34";
    vector<string> ans;
    generateCombination(input, ans, phoneMap,0);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        }cout << endl;
    }


}