#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> frq(26);
    for (int i = 0; i < N; i++) {
        frq[S[i] - 'a']++;
    }
    if (N % 2 == 0) {
        for (int i = 0; i < 26; i++) {
            if (frq[i] > 0 && frq[i] % 2 == 1) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    } else {
        int c = 0, p = 0;
        for (int i = 0; i < 26; i++) {
            if (frq[i] % 2 == 1) c++;
            if (frq[i]) p++;
        }
        if (c > 1) {
            cout << 0 << endl;
        } else {
            cout << (p > 1 ? 1 : 2) << endl;
        }
    }
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