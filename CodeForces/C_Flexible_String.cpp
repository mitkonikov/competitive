#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    string A, B;
    cin >> A >> B;
    
    vector<int> frq(26);
    for (int i = 0; i < N; i++) frq[A[i] - 'a']++;

    vector<int> mp_rev;
    for (int i = 0; i < 26; i++) if (frq[i]) mp_rev.push_back(i);

    vector<int> mp(26, 0);
    for (int i = 0; i < mp_rev.size(); i++) {
        mp[mp_rev[i]] = i;
    }

    ll ans = 0;
    for (int mask = 0; mask < (1 << (int)(mp_rev.size())); mask++) {
        if (__builtin_popcount(mask) > K) continue;
        
        int len = 0;
        ll current = 0;
        for (int i = 0; i < N; i++) {
            int in_mask = mp[A[i] - 'a'];
            if (mask & (1 << in_mask) || A[i] == B[i]) {
                len++;
            } else {
                current += ((ll)len * (len + 1) / 2);
                len = 0;
            }
        }
        current += ((ll)len * (len + 1) / 2);
        len = 0;

        ans = max(ans, current);
    }
    cout << ans << endl;
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