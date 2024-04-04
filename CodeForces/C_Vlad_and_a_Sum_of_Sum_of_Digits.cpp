#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<ll> precomp;

void testCase() {
    int N;
    cin >> N;
    cout << precomp[N - 1] << endl;
}

int main() {
    ll sum = 0;
    for (int i = 1; i < 2e6 + 1000; i++) {
        int t = i;
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        precomp.push_back(sum);
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}