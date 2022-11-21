// Task: https://mendo.mk/Task.do?id=272

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    int i = 0;
    for (i = 1; i <= 40000; i++) {
        s += to_string(i);
        if (n - (int)s.size() <= 0) break;
        n -= s.size();
    }
    s += to_string(i);
    cout << s[n-1] << endl;
    return 0;
}