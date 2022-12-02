// Task: https://mendo.mk/Task.do?id=286

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [&](const string& a, const string& b) {
        return (a + b > b + a);
    });
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}