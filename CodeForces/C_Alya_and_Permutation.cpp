#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> ans(N, -1);
    set<int> unvisited;
    for (int i = 1; i <= N; i++) unvisited.insert(i);
    
    if (N % 2 == 0) {
        bool case1 = false;
        int bit = 0;
        for (int i = 0; i < 31; i++) {
            if ((1 << i) == N) {
                case1 = true;
                bit = i;
            }
        }

        if (!case1) {
            int l = __builtin_clz(N);
            int b = 1 << (31 - l);

            ans[0] = N;
            ans[1] = b - 1;
            ans[2] = (ans[1] & ans[0]) ^ ans[1];

            for (int i = 0; i < 3; i++) {
                unvisited.erase(ans[i]);
            }
        } else {
            ans[0] = N;
            ans[1] = N - 1;
            ans[2] = N - 2;
            ans[3] = N - 3;
            ans[4] = 3;

            for (int i = 0; i < 5; i++) {
                unvisited.erase(ans[i]);
            }
        }
    } else {
        bool case1 = false;
        int bit = 0;
        for (int i = 0; i < 31; i++) {
            if ((1 << i) == N) {
                case1 = true;
                bit = i;
            }
        }

        if (!case1) {
            ans[0] = N;
            ans[1] = N - 1;
            int l = __builtin_clz(N);
            int b = 1 << (31 - l);
            ans[2] = b - 1;
            unvisited.erase(N);
            unvisited.erase(N - 1);
            unvisited.erase(b - 1);
        } else {
            ans[0] = N;
            ans[1] = (1 << bit);
            ans[2] = (1 << bit) - 1;
            ans[3] = N - (1 << bit);
            for (int i = 0; i < 4; i++) {
                unvisited.erase(ans[i]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i] != -1) continue;
        ans[i] = *unvisited.begin();
        unvisited.erase(*unvisited.begin());
    }

    reverse(ans.begin(), ans.end());
    int K = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            K = K & ans[i];
        } else {
            K = K | ans[i];
        }
    }

    cout << K << endl;
    for (int el : ans) cout << el << " ";
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