#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int L, R;
    cin >> L >> R;
    int kR = 0;
    int TR = R;
    while (TR > 0) {
        TR /= 2;
        kR++;
    }
    int kL = 0;
    int TL = L;
    while (TL > 0) {
        TL /= 2;
        kL++;
    }
    int ans[3] = { R, L, L };
    bool first = true;
    int kk = 0;
    for (int i = kR; i >= 0; i--) {
        int bit[3];
        int on[2] = { 0, 0 };
        for (int j = 0; j < 3; j++) {
            bit[j] = (ans[j] & (1 << i)) > 0;
            on[bit[j]]++;
        }
        if ((on[0] == 3 || on[1] == 3) && first) {
            continue;
        }
        if (first) {
            if ((ans[0] & ((1 << i) - 1)) == 0) {
                
            } else {
                ans[2] ^= (1 << i);
                ans[2] &= ~((1 << i) - 1);
            }
            kk = i;
            first = false;
        }
        if (on[1] == 3) {
            ans[0] ^= (1 << i);
        }
        if (on[0] == 3) {
            ans[1] ^= (1 << i);
        }
    }
    for (int i = 0; i < 3; i++) cout << ans[i] << " ";
    cout << endl;
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