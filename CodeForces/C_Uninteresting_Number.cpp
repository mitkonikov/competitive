#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    // 1->1
    // 2->4
    // 3->9
    string S;
    cin >> S;
    int N = S.size();
    ll sum = 0;
    int twos = 0, threes = 0;
    for (int i = 0; i < N; i++) {
        sum += S[i] - '0';
        if (S[i] == '2') twos++;
        else if (S[i] == '3') threes++;
    }
    bool ok = false;
    for (int i = 0; i <= min(9, twos); i++) {
        for (int j = 0; j <= min(9, threes); j++) {
            ok |= (sum + i * 2 + j * 6) % 9 == 0;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
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