// Task: https://mendo.mk/Task.do?id=364

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int S, K, T;
    cin >> S >> K >> T;
    int ans = 0;
    string target = to_string(T);
    for (int i = S; i <= K; i++) {
        string cur = to_string(i);
        if (target.size() > cur.size()) continue;
        for (int k = 0; k + target.size() <= cur.size(); k++) {
            if (cur.substr(k, target.size()) == target) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}