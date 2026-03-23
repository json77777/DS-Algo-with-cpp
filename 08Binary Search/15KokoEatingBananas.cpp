#include <bits/stdc++.h>
using namespace std;

long long f(vector<int> piles, int hourhly) {
    long long ans = 0;
    for(auto i:piles) {
        ans += ceil((double)i/hourhly);
    }
    return ans;
}


// tc -> O(nlogn + n)
int Koko_Eating_Banana(vector<int> piles, int h) {

    int low=1;
    int high = *max_element(piles.begin(), piles.end());
    int ans=1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        // calculate req time
        int reqTime = (int)f(piles,mid); // O(n)

        if(reqTime <= h) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    } return ans;
}

int main() {
    vector<int> piles = {7, 15, 6, 3};
    int h=8;

    cout << "Minimum k(bananas/hour) for koko to finish all banans: " << Koko_Eating_Banana(piles,h) << endl;
}