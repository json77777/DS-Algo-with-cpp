#include <bits/stdc++.h>
using namespace std;

// 1
void swap(int a, int b) {
    a=a^b;
    b=a^b;
    a=a^b;
    cout << a << " " << b << endl;
}

// 2
void checkBit(int n, int i) {
    // n-> number, i -> position
    if( n & (1 << i) ) cout << "yes";
    else cout << "no";
    cout << endl;
}


// 3
void setBit(int n, int i) {
    // n -> number i-> bit to set
    cout << (n | (1 << i)) << endl;
}


// 4
void resetBit(int n, int i) {
    // n -> number i-> bit to set
    cout << (n & ~(1 << i)) << endl;
}


// 5 toggle ith bit
void toggleIthBit(int n, int i) {
    cout << (n ^ (1 << i)) << endl;
}


// 6
void clearRightMostSetbit(int n) {
    cout << (n & n-1) << endl;
}


// 7
// power of 2
void checkPowOf2(int n) {
    if(n<=0) cout << "no";
    else if(n & n-1) cout << "no";
    else cout << "yes" ;
    cout << endl;
}


// count setbits
void countSetBits(int n) {
    int c=0;
    while(n) {
        //  n & 1 -> odd check
        c += n&1; // if it gives 1 that means remainder use the case of 13&1 gives 1 last bit
        n = n>>1; // divide by 2
    }
    cout << c << endl;
}

void countSetBits_second(int n) {
    int c=0;
    while(n) {
        n = n & (n-1);
        c++;
    }

    cout << "Second way: " << c << endl;
}

int main() {
    int a=5,b=6;
    swap(a,b);
    checkBit(13,2);
    setBit(9,2);
    resetBit(9,2);
    toggleIthBit(13,2);
    clearRightMostSetbit(12);
    checkPowOf2(16);
    countSetBits(15);
    countSetBits_second(15);
    // built in setbit count
    cout << (15) << endl;
    
}