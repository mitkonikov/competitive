#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> reel(3);
    for (int i = 0; i < 3; i++) cin >> reel[i];
    int ans = INT_MAX;
    for (char d = '0'; d <= '9'; d++) {
        vector<int> order(3);
        iota(order.begin(), order.end(), 0);
        do {
            int t = 0;
            int f = 0;
            for (int o = 0; o < 3; o++) {
                int r = order[o];
                for (int i = t; i <= N + t; i++) {
                    if (reel[r][i%N] == d) {
                        t = i + 1;
                        f++;
                        break;
                    }
                }
            }
            if (f == 3) {
                ans = min(ans, t - 1);
            }
        } while (next_permutation(order.begin(), order.end()));
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}