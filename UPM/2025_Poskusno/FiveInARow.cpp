#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline ll coord(ll R, ll C) {
    return R * (ll)(1e9 + 10) + C;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    unordered_map<ll, int> mp;
    bool win = false;
    int winner = -1;
    int win_move = 0;
    vector<int> moves(2);
    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        if (win) continue;
        moves[i & 1]++;
        mp[coord(R, C)] = i & 1;
        for (int r = R - 5; r <= R + 5 && !win; r++) {
            for (int c = C - 5; c <= C + 5 && !win; c++) {
                if (r < 0 || c < 0) continue;
                auto it = mp.find(coord(r, c));
                if (it != mp.end() && it->second == (i & 1)) {
                    // try rows
                    bool ok_row = true;
                    for (int k = 1; k < 5 && ok_row; k++) {
                        auto it = mp.find(coord(r + k, c));
                        ok_row &= (it != mp.end() && it->second == (i & 1));
                    }

                    bool ok_col = true;
                    for (int k = 1; k < 5 && ok_col; k++) {
                        auto it = mp.find(coord(r, c + k));
                        ok_col &= (it != mp.end() && it->second == (i & 1));
                    }

                    bool ok_dia1 = true;
                    for (int k = 1; k < 5 && ok_dia1; k++) {
                        auto it = mp.find(coord(r + k, c + k));
                        ok_dia1 &= (it != mp.end() && it->second == (i & 1));
                    }

                    bool ok_dia2 = true;
                    for (int k = 1; k < 5 && ok_dia2; k++) {
                        auto it = mp.find(coord(r + k, c - k));
                        ok_dia2 &= (it != mp.end() && it->second == (i & 1));
                    }

                    if (ok_row || ok_col || ok_dia1 || ok_dia2) {
                        winner = i & 1;
                        win_move = moves[i & 1];
                        win = true;
                        break;
                    }
                }
            }
        }
    }
    if (winner == -1) {
        cout << "neodloceno" << endl;
        return 0;
    }

    if (winner == 0) {
        cout << "Snoopy " << win_move << endl;
    } else {
        cout << "Linus " << win_move << endl;
    }
    return 0;
}