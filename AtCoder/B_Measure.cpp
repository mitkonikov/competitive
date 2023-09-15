#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string ans = "";
    for (int i = 0; i <= N; i++) {
        bool f = 0;
        for (int j = 1; j <= 9; j++) {
            if (N % j == 0 && i % (N / j) == 0) {
                ans += to_string(j);
                f = 1;
                break;
            }
        }
        if (!f) ans += '-';
    }
    cout << ans << endl;
    return 0;
}