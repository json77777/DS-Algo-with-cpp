#include<bits/stdc++.h>
using namespace std;

int candy_BF(vector<int>&candy) {
    if(candy.empty()) return 0;
    vector<int> l(candy.size()),r(candy.size());

    l[0] = 1;
    for(int i=1; i<candy.size(); i++) {
        if(candy[i] > candy[i-1]) {
            l[i] = l[i-1]+1;
        }
        else l[i] = 1;
    }

    r[candy.size()-1] = 1;
    for(int i=candy.size()-2; i>=0; i--) {
        if(candy[i] > candy[i+1]) r[i] = r[i+1]+1;
        else r[i] = 1;
    }

    int ans=0;
    for(auto i=0;i<l.size();i++) ans+=max(l[i],r[i]);

    return ans;
}

int main() {
    vector<int> candy = {1, 0, 5};
    cout << "min candies needed to distribure(BF): " << candy_BF(candy) << endl;
}