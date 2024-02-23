#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
vector<unordered_map<string, int>> dp;
vector<unordered_map<string, set<string>>> accessable_states;
int coord(int x, int y) {
    int c = x * 3 + y;
    assert(c >= 0 && c < 9);
    return c;
}
 
int win(string state) {
    for (int i = 0; i < 3; i++) {
        int x = 0, o = 0;
        for (int j = 0; j < 3; j++) {
            if (state[coord(i, j)] == 'x') x++;
            if (state[coord(i, j)] == 'o') o++;
        }
        if (x == 3) return 1;
        if (o == 3) return 1;
    }
    for (int i = 0; i < 3; i++) {
        int x = 0, o = 0;
        for (int j = 0; j < 3; j++) {
            if (state[coord(j, i)] == 'x') x++;
            if (state[coord(j, i)] == 'o') o++;
        }
        if (x == 3) return 1;
        if (o == 3) return 1;
    }
    {
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            if (state[coord(i, i)] == 'x') x++;
            if (state[coord(i, i)] == 'o') o++;
        }
        if (x == 3) return 1;
        if (o == 3) return 1;
    }
    {
        int x = 0, o = 0;
        for (int i = 0; i < 3; i++) {
            if (state[coord(i, 3-i-1)] == 'x') x++;
            if (state[coord(i, 3-i-1)] == 'o') o++;
        }
        if (x == 3) return 1;
        if (o == 3) return 1;
    }
    int empty = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[coord(i, j)] == '-') empty++;
        }
    }
    if (empty == 0) {
        return -1;
    }
    return -1;
}
 
void dfs(string state, int turn) {
    auto it = accessable_states[turn].find(state);
    if (it != accessable_states[turn].end()) {
        return;
    }
    if (win(state) != -1) {
        accessable_states[turn][state].insert(state);
        return;
    }
 
    string biggest = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[coord(i, j)] == '-') {
                string new_state = state;
                new_state[coord(i, j)] = (turn == 0 ? 'o' : 'x');
                dfs(new_state, turn ^ 1);
                if (biggest == "" || accessable_states[turn^1][new_state].size() > accessable_states[turn^1][biggest].size()) {
                    biggest = new_state;
                }
            }
        }
    }
    auto bg = accessable_states[turn^1][biggest];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[coord(i, j)] == '-') {
                string new_state = state;
                new_state[coord(i, j)] = (turn == 0 ? 'o' : 'x');
                for (auto child_states : accessable_states[turn^1][new_state]) {
                    bg.insert(child_states);
                }
            }
        }
    }
    accessable_states[turn][state].swap(bg);
}
 
int main() {
    dp.resize(2);
    accessable_states.resize(2);
    dfs("---------", 1);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        string S = s1 + s2 + s3;
        int valid = -1;
        for (int rep : { 0, 1 }) {
            auto it = accessable_states[rep].find(S);
            if (it != accessable_states[rep].end()) {
                valid = rep;
            }
        }
        if (valid == -1) {
            cout << -2 << endl;
        } else {
            auto sz = accessable_states[valid][S].size();
            if (sz == 1) {
                if (*(accessable_states[valid][S].begin()) == S) {
                    cout << -1 << endl;
                } else {
                    cout << accessable_states[valid][S].size() << endl;
                }
            } else {
                cout << accessable_states[valid][S].size() << endl;
            }
        }
    }
    return 0;
}