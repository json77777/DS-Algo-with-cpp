#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes: marks non-prime numbers in the boolean array.
void seiveOfEratostheves(vector<bool>&primes) {
    // Start from 2 because 0 and 1 are not prime numbers.
    for(int i=2; i*i<=primes.size(); i++) {
        // Process only numbers that are still marked as prime.
        if(primes[i] == 1) {
            // Mark all multiples of i as non-prime, starting from i*i.
            for(int j=i*i; j<primes.size(); j+=i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    int l = 30;
    // Initially assume every number is prime.
    vector<bool> primes(l,1);

    seiveOfEratostheves(primes);

    // Print all prime numbers found by the sieve.
    for(int i=2; i<primes.size(); i++) {
        if(primes[i]) cout << i << " ";
    }cout << endl;
}