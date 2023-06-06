#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    vector<string> S(2);
    cin >> S[0] >> S[1];
    int time, Q;
    cin >> time >> Q;

    int N = S[0].size();
    int mismatches = 0;
    for (int i = 0; i < N; i++) {
        if (S[0][i] != S[1][i]) mismatches++;
    }

    vector<int> unblock(Q + 10, -1);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        
        int ub = unblock[i];
        if (ub != -1) {
            if (S[0][ub] != S[1][ub]) mismatches++;
        }

        if (t == 1) {
            int p;
            cin >> p;
            p--;
            if (S[0][p] != S[1][p]) mismatches--;
            if (i + time < Q) unblock[i + time] = p;
        } else if (t == 2) {
            int s1, p1, s2, p2;
            cin >> s1 >> p1 >> s2 >> p2;
            s1--; s2--;
            p1--; p2--;
            bool p1m = (S[s1][p1] == S[s1^1][p1]);
            bool p2m = (S[s1][p2] == S[s1^1][p2]);
            swap(S[s1][p1], S[s2][p2]);
            if (p1 == p2) continue;
            if (p1m && S[s1][p1] != S[s1^1][p1]) mismatches++;
            if (p2m && S[s1][p2] != S[s1^1][p2]) mismatches++;
            if (!p1m && S[s1][p1] == S[s1^1][p1]) mismatches--;
            if (!p2m && S[s1][p2] == S[s1^1][p2]) mismatches--;
        } else {
            cout << (mismatches == 0 ? "YES" : "NO") << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}