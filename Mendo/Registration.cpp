// Task: https://mendo.mk/Task.do?id=138

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string target;
    cin >> target;
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        s.insert(t);
    }
    for (int i = 0; i <= n + 1; i++) {
        string t = target + (i > 0 ? to_string(i) : "");
        if (s.count(t)) {
            continue;
        }
        cout << t << endl;
        return 0;
    }
    return 0;
}