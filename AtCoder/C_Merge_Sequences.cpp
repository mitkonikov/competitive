#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct val {
    int where, id, value;
    bool operator<(const val& other) const {
        return (value < other.value);
    }
};

int main() {
    int A, B;
    cin >> A >> B;
    vector<val> V;
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        V.push_back({ 0, i, x });
    }
    for (int i = 0; i < B; i++) {
        int x;
        cin >> x;
        V.push_back({ 1, i, x });
    }
    sort(V.begin(), V.end());
    vector<vector<int>> ans(2);
    ans[0].resize(A);
    ans[1].resize(B);
    for (int i = 0; i < V.size(); i++) {
        ans[V[i].where][V[i].id] = i + 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}