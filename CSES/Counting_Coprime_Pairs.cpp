#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void zeta(vector<ll>& a) {
  int n = a.size() - 1;
  for (int i = 1; i <= n; ++i) { // reverse loop
    for (int j = 2; j <= n / i; ++j) {
      a[i] += a[i * j];             // swap(i, i*j)
    }
  }
}

void mobius(vector<ll>& a) {
  int n = a.size() - 1;
  for (int i = n; i >= 1; --i) { // reverse loop
    for (int j = 2; j <= n / i; ++j) {
      a[i] -= a[i * j];             // swap(i, i*j)
    }
  }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<ll> frq(1e6 + 100);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        frq[A[i]]++;
    }

    ll ones = frq[1];
    frq[1] = 0;

    zeta(frq);
    vector<ll> c(1e6 + 100);
    for (int i = 1; i < 1e6 + 100; ++i) c[i] = frq[i] * frq[i];
    mobius(c);

    cout << c[1] / 2 +                         // ?-? both ways
            (ones * (N - ones))                // 1-?
          + (ones * (ones - 1)) / 2 << endl;   // 1-1 both ways
    return 0;
}