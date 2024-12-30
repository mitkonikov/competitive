#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    ll factor = 1;

    vector<int> reverse;

    while (N >= K) {
        if (N % 2 == 0) {
            N /= 2;
            factor *= 2;
            reverse.push_back(0);
        } else {
            ll M = N / 2 + 1;

            ll offset = 0;
            ll curSize = N;
            ll ints = 1;
            ll sum = M;
            for (int j = reverse.size() - 1; j >= 0; j--) {
                if (reverse[j]) {
                    ll shift = ints * (curSize + 1);
                    sum += sum + shift;
                    curSize *= 2;
                    curSize++;
                    ints *= 2;
                } else {
                    ll shift = ints * curSize;
                    sum += sum + shift;
                    curSize *= 2;
                    ints *= 2;
                }
            }
            
            ans += sum;

            N /= 2;
            factor *= 2;
            reverse.push_back(1);
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