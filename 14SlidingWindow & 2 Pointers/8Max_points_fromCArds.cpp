#include <bits/stdc++.h>
using namespace std;

// Compute maximum points by taking exactly k cards from either
// the start or the end of the array. Uses a sliding/window-like
// approach: take first k cards, then iteratively move the split
// towards the right by removing one from the left sum and adding
// one from the right, tracking the maximum total.
int maxScore(vector<int>& cardPoints, int k) {
    int lSum = 0; // sum of cards taken from the left (start)
    int rSum = 0; // sum of cards taken from the right (end)
    int maxSum = 0;

    // initial take: first k cards from the left
    for (int i = 0; i < k; ++i) {
        lSum += cardPoints[i];
    }

    int endInd = static_cast<int>(cardPoints.size()) - 1;
    maxSum = lSum; // initial best is taking all k from left

    // move the split: for each step, return one card from left
    // and take one more card from the right, updating maxSum
    for (int i = k - 1; i >= 0; --i) {
        lSum -= cardPoints[i];
        rSum += cardPoints[endInd];
        --endInd;
        maxSum = max(maxSum, lSum + rSum);
    }
    return maxSum;
}

int main() {
    // Example usage (fixed values for quick testing)
    int n = 7; // number of cards (not used directly below)
    int k = 3; // number of cards to take
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};

    cout << maxScore(cardPoints, k) << '\n';
    return 0;
}

