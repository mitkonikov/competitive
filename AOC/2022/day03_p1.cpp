#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set<char> front;
        for (int j = 0; j < s.size() / 2; j++) {
            front.insert(s[j]);
        }
        for (int j = s.size() / 2; j < s.size(); j++) {
            if (front.count(s[j])) {
                if (s[j] >= 'a' && s[j] <= 'z') {
                    ans += (s[j] - 'a') + 1;
                } else {
                    ans += (s[j] - 'A') + 27;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}