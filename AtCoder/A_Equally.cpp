#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B == C || A + C == B || B + C == A || (A == B && B == C)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}