#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    int T = N - 1, c = 0;
    while (T > 0) {
        T /= 2;
        c++;
    }
    cout << c << endl;
    vector<vector<int>> bottles(c);
    for (int i = 1; i <= N - 1; i++) {
        for (int b = 0; b < c; b++) {
            if (i & (1 << b)) {
                bottles[b].push_back(i);
            }
        }
    }
    for (int i = 0; i < c; i++) {
        cout << bottles[i].size() << " ";
        for (auto el: bottles[i]) {
            cout << el << " ";
        }
        cout << endl;
    }
    string X;
    cin >> X;
    int ans = 0;
    for (int i = 0; i < c; i++) {
        if (X[i] == '1') ans += (1 << i);
    }
    if (ans == 0) ans = N;
    cout << ans << endl;
    return 0;
}