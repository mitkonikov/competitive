#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'p') S[i] = 'q';
        else if (S[i] == 'q') S[i] = 'p';
    }
    reverse(S.begin(), S.end());
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