#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int sum = 0;
    vector<int> valid(N);
    for (int i = N - 1; i > 0; i--) {
        sum += (S[i] == '1' ? 1 : -1);
        if (sum > 0) {
            valid.push_back(sum);
        }
    }
    sort(valid.rbegin(), valid.rend());
    int ans = 1;
    for (int i = 0; K > 0 && i < valid.size(); i++) {
        K -= valid[i];
        ans++;
    }
    cout << (K > 0 ? -1 : ans) << endl;
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