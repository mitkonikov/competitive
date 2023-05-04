#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

double expo(double b, ll e) {
    double result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b);
            e--;
            continue;
        }
 
        b = (b * b);
        e /= 2;
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i = 1; i <= K; i++) {
        ans += (expo(i, N) - expo(i - 1, N)) * i;
    }
    ans /= expo(K, N);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}