#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> R(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        R[A[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] != i) {
            int first = A[i];
            ans.push_back({ i, R[i] });
            swap(A[i], A[R[i]]);
            R[first] = R[i];
        }
    }
    cout << ans.size() << endl;
    for (auto [u, v]: ans) cout << u+1 << " " << v+1 << endl;
    return 0;
}