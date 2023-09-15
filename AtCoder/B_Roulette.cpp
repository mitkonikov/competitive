#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int k = 0; k < K; k++) {
            int c;
            cin >> c;
            A[i].push_back(c);
        }
    }
    int X;
    cin >> X;
    vector<pair<int, int>> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j] == X) {
                ans.push_back({ A[i].size(), i });
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back().first != ans[0].first) ans.pop_back();
    cout << ans.size() << endl;
    for (auto el: ans) cout << el.second + 1 << " ";
    cout << endl;
    return 0;
}