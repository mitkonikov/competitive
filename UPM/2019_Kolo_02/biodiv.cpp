#include <bits/stdc++.h>

using namespace std;

struct FenwickTree {
    vector<int> fwt;

    FenwickTree(int n) {
        fwt.resize(n, 0);
    }

    void addFWT(int ind, int val = 1) {
        for (ind++; ind < fwt.size(); ind+=ind&-ind)
            fwt[ind]+=val;
    }

    int getFWT(int ind) {
        int s = 0;
        for (ind++; ind > 0; ind-=ind&-ind)
            s += fwt[ind];
        return s;
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    string s;
    cin >> s;

    string t;
    cin >> t;

    vector<FenwickTree> fs(4, FenwickTree(N + 1000));
    vector<FenwickTree> ft(4, FenwickTree(M + 1000));
    
    map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    for (int i = 0; i < N; i++) {
        fs[mp[s[i]]].addFWT(i);
    }
    
    for (int i = 0; i < M; i++) {
        ft[mp[t[i]]].addFWT(i);
    }

    for (int i = 0; i < Q; i++) {
        int us, vs, ut, vt;
        cin >> us >> vs >> ut >> vt;
        us--; vs--; ut--; vt--;

        int count = 0;
        for (int tree = 0; tree < 4; tree++) {
            int s_count = fs[tree].getFWT(vs) - (us == 0 ? 0 : fs[tree].getFWT(us-1));
            int t_count = ft[tree].getFWT(vt) - (ut == 0 ? 0 : ft[tree].getFWT(ut-1));

            count += abs(s_count - t_count);
        }

        cout << count << endl;
    }
    
    return 0;
}