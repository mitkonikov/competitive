#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> cand(n);
    for (int i = 0; i < n; i++) cin >> cand[i];

    vector<ll> pref(n + 1, 0);
    vector<int> size(n + 1, 0);
    vector<int> parent(n + 1, -1);
    ll current = 0;
    ll taken = 0;
    size[0] = 1;
    while (k > 0) {
        taken = taken + cand[current];
        int next = taken % n;
        k--;
        if (next == current) {
            taken += k * cand[current];
            break;
        }

        pref[current] = taken;
        size[next] = size[current] + 1;
        if (parent[next] != -1) {
            if (parent[next] == current) {
                taken += k * cand[current];
                break;
            }

            ll cycle = taken - pref[parent[next]];
            ll cycle_size = size[current] - size[parent[next]];
            taken += k / cycle_size * cycle;
            k %= cycle_size;
            current = next;
            while (k > 0) {
                taken = taken + cand[current];
                current = taken % n;
                k--;
            }
            break;
        } else {
            parent[next] = current;
            current = next;
        }

    }

    cout << taken << endl;
    return 0;
}