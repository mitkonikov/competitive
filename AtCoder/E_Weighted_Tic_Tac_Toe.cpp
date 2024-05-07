#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline int coord(int x, int y) {
    return (x * 3) + y;
}

vector<ll> w(9);

int winning(vector<int>& state) {
    for (int i = 0; i < 3; i++) {
        vector<int> scores(3);
        for (int j = 0; j < 3; j++) {
            scores[state[coord(i, j)] + 1]++;
        }
        if (scores[0] == 3) return -1;
        if (scores[2] == 3) return 1;
    }
    for (int i = 0; i < 3; i++) {
        vector<int> scores(3);
        for (int j = 0; j < 3; j++) {
            scores[state[coord(j, i)] + 1]++;
        }
        if (scores[0] == 3) return -1;
        if (scores[2] == 3) return 1;
    }
    {
        vector<int> scores(3);
        for (int i = 0; i < 3; i++) {
            scores[state[coord(i, i)] + 1]++;
        }
        if (scores[0] == 3) return -1;
        if (scores[2] == 3) return 1;
    }
    {
        vector<int> scores(3);
        for (int i = 0; i < 3; i++) {
            scores[state[coord(i, 3-i-1)] + 1]++;
        }
        if (scores[0] == 3) return -1;
        if (scores[2] == 3) return 1;
    }
    return 0;
}

void print(vector<int> state) {
    for (auto el: state) cout << el << " ";
    cout << endl;
}

// player = 1 -> tak, -1 -> aok
ll dfs(vector<int>& state, int player, ll t = 0) {
    ll so_far = (player == 1 ? LLONG_MIN : LLONG_MAX);
    bool found = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[coord(i, j)] == 0) {
                found = true;
                state[coord(i, j)] = player;
                
                // check if winning
                auto win = winning(state);
                if (win == player) {
                    state[coord(i, j)] = 0;
                    return (ll)1e15 * player;
                }
                
                auto next = dfs(state, -player, t + (player == 1 ? w[coord(i, j)] : -w[coord(i, j)]));

                if (player == 1) {
                    so_far = max(so_far, next);
                } else {
                    so_far = min(so_far, next);
                }

                state[coord(i, j)] = 0;
            }
        }
    }
    if (!found) {
        return t;
    }
    return so_far;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> w[coord(i, j)];
        }
    }
    vector<int> state(9);
    ll ans = dfs(state, 1);
    cout << (ans >= 0 ? "Takahashi" : "Aoki") << endl;
    return 0;
}