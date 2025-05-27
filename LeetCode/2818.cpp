#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MX = 1e5 + 1000;
int lp[MX + 1], pr[MX + 1];
 
struct Sieve  {
    int counter = 0;
 
    Sieve() {
        for (int i = 0; i <= MX; i++) {
            pr[i] = -1;
            lp[i] = 0;
        }
 
        for (int i = 2; i <= MX; i++) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= MX; j++) {
                lp[i * pr[j]] = pr[j];
            }
        }
    }
};

ll expo(ll b, ll e, ll m) {
    ll result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
            e--;
            continue;
        }

        b = (b * b) % m;
        e /= 2;
    }
    return result % m;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        Sieve s;
        const int N = nums.size();
        vector<int> scores(N);
        for (int i = 0; i < N; i++) {
            map<int, int> primes;
            int T = nums[i];
            while (T > 1) {
                primes[lp[T]]++;
                T /= lp[T];
            }
            scores[i] = primes.size();
        }
        vector<int> left(N), right(N);
        vector<int> stack_left, stack_right;
        for (int i = 0; i < N; i++) {
            while (!stack_left.empty() && scores[stack_left.back()] < scores[i]) {
                stack_left.pop_back();
            }
            left[i] = (stack_left.empty() ? 0 : stack_left.back() + 1);
            stack_left.push_back(i);
        }
        for (int i = N - 1; i >= 0; i--) {
            while (!stack_right.empty() && scores[stack_right.back()] <= scores[i]) {
                stack_right.pop_back();
            }
            right[i] = (stack_right.empty() ? N - 1 : stack_right.back() - 1);
            stack_right.push_back(i);
        }
        vector<pair<int, int>> sorted(N);
        for (int i = 0; i < N; i++) {
            sorted[i] = { nums[i], i };
        }
        sort(sorted.rbegin(), sorted.rend());
        const int MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 0; i < N; i++) {
            int num = sorted[i].first;
            int index = sorted[i].second;
            ll R = right[index] - index + 1;
            ll L = index - left[index] + 1;
            ll strong = R * L;
            int take = min(strong, (ll)k);
            k -= take;
            ll contribution = expo(num, take, MOD);
            ans = (ans * contribution) % MOD;
        }
        return ans;
    }
};