#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,pair<ll,ll> > reverseGCD(ll a, ll b) {
    // returns (g,(x,y))
    pair<ll,pair<ll,ll>> ret;
    if (a==0) {
        ret.first = b;
        ret.second.first = 0;
        ret.second.second = 1;
    } else {
        ll g, x, y;
        pair<ll,pair<ll,ll>> temp = reverseGCD(b%a, a);
        g = temp.first;
        x = temp.second.first;
        y = temp.second.second;
        ret.first = g;
        ret.second.first = y - (b/a)*x;
        ret.second.second = x;
    }
    return ret;
}

template<typename T>
T CRT(vector<T> n, vector<T> a) {
    // n divisor, a is the remainder

    T Wi = n[0], remainder = a[0];
    int k = n.size();

    for (int i = 1; i < k; ++i) {
        T wi = n[i];
        T bi = a[i];
        auto rGCD = reverseGCD(Wi,wi);
        T x = rGCD.second.first, y = rGCD.second.second;

        T c = bi - remainder;

        if (c % rGCD.first) // indicates that no result
            return LLONG_MAX;

        T W = wi / rGCD.first;
        remainder += Wi*(((c/rGCD.first*x)%W+W)%W);
        Wi *= W;
    }

    // represents the remainder of all zeros
    if (!remainder) {
        remainder = 1;
        for(int i=0;i<k;++i)
            remainder = remainder * n[i] / gcd(remainder, n[i]);
    }

    return remainder;
}

int main() {
    map<char, pair<int, int>> hm;
    hm['>'] = make_pair(0,1);
    hm['<'] = make_pair(0,-1);
    hm['^'] = make_pair(-1,0);
    hm['v'] = make_pair(1,0);

    int T;
    cin >> T;

    for (int _t = 0; _t < T; _t++) {
        int N;
        cin >> N;
        vector<string> mat(N);
        for (int j = 0; j < N; j++) cin >> mat[j];
        int P;
        cin >> P;
        vector<pair<int, int>> points(P);
        for (int i = 0; i < P; i++) {
            cin >> points[i].first >> points[i].second;
        }
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        int x = 0, y = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, 0));
        vector<vector<int>> offset(N, vector<int>(N, -1));
        int P2 = 0;
        vector<pair<int, int>> route1;
        while (!visited[x][y]) {
            route1.push_back({ x, y });
            visited[x][y] = true;
            offset[x][y] = P2++;
            int nx = x + hm[mat[x][y]].first;
            int ny = y + hm[mat[x][y]].second;
            x = nx;
            y = ny;
        }
        // brute force the first round
        bool done = false;
        for (int i = 0; i < P2; i++) {
            if (route1[i] == points[i%P]) {
                cout << i << endl;
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }
        // remove the cycle offset
        int remove_offset = offset[x][y];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (offset[i][j] == -1) continue;
                offset[i][j] -= remove_offset;
            }
        }
        // update P2
        P2 -= remove_offset;
        // System of congruence equations:
        //   x == k      (mod P)
        //   x == offset (mod P2)
        ll ans = LLONG_MAX;
        for (int i = 0; i < P; i++) {
            int off2 = offset[points[i].first][points[i].second];
            if (off2 < 0) continue;
            vector<ll> offsets = { (ll)(i-remove_offset+P)%P, (ll)off2 };
            vector<ll> periods = { (ll)P, (ll)P2 };
            ll x = CRT<ll>(periods, offsets);
            if (x != LLONG_MAX) {
                ans = min(ans, x + remove_offset);
            }
        }
        cout << (ans == LLONG_MAX ? "never" : to_string(ans)) << endl;
    }

    return 0;
}
