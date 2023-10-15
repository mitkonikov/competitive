#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void umin(int& a, int b) {
    if (b < a) a = b;
}

map<pair<int, int>, int> solve(int A, int B, int M) {
    map<pair<int, int>, int> mp;
    mp[{ A, B }] = 0;
    // A = A and B
    // A = A or B
    // B = A xor B
    // B = B xor M
    auto update = [&](map<pair<int, int>, int>& mp, int steps, pair<int, int> value) {
        auto it = mp.find(value);
        if (it == mp.end()) {
            mp[value] = steps;
            return true;
        } else {
            if (mp[value] > steps) {
                mp[value] = steps;
                return true;
            }
        }
        return false;
    };
    while (true) {
        bool k = 0;
        for (auto [p, v]: mp) {
            int A = p.first;
            int B = p.second;
            k |= update(mp, v + 1, make_pair(A & B, B));
            k |= update(mp, v + 1, make_pair(A | B, B));
            k |= update(mp, v + 1, make_pair(A, B ^ A));
            k |= update(mp, v + 1, make_pair(A, B ^ M));
        }
        if (!k) break;
    }
    return mp;
}

map<pair<int, int>, int> precalc;
const int AA = 85;
const int BB = 102;
const int MM = 120;
int dp[150][150][150];

// Each test case can be solved in O(log2(N))
void testCase() {
    int A, B, C, D, M;
    cin >> A >> B >> C >> D >> M;
    int visited = 0;
    auto get_bit_column = [&](int A, int B, int M, int i) {
        int bit = ((A & (1 << i)) > 0);
        bit += ((B & (1 << i)) > 0) << 1;
        bit += ((M & (1 << i)) > 0) << 2;
        return bit;
    };
    for (int i = 0; i < 31; i++) {
        int bit = get_bit_column(A, B, M, i);
        if (bit == 0) continue;
        visited |= (1 << (bit - 1));
    }
    // edge case
    for (int i = 0; i < 31; i++) {
        int b1 = get_bit_column(A, B, M, i);
        int b2 = get_bit_column(C, D, M, i);
        if (b1 == 0 && b2 > 0) {
            cout << -1 << endl;
            return;
        }
    }
    // now we can map each column (A, B, i) to (C, D, i)
    vector<int> mp(32, -1);
    for (int i = 0; i < 31; i++) {
        int b1 = get_bit_column(A, B, M, i);
        int b2 = get_bit_column(C, D, M, i);
        if (mp[b1] == -1) mp[b1] = b2;
        else if (mp[b1] != b2) {
            cout << -1 << endl;
            return;
        }
    }
    // now we have a proper mapping, we just need to find
    // the minimum of all of the values that satisfy the mapping.
    int mpC = 0, mpD = 0;
    for (int i = 0; i < 32; i++) {
        if (mp[i] != -1) {
            if (mp[i] & 1) mpC += (1 << (i - 1));
            if (mp[i] & 2) mpD += (1 << (i - 1));
        }
    }
    int ans = dp[visited][visited & mpC][visited & mpD];
    if (ans >= 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    precalc = solve(AA, BB, MM);
    const int MX = 150;
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j < MX; j++) {
            for (int k = 0; k < MX; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }
    
    for (int mask = 0; mask < 128; mask++) {
        for (auto [p, v]: precalc) {
            umin(dp[mask][p.first & mask][p.second & mask], v);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}

// A = 1010101 = 1 + 4 + 16 + 64 = 85
// B = 1100110 = 2 + 4 + 32 + 64 = 102
// M = 1111000 = 8 + 16 + 32 + 64 = 120