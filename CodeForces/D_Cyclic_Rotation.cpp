#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, int> mp;
    int A = n - 1, B = n - 1;
    while (A >= 0) {
        if (b[B] == b[B-1]) {
            mp[b[B]]++;
            B--;
            continue;
        }

        if (a[A] == b[B]) {
            A--;
            B--;
            continue;
        }

        if (mp[a[A]] == 0) {
            cout << "NO" << endl;
            return;
        }

        mp[a[A]]--;
        A--;
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}