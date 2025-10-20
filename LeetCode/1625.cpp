#include <bits/stdc++.h>
using namespace std;

int minRotation(string S, int off) {
    const int N = S.size();
    vector<int> visited(N);
    int ptr = 0;
    while (true) {
        if (visited[ptr]) break;
        visited[ptr] = true;
        ptr = (ptr + off) % N;
    }

    int a = 0;
    S += S;
    for (int b = 0; b < N; b++) {
        if (!visited[b]) continue;
        for (int k = 0; k < N; k++) {
            if (a + k == b || S[a + k] < S[b + k]) {
                b += max(0, k - 1);
                break;
            }
            if (S[a + k] > S[b + k]) {
                a = b;
                break;
            }
        }
    }
    return a;
}

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string best = s;            
        if (b % 2 == 1) {
            for (int sx = 0; sx < 10; sx++) {
                for (int sy = 0; sy < 10; sy++) {
                    string ns = s;
                    for (int k = 0; k < ns.size(); k++) {
                        ns[k] = (char)(((s[k] - '0') + a * (k & 1 ? sx : sy)) % 10 + '0');
                    }
                    int r = minRotation(ns, b);
                    rotate(ns.begin(), ns.begin() + r, ns.end());
                    if (ns < best) best = ns;
                }
            }
        } else {
            for (int sx = 0; sx < 10; sx++) {
                string ns = s;
                for (int k = 1; k < ns.size(); k += 2) {
                    ns[k] = (char)(((s[k] - '0') + a * sx) % 10 + '0');
                }
                int r = minRotation(ns, b);
                rotate(ns.begin(), ns.begin() + r, ns.end());
                if (ns < best) best = ns;
            }
        }
        return best;
    }
};