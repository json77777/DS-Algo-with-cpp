#include<bits/stdc++.h>
using namespace std;

int assignCookie(vector<int> student, vector<int> cookie) {
    int i=0, j=0;
    sort(student.begin(), student.end());
    sort(cookie.begin(), cookie.end());

    int c = 0;

    while(i < student.size() && j < cookie.size()) {
        // check if cookie can be assigned
        if(student[i] <= cookie[j]) {
            i++,j++,c++;
        }
        else {
            j++; // move to higher cookie
        }
    }
    return c;
}

int main() {
    vector<int> students = {1,2,3};
    vector<int> cookies = {1,1};
    cout << "max students: " << assignCookie(students,cookies);
}