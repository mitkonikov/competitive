#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool ans = true;
    int sq = sqrt(N);
    if (sq * sq != N) {
        cout << "No" << endl;
        return;
    }
    bool first = 1, last = 1;
    for (int i = 0; i < sq; i++) {
        first &= (S[i] == '1');
        last &= (S[N-i-1] == '1');
    }
    ans &= first & last;
    bool outside = true, inside = true;
    for (int r = 1; r < sq - 1; r++) {
        for (int i = 1; i < sq - 1; i++) {
            inside &= (S[r * sq + i] == '0');
        }
        outside &= (S[r * sq] == '1');
        outside &= (S[r * sq + sq - 1] == '1');
    }
    ans &= outside & inside;
    cout << (ans ? "Yes" : "No") << endl;
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