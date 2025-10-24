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
    set<int> s, new_set;
    s.insert(A[0]);
    int ans = 1;
    for (int i = 1; i < N; i++) {
        new_set.insert(A[i]);
        s.erase(A[i]);
        if (s.empty()) {
            s.swap(new_set);
            ans++;
        }
    }
    cout << ans << endl;
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