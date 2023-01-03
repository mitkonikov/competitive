#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
struct Sieve {
  static const int N = 110;
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
    int N;
    cin >> N;
    map<int, int> factorization;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        while (s.lp[x] > 1) {
            factorization[s.lp[x]]++;
            x /= s.lp[x];
        }
    }
    ll ans = 1;
    for (auto el: factorization) {
        if (el.second % 2 == 1) {
            ans = (ans * el.first) % (int)(1e6 + 7);
        }
    }
    cout << ans << endl;
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