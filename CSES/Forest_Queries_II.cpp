#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

#define MAX 1010

int fenwick[MAX][MAX];

void update(int x, int y, int val) {
    x++; y++;
    for (int a = x; a < MAX; a += a & -a) {
        for (int b = y; b < MAX; b += b & -b) {
            fenwick[a][b] += val;
        }
    }
}

int query(int x, int y) {
    x++; y++;
    int ans = 0;
    for (int a = x; a > 0; a -= a & -a) {
        for (int b = y; b > 0; b -= b & -b) {
            ans += fenwick[a][b];
        }
    }
    return ans;
}

int query(int x1, int y1, int x2, int y2) {
    int ans = query(x2, y2);
    if (x1) ans -= query(x1 - 1, y2);
    if (y1) ans -= query(x2, y1 - 1);
    if (x1 && y1) ans += query(x1 - 1, y1 - 1);
    return ans;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < N; j++) {
            update(i, j, (S[j] == '*'));
        }
    }
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            int q = query(i, j, i, j);
            update(i, j, (q ? -1 : 1));
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            cout << query(x1, y1, x2, y2) << endl;
        }
    }
    return 0;
}