#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    map<int, int> frq;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }
    vector<pair<int, int>> s;
    for (auto [k, v] : frq) {
        s.push_back({ v, k });
    }
    sort(s.begin(), s.end());
    int ans = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i].first <= K) {
            K -= s[i].first;
            ans--;
        }
    }
    cout << max(1, ans) << endl;
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