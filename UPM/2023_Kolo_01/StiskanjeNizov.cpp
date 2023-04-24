#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string& s, vector<int>& SA) {
    int N = s.size();
    vector<int> rank(N, 0);
    for (int i = 0; i < N; i++)
        rank[SA[i]] = i;

    int k = 0;
    vector<int> lcp(N-1, 0);
    for (int i = 0; i < N; i++) {
        if (rank[i] == N - 1) {
            k = 0;
            continue;
        }
        int j = SA[rank[i] + 1];
        while (i + k < N && j + k < N && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

inline void umin(int& a, int b) { if (b < a) a = b; }
inline void umax(int& a, int b) { if (b > a) a = b; }

void histogram_max(vector<int>& hist, function<void(int,int)> callback) {
    int N = hist.size();
    vector<int> st;
    int tp = 0;
    int i = 0;
    while (i < N) {
        callback(hist[i], 1);

        if (st.empty() || hist[st.back()] <= hist[i]) {
            st.push_back(i++);
        } else {
            tp = st.back();
            st.pop_back();
  
            int range = (st.empty() ? i : i - st.back() - 1);
            int h = hist[tp];
            callback(h, range);
        }
    }
  
    while (!st.empty()) {
        tp = st.back();
        st.pop_back();
        int range = (st.empty() ? i : i - st.back() - 1);
        int h = hist[tp];
        callback(h, range);
    }
}

int main() {
    string S;
    cin >> S;
    int N = S.size();

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    auto sa = suffix_array_construction(S);
    auto lcp = lcp_construction(S, sa);

    vector<int> ans(N + 1);

    histogram_max(lcp, [&](int height, int range) {
        umax(ans[height], range + 1);
    });

    ans[N] = 1;
    for (int i = N; i > 0; i--) {
        ans[i-1] = max(ans[i-1], ans[i]);
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << endl;
    
    return 0;
}