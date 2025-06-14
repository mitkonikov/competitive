#include <bits/stdc++.h>
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
        int x = find_set(a), y = find_set(b);
        if (x == y) return x;
        if (-parent[x] < -parent[y]) swap(x, y);
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

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu DSU(26);
        for (int i = 0; i < s1.size(); i++) {
            DSU.merge(s1[i] - 'a', s2[i] - 'a');
        }
        vector<char> lowest(26);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (DSU.are_same(i, j)) {
                    lowest[i] = j;
                    break;
                }
            }
        }
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = lowest[baseStr[i] - 'a'] + 'a';
        }
        return baseStr;
    }
};