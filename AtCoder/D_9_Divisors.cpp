#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MXN = 3e6 + 1000;
int lp[MXN + 1], pr[MXN + 1];

struct Sieve {
    int counter = 0;

    Sieve() {
        for (int i = 0; i < MXN; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }

        for (int i = 2; i <= MXN; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= MXN;
                 ++j)
                lp[i * pr[j]] = pr[j];
        }
    }
};

int main() {
    Sieve s;
    ll N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < s.counter; i++) {
        if (pow((double)pr[i], 8) <= N) ans++;
        for (int j = i + 1; j < s.counter; j++) {
            if ((double)pr[i] * pr[i] * pr[j] * pr[j] <= N) {
                ans++;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}