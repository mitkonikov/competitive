#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct dsu {
    vector<int> parent;

    dsu(int n) {
        parent.resize(n, -1);
    }

    int find_set(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = find_set(parent[a]);
    }

    int merge(int a, int b) {
        swap(a, b);
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        // if (-parent[x] < -parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return x;
    }

    bool are_same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return -parent[find_set(a)];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i+1];
    }
    a[0] = INT_MAX;
    a.back() = INT_MIN;
    vector<int> pointers;
    for (int i = 2; i <= n; i++) {
        if (a[i-1] < a[i]) {
            pointers.push_back(i);
        }
    }
    int days = 0;
    dsu dsu_front(n + 2), dsu_back(n + 2);
    vector<bool> dead(n + 2, false);
    while (true) {
        vector<int> new_pointers;
        for (int i = 0; i < pointers.size(); i++) {
            if (dead[pointers[i]]) continue;
            dead[pointers[i]] = true;
            int left = dsu_front.find_set(pointers[i]-1);
            dsu_front.merge(pointers[i], pointers[i]-1);
            int right = dsu_back.find_set(pointers[i]+1);
            dsu_back.merge(pointers[i], pointers[i]+1);
            if (a[left] < a[right]) {
                new_pointers.push_back(right);
            }
        }
        pointers = new_pointers;
        days++;
        if (new_pointers.empty()) break;
    }
    cout << days << endl;
    return 0;
}