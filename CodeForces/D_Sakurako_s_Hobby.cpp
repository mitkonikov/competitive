#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> perm(N);
    for (int i = 0; i < N; i++) {
        cin >> perm[i];
    }
    string S;
    cin >> S;
    vector<vector<int>> cycles;
    vector<int> black(N);
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                j = perm[j] - 1;
            }
            cycles.push_back(cycle);
        }
    }
    for (int i = 0; i < cycles.size(); i++) {
        auto& cycle = cycles[i];
        for (int id: cycle) {
            if (S[id] == '0') {
                black[i]++;
            }
        }
    }
    vector<int> ans(N);
    for (int i = 0; i < cycles.size(); i++) {
        auto& cycle = cycles[i];
        for (int id: cycle) {
            ans[id] = black[i];
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
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