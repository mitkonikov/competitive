#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;

long long binary(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
            power--;
        }

        base = (base * base) % MOD;
        power /= 2;
    }

    return result;
}

struct sparse_bitset {
    map<int, int>* v;
    int id;
    
    void add(const sparse_bitset& b) {
        auto& m1 = *v;
        auto& m2 = *b.v;
        
        for (auto el = m2.begin(); el != m2.end(); el++) {
            if (el->second == 0) continue;
            
            m1[el->first] += el->second;
            auto el2 = m1.find(el->first);
            vector<int> to_erase;
            while (m1[el2->first] >= 2) {
                m1[el2->first + 1] += m1[el2->first] / 2;
                m1[el2->first] &= 1;
                if (m1[el2->first] == 0) {
                    to_erase.push_back(el2->first);
                }
                el2++;
            }

            for (auto element: to_erase) {
                m1.erase(element);
            }
        }
    }

    bool operator>(const sparse_bitset& b) const {
        auto& m1 = *v;
        auto& m2 = *b.v;

        if (m1.empty()) return false;
        if (m2.empty()) return true;

        auto it1 = m1.rbegin();
        auto it2 = m2.rbegin();

        while (it1 != m1.rend() && it2 != m2.rend() && it1->first == it2->first) {
            it1++;
            it2++;
            
            while (it1 != m1.rend() && it1->second == 0) {
                it1++;
            }
            
            if (it1 == m1.rend()) {
                return false;
            }

            if (it2 == m2.rend()) {
                return true;
            }
            
            while (it2 != m2.rend() && it2->second == 0) {
                it2++;
            }
            
            if (it1 == m1.rend()) {
                return false;
            }

            if (it2 == m2.rend()) {
                return true;
            }
        }

        return (it1->first > it2->first);
    }

    int calc() {
        ll res = 0;
        for (auto el: *v) {
            if (el.second > 0) res = (res + binary(2, el.first)) % MOD;
        }
        return res;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, int> ump;

    vector<int> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i];
        ump[jobs[i]] = 1;
    }
    
    if (ump.size() == n) {
        ll sum = 0;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + binary(2, jobs[i])) % MOD;
            mx = max(mx, (ll)jobs[i]);
        }
        
        if (m == 1) {
            cout << sum << endl;
        } else {
            cout << binary(2, mx) << endl;
        }
        
        return 0;
    }

    sort(jobs.rbegin(), jobs.rend());

    vector<map<int, int>> maps(m);
    priority_queue<sparse_bitset, vector<sparse_bitset>, greater<sparse_bitset>> pq;
    for (int i = 0; i < m; i++) {
        pq.push({ &maps[i], i });
    }

    map<int, int> tmp;
    for (int i = 0; i < n; i++) {
        auto top = pq.top(); pq.pop();

        tmp.clear();
        tmp[jobs[i]] = 1;
        top.add({&tmp, -1 });
        
        pq.push(top);
    }

    while (pq.size() > 1) {
        pq.pop();
    }

    auto ans = pq.top();
    cout << ans.calc() << endl;
    return 0;
}