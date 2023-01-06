#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

bool is_permutation(vector<int>& a) {
    vector<int> B(a);
    int N = B.size();
    sort(B.begin(), B.end());
    for (int i = 1; i < N; i++) {
        if (B[i] == -1 || B[i-1] == -1) return false;
        if (B[i] != B[i-1] + 1) {
            return false;
        }
    }
    return true;
}

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    if (is_permutation(A)) {
        cout << "YES" << endl;
        for (auto el: A) cout << el << " "; cout << endl;
        for (auto el: A) cout << el << " "; cout << endl;
        return;
    }
    vector<vector<int>> frq(N + 10);
    for (int i = 0; i < N; i++) {
        frq[A[i]].push_back(i + 1);
    }
    if (frq[1].size() > 1) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (frq[i].size() > 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> ans1(A), ans2(A);
    set<int> unvisited;
    for (int i = 1; i <= N; i++) {
        if (frq[i].size() == 0) {
            unvisited.insert(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (frq[i].size() == 2) {
            ans2[frq[i][0] - 1] = *(unvisited.begin());
            ans1[frq[i][1] - 1] = *(unvisited.begin());
            unvisited.erase(unvisited.begin());
        }
    }
    bool okA = is_permutation(ans1);
    bool okB = is_permutation(ans2);
    bool ok = true;
    for (int i = 0; i < N && ok; i++) {
        if (max(ans1[i], ans2[i]) != A[i]) ok = false;
    }
    if (okA && okB && ok) {
        cout << "YES" << endl;
        for (auto el: ans1) cout << el << " "; cout << endl;
        for (auto el: ans2) cout << el << " "; cout << endl;
        return;
    }
    cout << "NO" << endl;
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