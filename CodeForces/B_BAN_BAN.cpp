#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

//  BANBANBAN
//  BNNBANBAA
//  BNNBNABAA

void testCase() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int front = 1;
    int back = 3 * n - 1;
    while (front < back) {
        v.push_back({ front, back });

        front += 3;
        back -= 3;
    }

    cout << v.size() << endl;
    for (auto el: v) {
        cout << el.first + 1 << " " << el.second + 1 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}