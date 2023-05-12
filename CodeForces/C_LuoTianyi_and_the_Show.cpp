#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    set<int> s;
    int fL = 0, fR = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {
            if (A[i] == -1) fL++;
            else fR++;
            continue;
        }
        s.insert(A[i]);
    }

    int ans = 0;

    ans = max(ans, fL + (int)s.size());
    ans = max(ans, fR + (int)s.size());

    int below_me = 0;
    for (auto el: s) {
        // i
        int l = min(el - 1, fL);
        int r = min(M - el, fR);
        
        int left_l = (el - 1) - l;
        int left_r = (M - el) - r;

        int take_l = min(left_l, below_me);
        int take_r = min(left_r, (int)s.size() - 1 - below_me);

        int cur = l + r + take_l + take_r + 1;
        ans = max(ans, cur);

        below_me++;
    }

    cout << min(ans, M) << endl;
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