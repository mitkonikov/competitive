#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    int p1 = 0, p2 = 0;
    while (p1 < S.size() && p2 < T.size()) {
        if (S[p1] == T[p2]) {
            p1++;
            p2++;
            continue;
        } else {
            p2++;
        }
    }
    cout << p1 << endl;
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