#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A == C) {
        cout << (D < B ? "Yes" : "No") << endl;
    } else {
        cout << (C < A ? "Yes" : "No") << endl;
    }
    return 0;
}