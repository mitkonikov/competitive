#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i + 1 < N; i++) {
        if (S[i] > S[i+1]) {
            // delete S[i]
            char t = S[i];
            S.erase(S.begin() + i);
            bool found = false;
            for (int j = i; j < N; j++) {
                if (S[j] > t) {
                    S.insert(S.begin() + j, t);
                    found = true;
                    break;
                }
            }
            if (!found) S.push_back(t);
            cout << S << endl;
            return;
        }
    }
    cout << S << endl;
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