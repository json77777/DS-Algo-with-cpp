#include <bits/stdc++.h>
using namespace std;

int func_XOR_table(int n) {
    if (n <= 0) return 0;
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

int XOR_Range(int l, int r) {
    return func_XOR_table(l-1)^func_XOR_table(r);
}

int main() {
    int l=7, r=13;
    cout << XOR_Range(l,r) << endl;
}