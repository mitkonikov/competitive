#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    int N = S.size();
    
    bool same = true;
    for (int i = 0; i < N; i++) {
        if (S[i] != S[0]) same = false;
    }
    
    if (same) {
        cout << S[0] << " " << S.substr(1, N - 2) << " " << S[0] << endl;
        return;
    }
    
    for (int i = 1; i < N - 1; i++) {
        if (S[i] == 'a') {
            cout << S.substr(0, i) << " " << "a" << " " << S.substr(i + 1) << endl;
            return;
        }
    }

    cout << S[0] << " " << S.substr(1, N - 2) << " " << S.back() << endl;
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