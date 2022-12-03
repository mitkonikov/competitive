#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i += 3) {
        map<char, int> frq;
        for (int k = 0; k < 3; k++) {
            string s;
            cin >> s;
            set<char> front;
            for (int j = 0; j < s.size(); j++) {
                front.insert(s[j]);
            }
            for (int el: front) {
                frq[el]++;
            }
        }
        
        for (auto p: frq) {
            if (p.second == 3) {
                if (p.first >= 'a' && p.first <= 'z') {
                    ans += (p.first - 'a') + 1;
                } else {
                    ans += (p.first - 'A') + 27;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}