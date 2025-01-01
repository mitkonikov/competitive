#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    set<int> unvisited;
    for (int i = 1; i <= N; i++) {
        unvisited.insert(i);
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        if (unvisited.count(A[i])) {
            unvisited.erase(A[i]);
            ans[i] = A[i];
        }
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] == 0) {
            ans[i] = *unvisited.begin();
            unvisited.erase(unvisited.begin());
        }
    }
    for (auto el : ans) cout << el << " ";
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