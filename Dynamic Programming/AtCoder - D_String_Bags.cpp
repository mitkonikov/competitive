#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void umin(int& a, int b) {
    if (b < a) a = b;
}

int main() {
    string T;
    cin >> T;
    int bags;
    cin >> bags;
    vector<vector<string>> A(bags);
    vector<int> dp(T.size() + 1, 1e9);
    dp[0] = 0;
    auto matches = [&](int i, string P) {
        int matches = 0;
        for (int k = i; k < i + P.size() && k < T.size(); k++) {
            matches += (T[k] == P[k-i]);
        }
        return (matches == P.size());
    };
    for (int i = 0; i < bags; i++) {
        int N;
        cin >> N;
        A[i].resize(N);
        vector<int> new_dp(dp);
        new_dp[0] = 0;
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            for (int k = 0; k < T.size(); k++) {
                if (dp[k] != 1e9 && matches(k, A[i][j])) {
                    umin(new_dp[k + A[i][j].size()], dp[k] + 1);
                }
            }
        }
        new_dp.swap(dp);
    }
    cout << (dp[T.size()] == 1e9 ? -1 : dp[T.size()]) << endl;
    return 0;
}