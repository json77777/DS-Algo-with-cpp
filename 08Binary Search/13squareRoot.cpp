#include<bits/stdc++.h>
using namespace std;

int SquareRoot(int num) {

    if(num < 0) return -1;
    if(num == 1) return 1;

    int low = 1;
    int high = num;
    int ans = 1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(mid*mid <= num) {
            ans = mid;
            low=mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}

int main() {
    int num=9;
    cout << "Square Root of " << num << ": " << SquareRoot(num) << '\n';
}