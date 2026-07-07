#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string,bool> hash;
    for(auto i:wordList) {
        hash[i]=true;
    }

    queue<pair<string,int>> q;
    q.push({beginWord,1});

    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        string word = top.first;
        int len = top.second;

        if(word == endWord) {
            return len;
        }

        for(int i=0; i<word.length(); i++) {
            string temp = word;

            for(int j=0; j<26; j++) {
                temp[i]=char('a'+j);

                // check conditions
                if(hash.find(temp)!=hash.end()) { // temp is present 
                    q.push({temp,len+1});
                    hash.erase(temp); // erase from hashSet
                }
            }
        }
    }

    return 0;
}



int main() {
    auto start = high_resolution_clock::now();

    string st = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << "seq length: " << ladderLength(st,end,wordList) << endl;
}