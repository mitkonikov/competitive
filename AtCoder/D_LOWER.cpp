#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline bool UP(char c) {
    return (c >= 'A' && c <= 'Z');
}

inline bool LOW(char c) {
    return !UP(c);
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<tuple<int, int, char>> operations(Q);
    for (int i = 0; i < Q; i++) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        operations[i] = { t, x, c };
    }

    int last_op = -1, last_op_type = -1;
    for (int i = 0; i < Q; i++) {
        auto [t, x, c] = operations[i];
        if (t == 1) {

        } else if (t == 2) {
            last_op = i;
            last_op_type = 2;
        } else if (t == 3) {
            last_op = i;
            last_op_type = 3;
        }
    }
    for (int i = 0; i < last_op; i++) {
        auto [t, x, c] = operations[i];
        if (t == 1) S[x] = c;
    }
    if (last_op_type != -1) {
        for (int i = 0; i < N; i++) {
            if (last_op_type == 2 && UP(S[i])) S[i] = S[i] - 'A' + 'a';
            else if (last_op_type == 3 && LOW(S[i])) S[i] = S[i] - 'a' + 'A';
        }
    }
    for (int i = last_op + 1; i < Q; i++) {
        auto [t, x, c] = operations[i];
        if (t == 1) S[x] = c;
    }
    cout << S << endl;
    return 0;
}