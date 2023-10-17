#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
struct segment {
    int X, Y, D;
};
 
inline void eraseOne(multiset<int>& ms, int value) {
    auto it = ms.find(value);
    if (it != ms.end()) ms.erase(it);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int Q, H, W;
    cin >> Q >> H >> W;
    vector<map<int, int>> mp(W + 10); 
    vector<segment> segments(Q);
    multiset<int> ms;
    for (int i = 0; i < W; i++) {
        mp[i][H] = 1;
        ms.insert(H);
    }
    int counter = 0;
    for (int i = 0; i < Q; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            int X, Y, D;
            cin >> D >> X >> Y;
            for (int j = X; j < X + Y; j++) {
                int old = mp[j].begin()->first;
                mp[j][D]++;
 
                auto new_value = mp[j].begin()->first;
                if (old != new_value) {
                    eraseOne(ms, old);
                    ms.insert(new_value);
                }
            }
            segments[counter++] = { X, Y, D };
        } else {
            int id;
            cin >> id;
            id--;
            auto s = segments[id];
            for (int j = s.X; j < s.X + s.Y; j++) {
                int old = mp[j].begin()->first;
                mp[j][s.D]--;
                if (mp[j][s.D] == 0) mp[j].erase(s.D);
 
                auto new_value = mp[j].begin()->first;
                
                if (old != new_value) {
                    eraseOne(ms, old);
                    ms.insert(new_value);
                }
            }
        }
 
        cout << *prev(ms.end()) << endl;
    }
    return 0;
}