#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int i = num.length()-1;

    while(i >= 0 && (num[i] - '0') % 2 == 0) {
        i--;
    }

    if(i < 0) return "";

    return num.substr(0, i+1); // directly return
}

int main() {
    string num = "504";
    string result = largestOddNumber(num);
    cout << "Largest odd number: " << result << endl;
}
