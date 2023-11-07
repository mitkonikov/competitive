#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<int, int> last;
    vector<int> ans(N, 1);
    int p = 2;
    for (int i = 0; i < N; i++) {
        if (last.find(A[i]) == last.end()) {
            last[A[i]]++;
        } else {
            if (last[A[i]] >= 2) continue;
            if (p == 4) continue;
            ans[i] = p++;
            last[A[i]]++;
        }
    }
    if (p != 4) {
        cout << -1 << endl;
        return;
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