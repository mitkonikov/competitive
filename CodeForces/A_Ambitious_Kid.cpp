#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ans = min(ans, abs(x));
    }
    cout << ans << endl;
    return 0;
}