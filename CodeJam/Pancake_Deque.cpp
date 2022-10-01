#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    deque<int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }

    int count = 0;
    int last = 0;
    while (!d.empty()) {
        int MIN = min(d.front(), d.back());
        if (MIN >= last) {
            last = MIN;
            count++;
        }

        if (d.front() < d.back()) {
            d.pop_front();
        } else {
            d.pop_back();
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt + 1 << ": ";
        testCase();
    }

    cout << flush;
    return 0;
}