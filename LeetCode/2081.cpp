#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    ll kMirror(int k, int n) {
        ll pw[18];
        pw[0] = 1;
        for (int i = 1; i < 18; i++) {
            pw[i] = pw[i-1] * 10;
        }
        set<ll> arr;
        int baseK[100];
        auto check = [&](ll T) {
            int count = 0;
            while (T > 0) {
                baseK[count++] = T % k;
                T /= k;
            }
            bool ok = true;
            for (int i = 0; i < count / 2; i++) {
                ok &= (baseK[i] == baseK[count-i-1]);
            }
            return ok;
        };
        auto stoll = [](const string& s) {
            ll res = 0;
            ll pow = 1;
            for (int i = s.size() - 1; i >= 0; i--) {
                res += pow * (s[i] - '0');
                pow *= 10;
            }
            return res;
        };
        string S = "0";
        for (int i = 1; i <= 650000; i++) {
            S.back() += 1;
            for (int i = S.size() - 1; i >= 0; i--) {
                if (S[i] == ':') {
                    S[i] = '0';
                    if (i == 0) {
                        S.insert(S.begin(), '1');
                    } else {
                        S[i-1]++;
                    }
                }
            }
            
            string R = S;
            reverse(R.begin(), R.end());

            auto T1 = stoll(S + R);
            const int sz = S.size();
            auto T2 = (T1 / pw[sz+1] * pw[sz]) + (T1 % pw[sz]);

            if (T1 % k != 0 && check(T1)) {
                arr.insert(T1);
            }

            if (T2 % k != 0 && check(T2)) {
                arr.insert(T2);
            }
        }

        if (arr.size() < n) return -1;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += *arr.begin();
            arr.erase(arr.begin());
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.kMirror(7, 30) << endl;
    return 0;
}