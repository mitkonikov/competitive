#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    map<int, int> frq;
    vector<vector<int>> mat(N);
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        mat[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> mat[i][j];
            frq[mat[i][j]]++;
        }
    }
    bool ok = false;
    for (int i = 0; i < N && !ok; i++) {
        bool okk = true;
        for (int j = 0; j < mat[i].size(); j++) {
            if (frq[mat[i][j]] == 1) {
                okk = false;
                break;
            }
        }
        if (okk) {
            ok = true;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
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