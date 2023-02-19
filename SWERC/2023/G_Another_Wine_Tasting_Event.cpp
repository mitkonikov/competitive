#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
int INF = numeric_limits<int>::max() >> 1;
ll INFL = numeric_limits<ll>::max() >> 1;
ll mod = 998244353;
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int white = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            white++;
        }
    }
    int ans = white;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[n + i] == 'W')
        {
            white++;
        }
        if (s[i] == 'W')
        {
            white--;
        }
        ans = max(ans, white);
    }
    cout << ans << endl;
}
 
int main()
{
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}