#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

struct Sieve {
  static const int N = 3e6 + 1000;
  int lp[N+1], pr[N+1];
  int counter = 0;

  Sieve() {
    for (int i = 0; i < N; i++) {
      pr[i] = -1;
      lp[i] = 0;
    }
    
    for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr[counter++] = i;
      }
      for (int j = 0; j < counter && pr[j] <= lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
  }
};

Sieve s;

void testCase() {
    ll N;
    cin >> N;
    for (int i = 0; i < s.counter; i++) {
        ll p = s.pr[i];
        if (p == N) {
            cout << 1 << " " << p << endl;
            return;
        }
        
        if (N % p != 0) continue;
        if (N % (p * p) == 0) {
            cout << p << " " << N / (p * p) << endl;
            return;
        }
        ll sq = N / p;
        ll sqr = sqrtl(sq);
        for (int i = -2; i <= 2; i++) {
            if (sqr + i >= 1 && (sqr + i) * (sqr + i) == sq) {
                cout << sqr + i << " " << p << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}