#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<int> arrival(n), finish(n);
    for (int i = 0; i < n; i++) cin >> arrival[i];        
    for (int i = 0; i < n; i++) cin >> finish[i];

    int last_arrived = arrival[0];
    for (int i = 0; i < n; i++) {
        cout << finish[i] - last_arrived << " ";
        if (i+1<n) last_arrived = max(finish[i], arrival[i+1]);
    }

    cout << endl;
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