#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    double W, H;
    cin >> W >> H;
    if (H > W) swap(W, H);
    double ans = min(H * 2 / sqrt(3), sqrt(H*H + W*W - H*W*sqrt(3)) * 2);
    cout << fixed << setprecision(18) << ans << endl;
    return 0;
}