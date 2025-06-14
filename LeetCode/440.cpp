#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int countPrefix(ll prefix, ll n) {
        ll count = 0;
        ll curr = prefix, next = prefix + 1;
        while (curr <= n) {
            count += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        string ans = "";
        const int LEN = to_string(n).size();
        while (k > 0 && ans.size() <= LEN) {
            int count2 = 0;
            for (int d = (ans.empty() ? 1 : 0); d <= 9; d++) {
                string prefix = ans + (char)('0' + d);
                ll prefixNum = stoll(prefix);
                int count = countPrefix(prefixNum, n);
                if (count + count2 >= k) {
                    ans += '0' + d;
                    k -= count2 + 1;
                    break;
                }
                count2 += count;
            }
        }
        return stoi(ans);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.findKthNumber(n, k) << endl;
}