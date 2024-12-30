#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (B < C) {
        cout << ((A < B || A > C) ? "Yes" : "No") << endl;
    } else {
        cout << ((C < A && A < B) ? "Yes" : "No") << endl;
    }
    return 0;
}