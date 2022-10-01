#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "00" << endl;
        return 0;
    }
    string res = "";
    while (n > 0) {
        int t = n % 16;
        if (t >= 10) {
            res += ('A' + t - 10);
        } else {
            res += to_string(t);
        }
        n /= 16;
    }
    reverse(res.begin(), res.end());
    if (res.size() == 1) {
        cout << "0";
    }
    cout << res << endl;
    cout << flush;
    return 0;
}