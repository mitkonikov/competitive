#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int N;
string S, T;

vector<string> rows;

void dfs(int index) {
    if (index == N) {
        for (int i = 0; i < N; i++) {
            vector<int> frq(3);
            for (int j = 0; j < N; j++) {
                if (rows[i][j] != '.') frq[rows[i][j] - 'A']++;
            }
            if (!(frq[0] == 1 && frq[1] == 1 && frq[2] == 1)) return;
        }
        for (int i = 0; i < N; i++) {
            vector<int> frq(3);
            for (int j = 0; j < N; j++) {
                if (rows[j][i] != '.') frq[rows[j][i] - 'A']++;
            }
            if (!(frq[0] == 1 && frq[1] == 1 && frq[2] == 1)) return;
        }
        string check = "";
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                if (rows[i][j] != '.') {
                    check += rows[i][j];
                    break;
                }
            }
        }
        if (check == T) {
            cout << "Yes" << endl;
            for (int i = 0; i < N; i++) {
                cout << rows[i] << endl;
            }
            exit(0);
        }
        return;
    }

    for (int f = 0; f < 3; f++) {
        rows[index][f] = S[index];
        string ABC = "";
        for (int j = 0; j < 3; j++) {
            if (('A' + j) != S[index]) {
                ABC += ('A' + j);
            }
        }
        for (int s1 = f + 1; s1 < N; s1++) {
            for (int s2 = f + 1; s2 < N; s2++) {
                if (s1 == s2) continue;
                rows[index][s1] = ABC[0];
                rows[index][s2] = ABC[1];
                dfs(index + 1);
                rows[index][s1] = '.';
                rows[index][s2] = '.';
            }
        }
        rows[index][f] = '.';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S >> T;
    rows.resize(N, string(N, '.'));
    dfs(0);
    cout << "No" << endl;
    return 0;
}