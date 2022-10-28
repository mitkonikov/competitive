#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int mxn = 2 * 10000 + 1000;
const int off = mxn / 2;

int main() {
    int N, x, y;
    cin >> N >> x >> y;

    int a1;
    cin >> a1;

    // Given some a[i]
    //  separate them into 4 groups
    //    -x +x 
    //    -y +y ->  (a1, 0) -> (x, y)
    
    vector<int> a[2];
    for (int i = 1; i < N; i++) {
        int X;
        cin >> X;
        a[i%2].push_back(X);
    }

    int target_x = x - a1;
    int target_y = y;

    auto valid = [&](int g) {
        return (g >= 0 && g < mxn);
    };

    vector<bool> dp(mxn);
    bool ok = true;
    for (int rep = 0; rep < 2; rep++) {
        dp[off + 0] = 1;
        for (int i = 0; i < a[rep].size(); i++) {
            vector<bool> new_dp(mxn);
            for (int j = 0; j < mxn; j++) {
                if (dp[j]) {
                    if (valid(j + a[rep][i]))
                        new_dp[j + a[rep][i]] = true;
                    
                    if (valid(j - a[rep][i]))
                        new_dp[j - a[rep][i]] = true;
                }
            }
            dp.swap(new_dp);
        }

        if (!rep) ok &= dp[target_x + off];
        else ok &= dp[target_y + off];
        dp.clear();
    }

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}