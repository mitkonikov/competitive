#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') cnt++;
    }
    int md = (cnt + 1) / 2;
    int cnt2 = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            cnt2++;
        }
        if (cnt2 == md) {
            {
                int cnt3 = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (S[j] == '1') {
                        ans += abs(i - j) - 1 - cnt3;
                        cnt3++;
                    }
                }
            }
            {
                int cnt3 = 0;
                for (int j = i + 1; j < N; j++) {
                    if (S[j] == '1') {
                        ans += abs(i - j) - 1 - cnt3;
                        cnt3++;
                    }
                }
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}