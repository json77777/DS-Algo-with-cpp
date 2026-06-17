#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    // check whether it can be devided
    if(hand.size() % groupSize != 0) {
        return false;
    }

    map<int,int> freq; // unique and sorted
    for(auto i:hand) freq[i]++;

    // iterate over the map
    for( auto &[card, count] : freq) {
        if(!count) continue;
        // current neeed
        int need = count;
        for(int i=card; i<card+groupSize; i++) {
            if(freq[i] < need) return false;
            freq[i] -= need;
        }
    }

    return true;

}

int main() {
    vector<int> hand = {1,2,3,6,2,3,4,7};
    int groupSize = 3;
    cout << "can be stored: " << isNStraightHand(hand, groupSize);
}