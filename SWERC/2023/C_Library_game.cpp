#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
int INF = numeric_limits<int>::max() >> 1;
ll INFL = numeric_limits<ll>::max() >> 1;
ll mod = 998244353;
 
int bernardoWins(int n, int m, vector<int> &x)
{
    for (int i = 1; i < n; i++)
    {
        if (m / x[i] <= i)
        {
            return x[i];
        }
    }
    return -1;
}
 
void playBernardo(int n, int m, int winInterval)
{
    vector<bool> b(m + 1, false);
    for (int i = 0; i < n; i++)
    {
        int y, a;
        cin >> y >> a;
        int chosen = a;
        for (int j = 0; j < y; j++)
        {
            if (b[a + j])
            {
                chosen = a + j;
                break;
            }
            if ((a + j) % winInterval == 0)
            {
                chosen = a + j;
            }
        }
        cout << chosen << endl;
        b[chosen] = true;
    }
}
 
void playAlessia(int n, int m, vector<int> &x)
{
    vector<bool> taken(m + 1, false);
    for (int i = 0; i < n; i++)
    {
        int start = -1;
        for (int j = 1; j + x[i] - 1 <= m; j++)
        {
            bool works = true;
            for (int k = j; k <= j + x[i] - 1; k++)
            {
                if (taken[k])
                {
                    works = false;
                    break;
                }
            }
            if (works)
            {
                start = j;
                break;
            }
        }
        cout << x[i] << " " << start << endl;
        int b;
        cin >> b;
        taken[b] = true;
    }
}
 
void solve()
{
    // sort intervals largest to smallest
 
    // Bernardo - find at which move you will be able to take 2 of the same,
    // and choose sections such that every d-th element (d=interval length)
    // is taken by that move
 
    // Alessia - pick first valid interval?
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x.rbegin(), x.rend());
    int winInterval = bernardoWins(n, m, x);
    if (winInterval != -1)
    {
        cout << "Bernardo" << endl;
        playBernardo(n, m, winInterval);
    }
    else
    {
        cout << "Alessia" << endl;
        playAlessia(n, m, x);
    }
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