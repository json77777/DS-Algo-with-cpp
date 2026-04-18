#include<iostream>
using namespace std;

float pow_optimal(int x, int n) {
    if(n==1) return x;
    if(n==0) return 1;
    
    if(n<0) {
        return 1/(float)pow_optimal(x,-n);
    }

    if(n%2) { // odd 
        return x * pow_optimal(x,n-1);
    } else {
        return pow_optimal(x*x, n/2);
    }

}

int main() {
    cout << pow_optimal(2,-2);
}