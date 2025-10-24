#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<string> A;
    A.reserve(1e5 + 10);
    auto dfs = [&](auto&& self, int i, string cur) {
        if (i == K) {
            A.push_back(cur);
            return;
        }

        for (int k = 0; k < N; k++) {
            self(self, i + 1, cur + S[k]);
        }
    };
    dfs(dfs, 0, "");
    sort(A.begin(), A.end());
    cout << A[X-1] << endl;
    return 0;
}