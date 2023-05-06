#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
void testCase() {
    string CF = "codeforces";
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (S[i] != CF[i]) count++;
    }
    cout << count << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        testCase();
    }
 
    cout << flush;
    return 0;
}