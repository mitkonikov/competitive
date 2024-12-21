#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    // one is the whole string
    int N = S.size();
    if (N == 1) {
        cout << "1 1 1 1" << endl;
        return;
    }
    if (S[1] == '1') {
        for (int i = 1; i < N; i++) {
            if (S[i] == '1') continue;
            // S[i] == 0
            int count_zeros = 0;
            for (int l = i; l < N; l++) {
                if (S[l] == '0') count_zeros++;
                else break;
            }
            int left = max(0, i - count_zeros);
            int right = N - (i - left) - 1;
            cout << 1 << " " << N << " " << left + 1  << " " << right + 1 << endl;
            return;
        }
        cout << 1 << " " << N << " " << N - 1 << " " << N - 1 << endl;
    } else {
        cout << 1 << " " << N << " " << 1 << " " << N - 1 << endl;
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