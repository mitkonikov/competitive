#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = n;
    for (int i = 0; i < 3; i++) {
        n *= 2;
        ans += n;
    }
    cout << ans << endl;
    return 0;
}