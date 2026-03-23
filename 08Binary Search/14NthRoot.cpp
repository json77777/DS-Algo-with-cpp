#include<bits/stdc++.h>
using namespace std;

int Nth_Root(int num, int x) {

    if (x <= 0) return -1; // invalid root
    if (num == 0) return 0;
    if (num == 1) return 1;

    int low = 1;
    int high = num;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long power = 1;
        for (int i = 0; i < x; ++i) {
            power *= mid;
            if (power > num) break;
        }

        if (power == num) {
            return mid;
        } else if (power < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // no integer root found
}

int main() {
    int num=27;
    int x = 3;
    cout << "Nth Root of " << num << ": " << Nth_Root(num,x) << '\n';
}