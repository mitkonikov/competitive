#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            x = x + dx[count];
            y = y + dy[count];
        } else {
            count = (count + 1) % 4;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}