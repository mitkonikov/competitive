#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int count = N - 1;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == S[i+1]) {
            if (i + 2 < N && S[i+2] == S[i]) {
                count--;
                continue;
            }
        } else {
            if (i + 2 < N && S[i] == S[i + 2]) {
                count--;
                continue;
            }
        }
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