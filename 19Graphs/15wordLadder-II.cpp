#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> hash(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    if (!hash.count(endWord)) return ans;

    queue<vector<string>> q;
    q.push({beginWord});
    hash.erase(beginWord);
    bool found = false;

    while (!q.empty() && !found) {
        unordered_set<string> usedThisLevel;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            vector<string> path = q.front(); q.pop();
            string last = path.back();

            for (int j = 0; j < last.size(); j++) {
                string temp = last;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[j] = ch;
                    if (hash.count(temp)) {
                        vector<string> newPath = path;
                        newPath.push_back(temp);
                        if (temp == endWord) {
                            ans.push_back(newPath);
                            found = true;
                        } else {
                            q.push(newPath);
                        }
                        usedThisLevel.insert(temp);
                    }
                }
            }
        }
        // erase only after the whole level is processed
        for (auto& w : usedThisLevel) hash.erase(w);
    }
    return ans;
}


int main() {

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