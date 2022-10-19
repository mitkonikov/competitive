#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> zeros(n, 0);
    vector<int> ones(n, 0);
    zeros[0] = (s[0] == '0');
    ones[0] = (s[0] == '1');
    for (int i = 1; i < n; i++) {
        zeros[i] = zeros[i-1] + (s[i] == '0');
        ones[i] = ones[i-1] + (s[i] == '1');
    }

    int count = 0;
    k--;
    for (int i = k; i < n; i++) {
        bool not_ok = (i-k-1 >= 0 && ones[i-k-1] > 0);
        not_ok |= (ones[n-1] - ones[i] > 0);
        if (zeros[i] == (i-k-1>=0 ? zeros[i-k-1] : 0) && !not_ok) count++;
    }

    cout << (count == 1 ? "Yes" : "No") << endl;
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