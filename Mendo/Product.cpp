// Task: https://mendo.mk/Task.do?id=48

#include <bits/stdc++.h>
#define ll long long

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    double M1, N1;
    cin >> M1 >> N1;
    ll M = M1 * 100;
    ll N = N1 * 100;
    ll LCM = (M*N) / gcd(M, N);
    ll A = LCM / M;
    ll B = abs(LCM / N - LCM / M);
    ll GCD = gcd(A, B);
    cout << "KUPI " << A / GCD << " DOBIJ " << B / GCD << " GRATIS" << endl;
    return 0;
}