#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
const int MX = 1e7 + 1000;
int lp[MX + 1], pr[MX + 1];
 
struct Sieve  {
    int counter = 0;
 
    Sieve() {
        for (int i = 0; i < MX; i++) {
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
 
void get_divs(vector<int>& divs, vector<pair<int, int>>& primes, int current, int result) {
    if (current >= primes.size()) {
        divs.push_back(result);
        return;
    }
 
    int new_prime = 1;
    for (int alpha = 0; alpha <= primes[current].second; alpha++) {
        get_divs(divs, primes, current + 1, result * new_prime);
        new_prime *= primes[current].first;
    }
}
 
map<int, int> solutions;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    Sieve s;
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int X;
        cin >> X;
 
        auto it = solutions.find(X);
        if (it != solutions.end()) {
            cout << it->second << endl;
            continue;
        }
 
        int temp = X;
        map<int, int> primes;
        while (temp > 1) {
            primes[lp[temp]]++;
            temp /= lp[temp];
        }
 
        vector<int> divs;
        vector<pair<int, int>> vprimes;
        for (auto p: primes) {
            vprimes.push_back(p);
        }
        get_divs(divs, vprimes, 0, 1);
 
        sort(divs.begin(), divs.end());
        
        int ndivs = divs.size();
 
        if (ndivs == 0) {
            cout << 0 << endl;
            continue;
        }
 
        if (ndivs % 2 == 0) {
            ll a = max(0, divs[ndivs / 2] - 2);
            ll b = max(0, divs[ndivs / 2 - 1] - 2);
            solutions[X] = a * b;
            cout << (ll)a * b << endl;
        } else {
            ll a = max(0, divs[ndivs / 2] - 2);
            solutions[X] = a * a;
            cout << (ll)a * a << endl;
        }
    }
 
    return 0;
}