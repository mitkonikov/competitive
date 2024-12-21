#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    set<int> values;
    for (int i = 0; i < N; i++) {
        values.insert(i + 1);
    }
    vector<int> ans(N);
    for (int i = K - 1; i < N; i += K) {
        ans[i] = *values.begin();
        values.erase(values.begin());
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] == 0) {
            ans[i] = *values.begin();
            values.erase(values.begin());
        }
    }
    for (auto el: ans) cout << el << " ";
    cout << endl;
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