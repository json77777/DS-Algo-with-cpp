#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void dfs(string endWord, map<string,bool> hash, vector<string> temp, vector<vector<string>> &ans) {
    if(temp.back() == endWord) {
        ans.push_back(temp);
        return;
    }

    string word = temp.back();
    for (int i = 0; i < word.size(); i++) {
        char original = word[i];

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (ch == original) continue;
            word[i] = ch;

            if (hash.count(word)) {
                temp.push_back(word);
                hash.erase(word);

                dfs(endWord, hash, temp, ans);
                temp.pop_back();
            }
        }

        word[i] = original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // create a map
    map<string,bool> hash;
    for(auto i:wordList) {
        hash[i]=true;
    }

    // prepare for dfs calls
    vector<vector<string>> ans;
    vector<string> temp;
    temp.push_back(beginWord);
    
    dfs(endWord, hash, temp, ans);

    return ans;
}


int main() {
    auto start = high_resolution_clock::now();

    string st = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> ans =  findLadders(st,end,wordList);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }
}